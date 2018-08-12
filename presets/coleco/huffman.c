
// Huffman tree generated by ColecoVision huffman_analyzer.
// Nodes below HUFFMAN_LS are inner nodes.
// Nodes from HUFFMAN_LS to HUFFMAN_BS - 1 only have a right child node.
// Nodes from HUFFMAN_BS to HUFFMAN_RS - 1 do not have child nodes.
// Nodes from HUFFMAN_RS onward only have a left child node.

#include <cvu_compression.h>
#include <cvu.h>

#define RLE_ESCAPE (const uint8_t)(253)

#define PATTERN ((const cv_vmemp)0x0000)
#define COLOR ((const cv_vmemp)0x2000)
#define IMAGE ((const cv_vmemp)0x1c00)
#define SPRITES ((const cv_vmemp)0x3c00)

extern const unsigned char color[];
extern const unsigned char pattern[];

extern const uint8_t HUFFMAN_ROOT;
extern const uint8_t HUFFMAN_LS, HUFFMAN_BS, HUFFMAN_RS;
extern const struct cvu_huffman_node huffman_tree[255];

void main(void)
{
	unsigned int i;
	struct cvu_compression_state state;

	cv_set_screen_active(false);	
	cv_set_image_table(IMAGE);
	cv_set_color_table(0x3fff);
	cv_set_character_pattern_t(0x1fff);
	cv_set_screen_mode(CV_SCREENMODE_BITMAP);

	// Make all sprites transparent.
	cv_set_sprite_attribute_table(SPRITES);
	for(i = 0; i < 32; i++)
	{
		struct cvu_sprite s;
		cvu_set_sprite_color(&s, CV_COLOR_TRANSPARENT);
		cvu_set_sprite(SPRITES, i, &s);
	}

	// Decompress image data to video memory.
	cvu_init_compression(pattern, &state, huffman_tree, HUFFMAN_ROOT, HUFFMAN_LS, HUFFMAN_BS, HUFFMAN_RS, RLE_ESCAPE);
	cvu_memtovmemcpy_compression(PATTERN,& state, 6144);
	cvu_init_compression(color, &state, huffman_tree, HUFFMAN_ROOT, HUFFMAN_LS, HUFFMAN_BS, HUFFMAN_RS, RLE_ESCAPE);
	cvu_memtovmemcpy_compression(COLOR, &state, 6144);

	for(i = 0; i < 768; i++)
		cvu_voutb(i % 256, IMAGE + i);

	cv_set_screen_active(true);

	for(;;);
}

