
`define OP_LOAD_A	4'h0
`define OP_LOAD_B	4'h1
`define OP_ADD		4'h2
`define OP_SUB		4'h3
`define OP_INC		4'h4
`define OP_DEC		4'h5
`define OP_ASL		4'h6
`define OP_LSR		4'h7
`define OP_OR		4'h8
`define OP_AND		4'h9
`define OP_XOR		4'ha

module ALU(A, B, Y, aluop);
  
  input [7:0] A;
  input [7:0] B;
  output [8:0] Y;
  input [3:0] aluop;
  
  always @(*)
    case (aluop)
      `OP_LOAD_A:	Y = {1'b0, A};
      `OP_LOAD_B:	Y = {1'b0, B};
      `OP_ADD:		Y = A + B;
      `OP_SUB:		Y = A - B;
      `OP_INC:		Y = A + 1;
      `OP_DEC:		Y = A - 1;
      `OP_ASL:		Y = {A[7], A + A};
      `OP_LSR:		Y = {A[0], A >> 1};
      `OP_OR:		Y = {1'b0, A | B};
      `OP_AND:		Y = {1'b0, A & B};
      `OP_XOR:		Y = {1'b0, A ^ B};
      default:		Y = 9'bx;
    endcase
  
endmodule

`define REG_A 1'b0
`define REG_B 1'b1
`define I_CONST(r,x) { 2'b00, r, x }
`define I_LOAD_ADDR(r,addr) { 3'b010, r, addr }
`define I_STORE_ADDR(r,addr) { 3'b011, r, addr }
`define I_COMPUTE(r,op) { 3'b100, r, op }
`define I_RESET 8'hff

module CPU(clk, reset, address, data_in, data_out, write);

  input  clk, reset;
  output [7:0] address;
  input  [7:0] data_in;
  output [7:0] data_out;
  output write;
  
  reg [7:0] ip;
  reg [7:0] opcode;
  reg [3:0] aluop;
  reg [7:0] A, B;
  reg [8:0] Y;
  reg [1:0] state;
  reg [2:0] action;
  
  reg carry;
  reg zero;
  
  localparam NOOP = 0;
  localparam MAKE_CONST = 1;
  localparam LOAD_ADDR = 2;
  localparam STORE_ADDR = 3;
  localparam COMPUTE = 4;
  
  wire load_const = opcode[3:1] == 3'b111;
  
  ALU alu(.A(A), .B(B), .Y(Y), .aluop(aluop));
  
  always @(posedge clk)
    if (reset) begin
      state <= 0;
      write <= 0;
    end else begin
      case (state)
        // state 0: reset
        0: begin
          ip <= 8'h80;
          write <= 0;
          state <= 1;
        end
	// state 1: select opcode address
        1: begin
          address <= ip;
          ip <= ip + 1;
          write <= 0;
          state <= 2;
        end
        // state 2: read/decode opcode
        2: begin
          casez (data_in)
            8'b00??????: begin
              action <= MAKE_CONST;
              if (data_in[5])
                B <= {3'b0, data_in[4:0]};
              else
                A <= {3'b0, data_in[4:0]};
              state <= 1;
            end
            8'b010?????: begin
              action <= LOAD_ADDR;
              address <= {4'b0, data_in[3:0]};
              state <= 3;
            end
            8'b011?????: begin
              action <= STORE_ADDR;
              address <= {4'b0, data_in[3:0]};
              state <= 3;
            end
            8'b100?????: begin
              action <= COMPUTE;
              aluop <= data_in[3:0];
              state <= 3;
            end
            default: begin
              action <= NOOP;
              state <= 0; // reset
            end
          endcase
          opcode <= data_in;
        end
        // state 3: perform action
        3: begin
          if (action == LOAD_ADDR) begin
            if (opcode[4])
              B <= data_in;
            else
              A <= data_in;
          end else if (action == STORE_ADDR) begin
            if (opcode[4])
              data_out <= B;
            else
              data_out <= A;
            write <= 1;
          end else if (action == COMPUTE) begin
            if (opcode[4])
              B <= Y[7:0];
            else
              A <= Y[7:0];
            carry <= Y[8];
            zero <= ~|Y;
          end
          state <= 1; // repeat loop at state 1
        end
      endcase
    end

endmodule

module test_CPU_top(clk, reset, address_bus, to_cpu, from_cpu, write_enable);

  input clk, reset;
  output [7:0] address_bus;
  output reg [7:0] to_cpu;
  output [7:0] from_cpu;
  output write_enable;

  reg [7:0] ram[128];
  reg [7:0] rom[128];
  
  CPU cpu(.clk(clk),
          .reset(reset),
          .address(address_bus),
          .data_in(to_cpu),
          .data_out(from_cpu),
          .write(write_enable));

  // does not work as (posedge clk)
  always @(*)
    if (write_enable)
      ram[address_bus[6:0]] = from_cpu;
    else if (address_bus[7] == 0)
      to_cpu = ram[address_bus[6:0]];
    else
      to_cpu = rom[address_bus[6:0]];
  
  initial begin
    // address 0x80
    rom['h00] = `I_CONST(`REG_A, 5'h1f);
    rom['h01] = `I_COMPUTE(`REG_A, `OP_ASL);
    rom['h02] = `I_COMPUTE(`REG_A, `OP_ASL);
    rom['h03] = `I_COMPUTE(`REG_A, `OP_ASL);
    rom['h04] = `I_COMPUTE(`REG_A, `OP_ASL);
    rom['h05] = `I_COMPUTE(`REG_B, `OP_LOAD_A);
    rom['h06] = `I_STORE_ADDR(`REG_B, 4'd1);
    rom['h07] = `I_LOAD_ADDR(`REG_B, 4'd1);
    rom['h08] = `I_RESET;
  end

endmodule