const uint8_t HUFFMAN_ROOT = 108;
const uint8_t HUFFMAN_LS = 109, HUFFMAN_BS = 124, HUFFMAN_RS = 234;
const struct cvu_huffman_node huffman_tree[255] = {

/* Node 0 */ {125, 126},
/* Node 1 */ {127, 128},
/* Node 2 */ {129, 130},
/* Node 3 */ {131, 132},
/* Node 4 */ {133, 134},
/* Node 5 */ {135, 136},
/* Node 6 */ {137, 138},
/* Node 7 */ {139, 140},
/* Node 8 */ {141, 142},
/* Node 9 */ {143, 144},
/* Node 10 */ {145, 146},
/* Node 11 */ {147, 148},
/* Node 12 */ {149, 150},
/* Node 13 */ {151, 152},
/* Node 14 */ {153, 154},
/* Node 15 */ {155, 156},
/* Node 16 */ {157, 158},
/* Node 17 */ {159, 160},
/* Node 18 */ {161, 162},
/* Node 19 */ {163, 164},
/* Node 20 */ {165, 166},
/* Node 21 */ {167, 168},
/* Node 22 */ {169, 170},
/* Node 23 */ {171, 172},
/* Node 24 */ {173, 174},
/* Node 25 */ {175, 176},
/* Node 26 */ {177, 178},
/* Node 27 */ {179, 180},
/* Node 28 */ {181, 182},
/* Node 29 */ {183, 184},
/* Node 30 */ {109, 0},
/* Node 31 */ {1, 2},
/* Node 32 */ {3, 4},
/* Node 33 */ {5, 6},
/* Node 34 */ {7, 8},
/* Node 35 */ {9, 10},
/* Node 36 */ {11, 12},
/* Node 37 */ {13, 14},
/* Node 38 */ {15, 16},
/* Node 39 */ {17, 18},
/* Node 40 */ {19, 20},
/* Node 41 */ {21, 22},
/* Node 42 */ {23, 24},
/* Node 43 */ {25, 26},
/* Node 44 */ {27, 28},
/* Node 45 */ {29, 30},
/* Node 46 */ {31, 32},
/* Node 47 */ {33, 34},
/* Node 48 */ {35, 36},
/* Node 49 */ {37, 38},
/* Node 50 */ {39, 40},
/* Node 51 */ {41, 42},
/* Node 52 */ {43, 44},
/* Node 53 */ {45, 46},
/* Node 54 */ {47, 48},
/* Node 55 */ {49, 50},
/* Node 56 */ {51, 52},
/* Node 57 */ {53, 54},
/* Node 58 */ {55, 56},
/* Node 59 */ {57, 58},
/* Node 60 */ {185, 186},
/* Node 61 */ {187, 188},
/* Node 62 */ {189, 190},
/* Node 63 */ {191, 192},
/* Node 64 */ {193, 194},
/* Node 65 */ {195, 196},
/* Node 66 */ {197, 198},
/* Node 67 */ {199, 200},
/* Node 68 */ {201, 202},
/* Node 69 */ {203, 204},
/* Node 70 */ {205, 206},
/* Node 71 */ {207, 208},
/* Node 72 */ {209, 210},
/* Node 73 */ {60, 61},
/* Node 74 */ {62, 63},
/* Node 75 */ {64, 65},
/* Node 76 */ {66, 67},
/* Node 77 */ {212, 213},
/* Node 78 */ {214, 215},
/* Node 79 */ {216, 217},
/* Node 80 */ {218, 219},
/* Node 81 */ {220, 221},
/* Node 82 */ {68, 69},
/* Node 83 */ {70, 71},
/* Node 84 */ {72, 73},
/* Node 85 */ {74, 75},
/* Node 86 */ {223, 224},
/* Node 87 */ {226, 110},
/* Node 88 */ {77, 78},
/* Node 89 */ {81, 82},
/* Node 90 */ {83, 84},
/* Node 91 */ {87, 88},
/* Node 92 */ {239, 230},
/* Node 93 */ {89, 90},
/* Node 94 */ {244, 117},
/* Node 95 */ {91, 231},
/* Node 96 */ {118, 93},
/* Node 97 */ {119, 232},
/* Node 98 */ {248, 233},
/* Node 99 */ {249, 250},
/* Node 100 */ {95, 120},
/* Node 101 */ {121, 251},
/* Node 102 */ {122, 97},
/* Node 103 */ {98, 99},
/* Node 104 */ {252, 100},
/* Node 105 */ {123, 102},
/* Node 106 */ {104, 253},
/* Node 107 */ {105, 254},
/* Node 108 */ {106, 107},
/* Node 109 */ {250, 124},
/* Node 110 */ {247, 211},
/* Node 111 */ {243, 222},
/* Node 112 */ {60, 225},
/* Node 113 */ {249, 237},
/* Node 114 */ {8, 80},
/* Node 115 */ {241, 228},
/* Node 116 */ {227, 111},
/* Node 117 */ {135, 112},
/* Node 118 */ {240, 114},
/* Node 119 */ {254, 242},
/* Node 120 */ {4, 92},
/* Node 121 */ {31, 245},
/* Node 122 */ {127, 247},
/* Node 123 */ {3, 96},
/* Node 124 */ {10, 32},
/* Node 125 */ {33, 36},
/* Node 126 */ {37, 38},
/* Node 127 */ {41, 42},
/* Node 128 */ {43, 44},
/* Node 129 */ {50, 52},
/* Node 130 */ {54, 58},
/* Node 131 */ {64, 67},
/* Node 132 */ {68, 69},
/* Node 133 */ {70, 71},
/* Node 134 */ {72, 73},
/* Node 135 */ {74, 75},
/* Node 136 */ {76, 77},
/* Node 137 */ {78, 80},
/* Node 138 */ {81, 82},
/* Node 139 */ {83, 84},
/* Node 140 */ {85, 86},
/* Node 141 */ {87, 88},
/* Node 142 */ {90, 91},
/* Node 143 */ {92, 93},
/* Node 144 */ {94, 95},
/* Node 145 */ {96, 97},
/* Node 146 */ {98, 100},
/* Node 147 */ {101, 102},
/* Node 148 */ {104, 105},
/* Node 149 */ {106, 107},
/* Node 150 */ {108, 109},
/* Node 151 */ {110, 114},
/* Node 152 */ {117, 122},
/* Node 153 */ {125, 130},
/* Node 154 */ {137, 141},
/* Node 155 */ {144, 146},
/* Node 156 */ {147, 148},
/* Node 157 */ {149, 150},
/* Node 158 */ {151, 154},
/* Node 159 */ {160, 161},
/* Node 160 */ {162, 163},
/* Node 161 */ {164, 165},
/* Node 162 */ {166, 167},
/* Node 163 */ {168, 169},
/* Node 164 */ {170, 171},
/* Node 165 */ {172, 173},
/* Node 166 */ {174, 175},
/* Node 167 */ {176, 177},
/* Node 168 */ {178, 179},
/* Node 169 */ {180, 181},
/* Node 170 */ {182, 183},
/* Node 171 */ {184, 186},
/* Node 172 */ {187, 188},
/* Node 173 */ {194, 200},
/* Node 174 */ {201, 202},
/* Node 175 */ {209, 210},
/* Node 176 */ {211, 212},
/* Node 177 */ {213, 214},
/* Node 178 */ {215, 216},
/* Node 179 */ {217, 218},
/* Node 180 */ {219, 221},
/* Node 181 */ {228, 229},
/* Node 182 */ {233, 234},
/* Node 183 */ {235, 237},
/* Node 184 */ {244, 245},
/* Node 185 */ {13, 35},
/* Node 186 */ {39, 40},
/* Node 187 */ {45, 46},
/* Node 188 */ {48, 49},
/* Node 189 */ {53, 66},
/* Node 190 */ {79, 89},
/* Node 191 */ {103, 111},
/* Node 192 */ {116, 133},
/* Node 193 */ {134, 138},
/* Node 194 */ {139, 145},
/* Node 195 */ {153, 155},
/* Node 196 */ {158, 185},
/* Node 197 */ {189, 190},
/* Node 198 */ {191, 196},
/* Node 199 */ {198, 205},
/* Node 200 */ {208, 236},
/* Node 201 */ {11, 14},
/* Node 202 */ {17, 19},
/* Node 203 */ {20, 34},
/* Node 204 */ {59, 61},
/* Node 205 */ {65, 99},
/* Node 206 */ {112, 113},
/* Node 207 */ {120, 140},
/* Node 208 */ {157, 203},
/* Node 209 */ {204, 220},
/* Node 210 */ {226, 238},
/* Node 211 */ {26, 47},
/* Node 212 */ {56, 119},
/* Node 213 */ {123, 129},
/* Node 214 */ {132, 136},
/* Node 215 */ {152, 197},
/* Node 216 */ {223, 232},
/* Node 217 */ {246, 251},
/* Node 218 */ {22, 25},
/* Node 219 */ {27, 51},
/* Node 220 */ {55, 118},
/* Node 221 */ {222, 242},
/* Node 222 */ {12, 21},
/* Node 223 */ {29, 57},
/* Node 224 */ {156, 239},
/* Node 225 */ {16, 23},
/* Node 226 */ {28, 131},
/* Node 227 */ {124, 206},
/* Node 228 */ {121, 142},
/* Node 229 */ {230, 30},
/* Node 230 */ {115, 126},
/* Node 231 */ {6, 195},
/* Node 232 */ {224, 252},
/* Node 233 */ {15, 143},
/* Node 234 */ {59, 2},
/* Node 235 */ {234, 9},
/* Node 236 */ {235, 18},
/* Node 237 */ {236, 193},
/* Node 238 */ {76, 24},
/* Node 239 */ {79, 62},
/* Node 240 */ {227, 1},
/* Node 241 */ {85, 225},
/* Node 242 */ {238, 231},
/* Node 243 */ {229, 207},
/* Node 244 */ {86, 159},
/* Node 245 */ {240, 0},
/* Node 246 */ {113, 199},
/* Node 247 */ {241, 128},
/* Node 248 */ {115, 192},
/* Node 249 */ {243, 248},
/* Node 250 */ {116, 5},
/* Node 251 */ {246, 63},
/* Node 252 */ {94, 7},
/* Node 253 */ {101, 255},
/* Node 254 */ {103, 253}};
// Huffman-encoded data encoded by ColecoVision huffman encoder.

const uint8_t color[] = { 151, 179, 58, 64, 86, 231, 40, 158, 15, 165, 207, 91, 28, 149, 102, 253, 148, 210, 39, 226, 112, 89, 127, 32, 14, 159, 205, 57, 138, 71, 54, 223, 183, 159, 229, 240, 109, 219, 207, 177, 245, 251, 246, 71, 154, 83, 219, 79, 165, 121, 203, 91, 143, 105, 224, 159, 239, 52, 111, 89, 235, 101, 120, 248, 203, 173, 173, 173, 223, 211, 158, 145, 190, 34, 237, 131, 216, 169, 180, 87, 16, 75, 247, 149, 216, 229, 116, 233, 46, 19, 16, 16, 124, 7, 56, 83, 190, 2, 224, 177, 120, 10, 224, 138, 69, 241, 117, 241, 178, 184, 44, 46, 139, 203, 226, 178, 0};

const uint8_t pattern[] = { 151, 125, 0, 247, 9, 253, 221, 40, 77, 190, 155, 3, 40, 190, 221, 227, 184, 126, 247, 163, 188, 2, 78, 146, 254, 187, 101, 25, 191, 187, 239, 79, 89, 150, 241, 148, 7, 201, 23, 173, 210, 207, 222, 221, 88, 159, 114, 209, 118, 211, 244, 253, 186, 206, 66, 104, 253, 40, 125, 115, 202, 226, 49, 205, 243, 114, 121, 244, 122, 180, 126, 106, 125, 170, 28, 157, 28, 93, 142, 110, 142, 158, 62, 25, 155, 230, 148, 31, 19, 66, 16, 33, 125, 116, 51, 207, 15, 80, 235, 146, 12, 190, 91, 250, 201, 113, 52, 140, 86, 191, 27, 63, 25, 143, 94, 143, 206, 242, 104, 60, 156, 207, 234, 177, 115, 119, 166, 203, 195, 79, 173, 79, 149, 103, 233, 70, 178, 163, 161, 105, 122, 136, 9, 162, 55, 103, 213, 167, 214, 179, 194, 231, 75, 72, 140, 208, 36, 132, 214, 178, 152, 85, 154, 222, 208, 210, 53, 169, 62, 104, 8, 138, 179, 234, 192, 238, 215, 164, 90, 221, 208, 180, 52, 167, 245, 123, 111, 151, 114, 166, 149, 171, 213, 46, 73, 214, 181, 105, 250, 94, 49, 52, 196, 43, 229, 148, 165, 199, 106, 223, 63, 20, 107, 223, 200, 107, 99, 23, 148, 97, 103, 250, 97, 60, 66, 253, 154, 84, 171, 27, 154, 150, 230, 180, 126, 239, 87, 151, 114, 166, 183, 41, 25, 120, 54, 133, 114, 247, 61, 57, 156, 199, 239, 245, 216, 149, 239, 186, 120, 237, 251, 230, 204, 165, 104, 45, 38, 186, 251, 238, 102, 149, 37, 37, 103, 80, 232, 226, 135, 152, 166, 89, 237, 206, 170, 27, 26, 154, 78, 173, 201, 248, 144, 224, 243, 75, 153, 100, 173, 133, 152, 176, 150, 62, 172, 216, 82, 39, 8, 34, 164, 105, 229, 46, 57, 115, 175, 24, 4, 77, 111, 170, 213, 193, 122, 170, 95, 19, 233, 153, 46, 197, 126, 244, 77, 243, 112, 250, 124, 33, 62, 38, 241, 148, 79, 85, 149, 107, 91, 161, 120, 172, 173, 245, 250, 112, 225, 202, 90, 139, 7, 168, 249, 167, 32, 148, 105, 122, 83, 173, 14, 86, 137, 239, 253, 154, 72, 207, 116, 41, 94, 143, 147, 244, 152, 212, 71, 139, 43, 233, 110, 252, 94, 219, 229, 187, 126, 202, 253, 209, 248, 201, 235, 209, 250, 232, 241, 232, 233, 232, 228, 104, 125, 116, 127, 244, 244, 201, 120, 120, 131, 159, 92, 31, 157, 246, 232, 250, 232, 230, 104, 249, 232, 114, 52, 30, 189, 30, 45, 61, 186, 62, 90, 124, 242, 216, 185, 27, 207, 234, 135, 92, 30, 250, 41, 139, 7, 88, 233, 92, 115, 5, 50, 17, 81, 123, 124, 180, 13, 12, 188, 36, 253, 88, 158, 57, 85, 137, 225, 225, 51, 19, 145, 44, 5, 24, 88, 50, 83, 166, 71, 11, 30, 197, 100, 36, 219, 11, 103, 206, 150, 71, 50, 195, 153, 225, 0, 115, 35, 119, 102, 178, 121, 100, 202, 116, 230, 10, 182, 73, 230, 120, 102, 173, 249, 252, 51, 67, 233, 51, 242, 155, 135, 103, 30, 143, 212, 119, 205, 133, 193, 206, 44, 42, 186, 176, 112, 102, 40, 125, 70, 254, 153, 135, 121, 60, 82, 103, 134, 203, 62, 183, 202, 182, 219, 246, 252, 88, 158, 185, 146, 233, 179, 19, 32, 104, 107, 46, 12, 118, 102, 130, 133, 5, 78, 103, 206, 177, 194, 128, 128, 167, 220, 52, 103, 30, 206, 192, 227, 157, 153, 196, 3, 118, 56, 215, 245, 216, 185, 27, 107, 173, 203, 195, 69, 159, 185, 121, 248, 12, 72, 126, 184, 221, 94, 200, 43, 255, 15, 47, 151, 45, 37, 191, 121, 248, 108, 184, 126, 204, 143, 146, 145, 211, 195, 15, 82, 68, 68, 15, 231, 53, 24, 40, 56, 63, 76, 156, 248, 12, 130, 15, 147, 109, 113, 75, 22, 242, 126, 184, 133, 45, 210, 165, 60, 156, 173, 210, 214, 202, 84, 254, 225, 71, 35, 185, 124, 248, 193, 207, 48, 61, 60, 52, 196, 227, 145, 121, 248, 12, 54, 61, 76, 53, 77, 198, 233, 225, 7, 63, 195, 244, 240, 208, 16, 143, 7, 61, 156, 123, 238, 106, 27, 248, 225, 179, 37, 233, 135, 9, 7, 67, 128, 74, 124, 248, 1, 227, 226, 195, 153, 51, 47, 44, 108, 123, 248, 49, 68, 66, 126, 248, 209, 72, 86, 232, 225, 40, 37, 59, 232, 225, 7, 140, 28, 153, 163, 203, 179, 240, 89, 61, 118, 238, 206, 116, 121, 62, 29, 95, 122, 252, 94, 143, 93, 249, 174, 203, 51, 187, 27, 191, 215, 118, 249, 174, 159, 120, 236, 220, 141, 103, 245, 67, 46, 15, 253, 196, 117, 61, 118, 238, 198, 90, 235, 242, 112, 209, 79, 124, 86, 143, 157, 187, 51, 93, 190, 229, 241, 123, 61, 118, 229, 187, 46, 207, 236, 110, 252, 94, 219, 229, 187, 126, 226, 177, 115, 55, 158, 213, 15, 185, 60, 244, 19, 215, 245, 216, 185, 27, 107, 173, 203, 195, 69, 63, 241, 89, 61, 118, 238, 206, 116, 249, 150, 199, 239, 245, 216, 149, 239, 186, 156, 147, 123, 197, 214, 153, 99, 109, 190, 27, 124, 136, 87, 204, 224, 12, 62, 63, 110, 142, 198, 135, 122, 18, 110, 183, 85, 117, 249, 152, 159, 178, 120, 128, 118, 211, 63, 172, 76, 192, 45, 229, 225, 181, 225, 115, 23, 31, 206, 95, 126, 23, 181, 126, 120, 173, 8, 113, 33, 30, 230, 11, 49, 207, 15, 111, 171, 20, 52, 207, 15, 235, 121, 169, 182, 31, 166, 42, 254, 160, 31, 22, 149, 27, 6, 90, 31, 38, 4, 148, 232, 251, 135, 27, 133, 98, 40, 231, 135, 211, 109, 182, 56, 115, 126, 56, 121, 44, 231, 135, 243, 92, 4, 57, 112, 120, 248, 76, 44, 62, 220, 13, 131, 90, 63, 220, 23, 13, 206, 15, 183, 194, 79, 66, 60, 92, 132, 152, 231, 103, 225, 68, 93, 206, 243, 153, 138, 144, 170, 62, 188, 110, 218, 203, 249, 97, 13, 46, 85, 245, 97, 138, 60, 173, 170, 15, 139, 60, 200, 111, 54, 15, 79, 155, 205, 96, 240, 112, 63, 216, 106, 171, 15, 139, 101, 123, 107, 48, 47, 85, 181, 189, 25, 244, 167, 220, 60, 250, 60, 129, 128, 184, 92, 159, 42, 92, 130, 239, 139, 92, 174, 196, 81, 115, 159, 18, 199, 121, 58, 53, 67, 132, 223, 55, 170, 58, 31, 85, 232, 251, 218, 247, 77, 47, 63, 92, 248, 176, 92, 114, 105, 188, 197, 203, 57, 17, 33, 85, 126, 40, 6, 227, 152, 52, 32, 56, 67, 22, 211, 244, 88, 14, 127, 95, 124, 136, 83, 90, 12, 127, 159, 65, 161, 159, 18, 79, 205, 79, 249, 187, 152, 231, 163, 10, 225, 92, 63, 102, 85, 221, 168, 248, 48, 81, 123, 121, 84, 161, 227, 134, 62, 14, 170, 223, 213, 246, 230, 212, 96, 107, 163, 62, 101, 233, 39, 43, 31, 189, 30, 189, 237, 104, 234, 232, 248, 238, 198, 100, 191, 207, 82, 235, 163, 229, 79, 38, 60, 122, 235, 104, 60, 154, 220, 209, 220, 163, 227, 232, 238, 232, 254, 104, 234, 232, 248, 228, 228, 232, 28, 142, 94, 143, 214, 71, 75, 143, 174, 143, 30, 143, 150, 56, 90, 28, 13};
