#ifndef _DPHIL_TMAP_H_
#define _DPHIL_TMAP_H_

#define TMAP_NAME "DPHIL"

const uint16_t localPlaces = 1000;
const uint8_t outPlaces = 3;
const uint16_t transitions = 600; // (12 aligned to 4) x 50 steps

#if (MAX_TRANS_CONNECTS<4)
#error "not enough connectivity in Transition"
#endif

const Transition tmap[transitions] = {
	// {0xoi, inp-s, outp-s}
	{0x22, 4, 1, 1001 /* out */ , 1000 /* out */ }, // 0:0: ccw_take_left_fork *choice
	{0x22, 4, 12, 9, 5}, // 0:1: take_right_fork *choice
	{0x21, 0, 1, 4}, // 0:2: ccw_put_left_fork
	{0x21, 10, 11, 3}, // 0:3: put_left_fork

	{0x31, 7, 10, 2, 8}, // 0:4: start_thinking
	{0x13, 9, 6, 8, 7}, // 0:5: start_eating
	{0x21, 2, 4, 12}, // 0:6: put_right_fork
	{0x31, 13, 20 /* next */ , 18, 14}, // 0:7: cw_start_thinking

	{0x13, 11, 3, 5, 6}, // 0:8: take_left_fork *choice
	{0x13, 11, 16, 17, 19}, // 0:9: cw_take_right_fork *choice
	{0x21, 18, 16, 11}, // 0:10: cw_put_right_fork
	{0x13, 14, 19, 15, 13}, // 0:11: cw_start_eating

	{0x22, 24, 21, 15 /* prev */ , 17 /* prev */ }, // 1:0: ccw_take_left_fork *choice
	{0x22, 24, 32, 29, 25}, // 1:1: take_right_fork *choice
	{0x21, 20, 21, 24}, // 1:2: ccw_put_left_fork
	{0x21, 30, 31, 23}, // 1:3: put_left_fork

	{0x31, 27, 30, 22, 28}, // 1:4: start_thinking
	{0x13, 29, 26, 28, 27}, // 1:5: start_eating
	{0x21, 22, 24, 32}, // 1:6: put_right_fork
	{0x31, 33, 40 /* next */ , 38, 34}, // 1:7: cw_start_thinking

	{0x13, 31, 23, 25, 26}, // 1:8: take_left_fork *choice
	{0x13, 31, 36, 37, 39}, // 1:9: cw_take_right_fork *choice
	{0x21, 38, 36, 31}, // 1:10: cw_put_right_fork
	{0x13, 34, 39, 35, 33}, // 1:11: cw_start_eating

	{0x22, 44, 41, 35 /* prev */ , 37 /* prev */ }, // 2:0: ccw_take_left_fork *choice
	{0x22, 44, 52, 49, 45}, // 2:1: take_right_fork *choice
	{0x21, 40, 41, 44}, // 2:2: ccw_put_left_fork
	{0x21, 50, 51, 43}, // 2:3: put_left_fork

	{0x31, 47, 50, 42, 48}, // 2:4: start_thinking
	{0x13, 49, 46, 48, 47}, // 2:5: start_eating
	{0x21, 42, 44, 52}, // 2:6: put_right_fork
	{0x31, 53, 60 /* next */ , 58, 54}, // 2:7: cw_start_thinking

	{0x13, 51, 43, 45, 46}, // 2:8: take_left_fork *choice
	{0x13, 51, 56, 57, 59}, // 2:9: cw_take_right_fork *choice
	{0x21, 58, 56, 51}, // 2:10: cw_put_right_fork
	{0x13, 54, 59, 55, 53}, // 2:11: cw_start_eating

	{0x22, 64, 61, 55 /* prev */ , 57 /* prev */ }, // 3:0: ccw_take_left_fork *choice
	{0x22, 64, 72, 69, 65}, // 3:1: take_right_fork *choice
	{0x21, 60, 61, 64}, // 3:2: ccw_put_left_fork
	{0x21, 70, 71, 63}, // 3:3: put_left_fork

	{0x31, 67, 70, 62, 68}, // 3:4: start_thinking
	{0x13, 69, 66, 68, 67}, // 3:5: start_eating
	{0x21, 62, 64, 72}, // 3:6: put_right_fork
	{0x31, 73, 80 /* next */ , 78, 74}, // 3:7: cw_start_thinking

	{0x13, 71, 63, 65, 66}, // 3:8: take_left_fork *choice
	{0x13, 71, 76, 77, 79}, // 3:9: cw_take_right_fork *choice
	{0x21, 78, 76, 71}, // 3:10: cw_put_right_fork
	{0x13, 74, 79, 75, 73}, // 3:11: cw_start_eating

	{0x22, 84, 81, 75 /* prev */ , 77 /* prev */ }, // 4:0: ccw_take_left_fork *choice
	{0x22, 84, 92, 89, 85}, // 4:1: take_right_fork *choice
	{0x21, 80, 81, 84}, // 4:2: ccw_put_left_fork
	{0x21, 90, 91, 83}, // 4:3: put_left_fork

	{0x31, 87, 90, 82, 88}, // 4:4: start_thinking
	{0x13, 89, 86, 88, 87}, // 4:5: start_eating
	{0x21, 82, 84, 92}, // 4:6: put_right_fork
	{0x31, 93, 100 /* next */ , 98, 94}, // 4:7: cw_start_thinking

	{0x13, 91, 83, 85, 86}, // 4:8: take_left_fork *choice
	{0x13, 91, 96, 97, 99}, // 4:9: cw_take_right_fork *choice
	{0x21, 98, 96, 91}, // 4:10: cw_put_right_fork
	{0x13, 94, 99, 95, 93}, // 4:11: cw_start_eating

	{0x22, 104, 101, 95 /* prev */ , 97 /* prev */ }, // 5:0: ccw_take_left_fork *choice
	{0x22, 104, 112, 109, 105}, // 5:1: take_right_fork *choice
	{0x21, 100, 101, 104}, // 5:2: ccw_put_left_fork
	{0x21, 110, 111, 103}, // 5:3: put_left_fork

	{0x31, 107, 110, 102, 108}, // 5:4: start_thinking
	{0x13, 109, 106, 108, 107}, // 5:5: start_eating
	{0x21, 102, 104, 112}, // 5:6: put_right_fork
	{0x31, 113, 120 /* next */ , 118, 114}, // 5:7: cw_start_thinking

	{0x13, 111, 103, 105, 106}, // 5:8: take_left_fork *choice
	{0x13, 111, 116, 117, 119}, // 5:9: cw_take_right_fork *choice
	{0x21, 118, 116, 111}, // 5:10: cw_put_right_fork
	{0x13, 114, 119, 115, 113}, // 5:11: cw_start_eating

	{0x22, 124, 121, 115 /* prev */ , 117 /* prev */ }, // 6:0: ccw_take_left_fork *choice
	{0x22, 124, 132, 129, 125}, // 6:1: take_right_fork *choice
	{0x21, 120, 121, 124}, // 6:2: ccw_put_left_fork
	{0x21, 130, 131, 123}, // 6:3: put_left_fork

	{0x31, 127, 130, 122, 128}, // 6:4: start_thinking
	{0x13, 129, 126, 128, 127}, // 6:5: start_eating
	{0x21, 122, 124, 132}, // 6:6: put_right_fork
	{0x31, 133, 140 /* next */ , 138, 134}, // 6:7: cw_start_thinking

	{0x13, 131, 123, 125, 126}, // 6:8: take_left_fork *choice
	{0x13, 131, 136, 137, 139}, // 6:9: cw_take_right_fork *choice
	{0x21, 138, 136, 131}, // 6:10: cw_put_right_fork
	{0x13, 134, 139, 135, 133}, // 6:11: cw_start_eating

	{0x22, 144, 141, 135 /* prev */ , 137 /* prev */ }, // 7:0: ccw_take_left_fork *choice
	{0x22, 144, 152, 149, 145}, // 7:1: take_right_fork *choice
	{0x21, 140, 141, 144}, // 7:2: ccw_put_left_fork
	{0x21, 150, 151, 143}, // 7:3: put_left_fork

	{0x31, 147, 150, 142, 148}, // 7:4: start_thinking
	{0x13, 149, 146, 148, 147}, // 7:5: start_eating
	{0x21, 142, 144, 152}, // 7:6: put_right_fork
	{0x31, 153, 160 /* next */ , 158, 154}, // 7:7: cw_start_thinking

	{0x13, 151, 143, 145, 146}, // 7:8: take_left_fork *choice
	{0x13, 151, 156, 157, 159}, // 7:9: cw_take_right_fork *choice
	{0x21, 158, 156, 151}, // 7:10: cw_put_right_fork
	{0x13, 154, 159, 155, 153}, // 7:11: cw_start_eating

	{0x22, 164, 161, 155 /* prev */ , 157 /* prev */ }, // 8:0: ccw_take_left_fork *choice
	{0x22, 164, 172, 169, 165}, // 8:1: take_right_fork *choice
	{0x21, 160, 161, 164}, // 8:2: ccw_put_left_fork
	{0x21, 170, 171, 163}, // 8:3: put_left_fork

	{0x31, 167, 170, 162, 168}, // 8:4: start_thinking
	{0x13, 169, 166, 168, 167}, // 8:5: start_eating
	{0x21, 162, 164, 172}, // 8:6: put_right_fork
	{0x31, 173, 180 /* next */ , 178, 174}, // 8:7: cw_start_thinking

	{0x13, 171, 163, 165, 166}, // 8:8: take_left_fork *choice
	{0x13, 171, 176, 177, 179}, // 8:9: cw_take_right_fork *choice
	{0x21, 178, 176, 171}, // 8:10: cw_put_right_fork
	{0x13, 174, 179, 175, 173}, // 8:11: cw_start_eating

	{0x22, 184, 181, 175 /* prev */ , 177 /* prev */ }, // 9:0: ccw_take_left_fork *choice
	{0x22, 184, 192, 189, 185}, // 9:1: take_right_fork *choice
	{0x21, 180, 181, 184}, // 9:2: ccw_put_left_fork
	{0x21, 190, 191, 183}, // 9:3: put_left_fork

	{0x31, 187, 190, 182, 188}, // 9:4: start_thinking
	{0x13, 189, 186, 188, 187}, // 9:5: start_eating
	{0x21, 182, 184, 192}, // 9:6: put_right_fork
	{0x31, 193, 200 /* next */ , 198, 194}, // 9:7: cw_start_thinking

	{0x13, 191, 183, 185, 186}, // 9:8: take_left_fork *choice
	{0x13, 191, 196, 197, 199}, // 9:9: cw_take_right_fork *choice
	{0x21, 198, 196, 191}, // 9:10: cw_put_right_fork
	{0x13, 194, 199, 195, 193}, // 9:11: cw_start_eating

	{0x22, 204, 201, 195 /* prev */ , 197 /* prev */ }, // 10:0: ccw_take_left_fork *choice
	{0x22, 204, 212, 209, 205}, // 10:1: take_right_fork *choice
	{0x21, 200, 201, 204}, // 10:2: ccw_put_left_fork
	{0x21, 210, 211, 203}, // 10:3: put_left_fork

	{0x31, 207, 210, 202, 208}, // 10:4: start_thinking
	{0x13, 209, 206, 208, 207}, // 10:5: start_eating
	{0x21, 202, 204, 212}, // 10:6: put_right_fork
	{0x31, 213, 220 /* next */ , 218, 214}, // 10:7: cw_start_thinking

	{0x13, 211, 203, 205, 206}, // 10:8: take_left_fork *choice
	{0x13, 211, 216, 217, 219}, // 10:9: cw_take_right_fork *choice
	{0x21, 218, 216, 211}, // 10:10: cw_put_right_fork
	{0x13, 214, 219, 215, 213}, // 10:11: cw_start_eating

	{0x22, 224, 221, 215 /* prev */ , 217 /* prev */ }, // 11:0: ccw_take_left_fork *choice
	{0x22, 224, 232, 229, 225}, // 11:1: take_right_fork *choice
	{0x21, 220, 221, 224}, // 11:2: ccw_put_left_fork
	{0x21, 230, 231, 223}, // 11:3: put_left_fork

	{0x31, 227, 230, 222, 228}, // 11:4: start_thinking
	{0x13, 229, 226, 228, 227}, // 11:5: start_eating
	{0x21, 222, 224, 232}, // 11:6: put_right_fork
	{0x31, 233, 240 /* next */ , 238, 234}, // 11:7: cw_start_thinking

	{0x13, 231, 223, 225, 226}, // 11:8: take_left_fork *choice
	{0x13, 231, 236, 237, 239}, // 11:9: cw_take_right_fork *choice
	{0x21, 238, 236, 231}, // 11:10: cw_put_right_fork
	{0x13, 234, 239, 235, 233}, // 11:11: cw_start_eating

	{0x22, 244, 241, 235 /* prev */ , 237 /* prev */ }, // 12:0: ccw_take_left_fork *choice
	{0x22, 244, 252, 249, 245}, // 12:1: take_right_fork *choice
	{0x21, 240, 241, 244}, // 12:2: ccw_put_left_fork
	{0x21, 250, 251, 243}, // 12:3: put_left_fork

	{0x31, 247, 250, 242, 248}, // 12:4: start_thinking
	{0x13, 249, 246, 248, 247}, // 12:5: start_eating
	{0x21, 242, 244, 252}, // 12:6: put_right_fork
	{0x31, 253, 260 /* next */ , 258, 254}, // 12:7: cw_start_thinking

	{0x13, 251, 243, 245, 246}, // 12:8: take_left_fork *choice
	{0x13, 251, 256, 257, 259}, // 12:9: cw_take_right_fork *choice
	{0x21, 258, 256, 251}, // 12:10: cw_put_right_fork
	{0x13, 254, 259, 255, 253}, // 12:11: cw_start_eating

	{0x22, 264, 261, 255 /* prev */ , 257 /* prev */ }, // 13:0: ccw_take_left_fork *choice
	{0x22, 264, 272, 269, 265}, // 13:1: take_right_fork *choice
	{0x21, 260, 261, 264}, // 13:2: ccw_put_left_fork
	{0x21, 270, 271, 263}, // 13:3: put_left_fork

	{0x31, 267, 270, 262, 268}, // 13:4: start_thinking
	{0x13, 269, 266, 268, 267}, // 13:5: start_eating
	{0x21, 262, 264, 272}, // 13:6: put_right_fork
	{0x31, 273, 280 /* next */ , 278, 274}, // 13:7: cw_start_thinking

	{0x13, 271, 263, 265, 266}, // 13:8: take_left_fork *choice
	{0x13, 271, 276, 277, 279}, // 13:9: cw_take_right_fork *choice
	{0x21, 278, 276, 271}, // 13:10: cw_put_right_fork
	{0x13, 274, 279, 275, 273}, // 13:11: cw_start_eating

	{0x22, 284, 281, 275 /* prev */ , 277 /* prev */ }, // 14:0: ccw_take_left_fork *choice
	{0x22, 284, 292, 289, 285}, // 14:1: take_right_fork *choice
	{0x21, 280, 281, 284}, // 14:2: ccw_put_left_fork
	{0x21, 290, 291, 283}, // 14:3: put_left_fork

	{0x31, 287, 290, 282, 288}, // 14:4: start_thinking
	{0x13, 289, 286, 288, 287}, // 14:5: start_eating
	{0x21, 282, 284, 292}, // 14:6: put_right_fork
	{0x31, 293, 300 /* next */ , 298, 294}, // 14:7: cw_start_thinking

	{0x13, 291, 283, 285, 286}, // 14:8: take_left_fork *choice
	{0x13, 291, 296, 297, 299}, // 14:9: cw_take_right_fork *choice
	{0x21, 298, 296, 291}, // 14:10: cw_put_right_fork
	{0x13, 294, 299, 295, 293}, // 14:11: cw_start_eating

	{0x22, 304, 301, 295 /* prev */ , 297 /* prev */ }, // 15:0: ccw_take_left_fork *choice
	{0x22, 304, 312, 309, 305}, // 15:1: take_right_fork *choice
	{0x21, 300, 301, 304}, // 15:2: ccw_put_left_fork
	{0x21, 310, 311, 303}, // 15:3: put_left_fork

	{0x31, 307, 310, 302, 308}, // 15:4: start_thinking
	{0x13, 309, 306, 308, 307}, // 15:5: start_eating
	{0x21, 302, 304, 312}, // 15:6: put_right_fork
	{0x31, 313, 320 /* next */ , 318, 314}, // 15:7: cw_start_thinking

	{0x13, 311, 303, 305, 306}, // 15:8: take_left_fork *choice
	{0x13, 311, 316, 317, 319}, // 15:9: cw_take_right_fork *choice
	{0x21, 318, 316, 311}, // 15:10: cw_put_right_fork
	{0x13, 314, 319, 315, 313}, // 15:11: cw_start_eating

	{0x22, 324, 321, 315 /* prev */ , 317 /* prev */ }, // 16:0: ccw_take_left_fork *choice
	{0x22, 324, 332, 329, 325}, // 16:1: take_right_fork *choice
	{0x21, 320, 321, 324}, // 16:2: ccw_put_left_fork
	{0x21, 330, 331, 323}, // 16:3: put_left_fork

	{0x31, 327, 330, 322, 328}, // 16:4: start_thinking
	{0x13, 329, 326, 328, 327}, // 16:5: start_eating
	{0x21, 322, 324, 332}, // 16:6: put_right_fork
	{0x31, 333, 340 /* next */ , 338, 334}, // 16:7: cw_start_thinking

	{0x13, 331, 323, 325, 326}, // 16:8: take_left_fork *choice
	{0x13, 331, 336, 337, 339}, // 16:9: cw_take_right_fork *choice
	{0x21, 338, 336, 331}, // 16:10: cw_put_right_fork
	{0x13, 334, 339, 335, 333}, // 16:11: cw_start_eating

	{0x22, 344, 341, 335 /* prev */ , 337 /* prev */ }, // 17:0: ccw_take_left_fork *choice
	{0x22, 344, 352, 349, 345}, // 17:1: take_right_fork *choice
	{0x21, 340, 341, 344}, // 17:2: ccw_put_left_fork
	{0x21, 350, 351, 343}, // 17:3: put_left_fork

	{0x31, 347, 350, 342, 348}, // 17:4: start_thinking
	{0x13, 349, 346, 348, 347}, // 17:5: start_eating
	{0x21, 342, 344, 352}, // 17:6: put_right_fork
	{0x31, 353, 360 /* next */ , 358, 354}, // 17:7: cw_start_thinking

	{0x13, 351, 343, 345, 346}, // 17:8: take_left_fork *choice
	{0x13, 351, 356, 357, 359}, // 17:9: cw_take_right_fork *choice
	{0x21, 358, 356, 351}, // 17:10: cw_put_right_fork
	{0x13, 354, 359, 355, 353}, // 17:11: cw_start_eating

	{0x22, 364, 361, 355 /* prev */ , 357 /* prev */ }, // 18:0: ccw_take_left_fork *choice
	{0x22, 364, 372, 369, 365}, // 18:1: take_right_fork *choice
	{0x21, 360, 361, 364}, // 18:2: ccw_put_left_fork
	{0x21, 370, 371, 363}, // 18:3: put_left_fork

	{0x31, 367, 370, 362, 368}, // 18:4: start_thinking
	{0x13, 369, 366, 368, 367}, // 18:5: start_eating
	{0x21, 362, 364, 372}, // 18:6: put_right_fork
	{0x31, 373, 380 /* next */ , 378, 374}, // 18:7: cw_start_thinking

	{0x13, 371, 363, 365, 366}, // 18:8: take_left_fork *choice
	{0x13, 371, 376, 377, 379}, // 18:9: cw_take_right_fork *choice
	{0x21, 378, 376, 371}, // 18:10: cw_put_right_fork
	{0x13, 374, 379, 375, 373}, // 18:11: cw_start_eating

	{0x22, 384, 381, 375 /* prev */ , 377 /* prev */ }, // 19:0: ccw_take_left_fork *choice
	{0x22, 384, 392, 389, 385}, // 19:1: take_right_fork *choice
	{0x21, 380, 381, 384}, // 19:2: ccw_put_left_fork
	{0x21, 390, 391, 383}, // 19:3: put_left_fork

	{0x31, 387, 390, 382, 388}, // 19:4: start_thinking
	{0x13, 389, 386, 388, 387}, // 19:5: start_eating
	{0x21, 382, 384, 392}, // 19:6: put_right_fork
	{0x31, 393, 400 /* next */ , 398, 394}, // 19:7: cw_start_thinking

	{0x13, 391, 383, 385, 386}, // 19:8: take_left_fork *choice
	{0x13, 391, 396, 397, 399}, // 19:9: cw_take_right_fork *choice
	{0x21, 398, 396, 391}, // 19:10: cw_put_right_fork
	{0x13, 394, 399, 395, 393}, // 19:11: cw_start_eating

	{0x22, 404, 401, 395 /* prev */ , 397 /* prev */ }, // 20:0: ccw_take_left_fork *choice
	{0x22, 404, 412, 409, 405}, // 20:1: take_right_fork *choice
	{0x21, 400, 401, 404}, // 20:2: ccw_put_left_fork
	{0x21, 410, 411, 403}, // 20:3: put_left_fork

	{0x31, 407, 410, 402, 408}, // 20:4: start_thinking
	{0x13, 409, 406, 408, 407}, // 20:5: start_eating
	{0x21, 402, 404, 412}, // 20:6: put_right_fork
	{0x31, 413, 420 /* next */ , 418, 414}, // 20:7: cw_start_thinking

	{0x13, 411, 403, 405, 406}, // 20:8: take_left_fork *choice
	{0x13, 411, 416, 417, 419}, // 20:9: cw_take_right_fork *choice
	{0x21, 418, 416, 411}, // 20:10: cw_put_right_fork
	{0x13, 414, 419, 415, 413}, // 20:11: cw_start_eating

	{0x22, 424, 421, 415 /* prev */ , 417 /* prev */ }, // 21:0: ccw_take_left_fork *choice
	{0x22, 424, 432, 429, 425}, // 21:1: take_right_fork *choice
	{0x21, 420, 421, 424}, // 21:2: ccw_put_left_fork
	{0x21, 430, 431, 423}, // 21:3: put_left_fork

	{0x31, 427, 430, 422, 428}, // 21:4: start_thinking
	{0x13, 429, 426, 428, 427}, // 21:5: start_eating
	{0x21, 422, 424, 432}, // 21:6: put_right_fork
	{0x31, 433, 440 /* next */ , 438, 434}, // 21:7: cw_start_thinking

	{0x13, 431, 423, 425, 426}, // 21:8: take_left_fork *choice
	{0x13, 431, 436, 437, 439}, // 21:9: cw_take_right_fork *choice
	{0x21, 438, 436, 431}, // 21:10: cw_put_right_fork
	{0x13, 434, 439, 435, 433}, // 21:11: cw_start_eating

	{0x22, 444, 441, 435 /* prev */ , 437 /* prev */ }, // 22:0: ccw_take_left_fork *choice
	{0x22, 444, 452, 449, 445}, // 22:1: take_right_fork *choice
	{0x21, 440, 441, 444}, // 22:2: ccw_put_left_fork
	{0x21, 450, 451, 443}, // 22:3: put_left_fork

	{0x31, 447, 450, 442, 448}, // 22:4: start_thinking
	{0x13, 449, 446, 448, 447}, // 22:5: start_eating
	{0x21, 442, 444, 452}, // 22:6: put_right_fork
	{0x31, 453, 460 /* next */ , 458, 454}, // 22:7: cw_start_thinking

	{0x13, 451, 443, 445, 446}, // 22:8: take_left_fork *choice
	{0x13, 451, 456, 457, 459}, // 22:9: cw_take_right_fork *choice
	{0x21, 458, 456, 451}, // 22:10: cw_put_right_fork
	{0x13, 454, 459, 455, 453}, // 22:11: cw_start_eating

	{0x22, 464, 461, 455 /* prev */ , 457 /* prev */ }, // 23:0: ccw_take_left_fork *choice
	{0x22, 464, 472, 469, 465}, // 23:1: take_right_fork *choice
	{0x21, 460, 461, 464}, // 23:2: ccw_put_left_fork
	{0x21, 470, 471, 463}, // 23:3: put_left_fork

	{0x31, 467, 470, 462, 468}, // 23:4: start_thinking
	{0x13, 469, 466, 468, 467}, // 23:5: start_eating
	{0x21, 462, 464, 472}, // 23:6: put_right_fork
	{0x31, 473, 480 /* next */ , 478, 474}, // 23:7: cw_start_thinking

	{0x13, 471, 463, 465, 466}, // 23:8: take_left_fork *choice
	{0x13, 471, 476, 477, 479}, // 23:9: cw_take_right_fork *choice
	{0x21, 478, 476, 471}, // 23:10: cw_put_right_fork
	{0x13, 474, 479, 475, 473}, // 23:11: cw_start_eating

	{0x22, 484, 481, 475 /* prev */ , 477 /* prev */ }, // 24:0: ccw_take_left_fork *choice
	{0x22, 484, 492, 489, 485}, // 24:1: take_right_fork *choice
	{0x21, 480, 481, 484}, // 24:2: ccw_put_left_fork
	{0x21, 490, 491, 483}, // 24:3: put_left_fork

	{0x31, 487, 490, 482, 488}, // 24:4: start_thinking
	{0x13, 489, 486, 488, 487}, // 24:5: start_eating
	{0x21, 482, 484, 492}, // 24:6: put_right_fork
	{0x31, 493, 500 /* next */ , 498, 494}, // 24:7: cw_start_thinking

	{0x13, 491, 483, 485, 486}, // 24:8: take_left_fork *choice
	{0x13, 491, 496, 497, 499}, // 24:9: cw_take_right_fork *choice
	{0x21, 498, 496, 491}, // 24:10: cw_put_right_fork
	{0x13, 494, 499, 495, 493}, // 24:11: cw_start_eating

	{0x22, 504, 501, 495 /* prev */ , 497 /* prev */ }, // 25:0: ccw_take_left_fork *choice
	{0x22, 504, 512, 509, 505}, // 25:1: take_right_fork *choice
	{0x21, 500, 501, 504}, // 25:2: ccw_put_left_fork
	{0x21, 510, 511, 503}, // 25:3: put_left_fork

	{0x31, 507, 510, 502, 508}, // 25:4: start_thinking
	{0x13, 509, 506, 508, 507}, // 25:5: start_eating
	{0x21, 502, 504, 512}, // 25:6: put_right_fork
	{0x31, 513, 520 /* next */ , 518, 514}, // 25:7: cw_start_thinking

	{0x13, 511, 503, 505, 506}, // 25:8: take_left_fork *choice
	{0x13, 511, 516, 517, 519}, // 25:9: cw_take_right_fork *choice
	{0x21, 518, 516, 511}, // 25:10: cw_put_right_fork
	{0x13, 514, 519, 515, 513}, // 25:11: cw_start_eating

	{0x22, 524, 521, 515 /* prev */ , 517 /* prev */ }, // 26:0: ccw_take_left_fork *choice
	{0x22, 524, 532, 529, 525}, // 26:1: take_right_fork *choice
	{0x21, 520, 521, 524}, // 26:2: ccw_put_left_fork
	{0x21, 530, 531, 523}, // 26:3: put_left_fork

	{0x31, 527, 530, 522, 528}, // 26:4: start_thinking
	{0x13, 529, 526, 528, 527}, // 26:5: start_eating
	{0x21, 522, 524, 532}, // 26:6: put_right_fork
	{0x31, 533, 540 /* next */ , 538, 534}, // 26:7: cw_start_thinking

	{0x13, 531, 523, 525, 526}, // 26:8: take_left_fork *choice
	{0x13, 531, 536, 537, 539}, // 26:9: cw_take_right_fork *choice
	{0x21, 538, 536, 531}, // 26:10: cw_put_right_fork
	{0x13, 534, 539, 535, 533}, // 26:11: cw_start_eating

	{0x22, 544, 541, 535 /* prev */ , 537 /* prev */ }, // 27:0: ccw_take_left_fork *choice
	{0x22, 544, 552, 549, 545}, // 27:1: take_right_fork *choice
	{0x21, 540, 541, 544}, // 27:2: ccw_put_left_fork
	{0x21, 550, 551, 543}, // 27:3: put_left_fork

	{0x31, 547, 550, 542, 548}, // 27:4: start_thinking
	{0x13, 549, 546, 548, 547}, // 27:5: start_eating
	{0x21, 542, 544, 552}, // 27:6: put_right_fork
	{0x31, 553, 560 /* next */ , 558, 554}, // 27:7: cw_start_thinking

	{0x13, 551, 543, 545, 546}, // 27:8: take_left_fork *choice
	{0x13, 551, 556, 557, 559}, // 27:9: cw_take_right_fork *choice
	{0x21, 558, 556, 551}, // 27:10: cw_put_right_fork
	{0x13, 554, 559, 555, 553}, // 27:11: cw_start_eating

	{0x22, 564, 561, 555 /* prev */ , 557 /* prev */ }, // 28:0: ccw_take_left_fork *choice
	{0x22, 564, 572, 569, 565}, // 28:1: take_right_fork *choice
	{0x21, 560, 561, 564}, // 28:2: ccw_put_left_fork
	{0x21, 570, 571, 563}, // 28:3: put_left_fork

	{0x31, 567, 570, 562, 568}, // 28:4: start_thinking
	{0x13, 569, 566, 568, 567}, // 28:5: start_eating
	{0x21, 562, 564, 572}, // 28:6: put_right_fork
	{0x31, 573, 580 /* next */ , 578, 574}, // 28:7: cw_start_thinking

	{0x13, 571, 563, 565, 566}, // 28:8: take_left_fork *choice
	{0x13, 571, 576, 577, 579}, // 28:9: cw_take_right_fork *choice
	{0x21, 578, 576, 571}, // 28:10: cw_put_right_fork
	{0x13, 574, 579, 575, 573}, // 28:11: cw_start_eating

	{0x22, 584, 581, 575 /* prev */ , 577 /* prev */ }, // 29:0: ccw_take_left_fork *choice
	{0x22, 584, 592, 589, 585}, // 29:1: take_right_fork *choice
	{0x21, 580, 581, 584}, // 29:2: ccw_put_left_fork
	{0x21, 590, 591, 583}, // 29:3: put_left_fork

	{0x31, 587, 590, 582, 588}, // 29:4: start_thinking
	{0x13, 589, 586, 588, 587}, // 29:5: start_eating
	{0x21, 582, 584, 592}, // 29:6: put_right_fork
	{0x31, 593, 600 /* next */ , 598, 594}, // 29:7: cw_start_thinking

	{0x13, 591, 583, 585, 586}, // 29:8: take_left_fork *choice
	{0x13, 591, 596, 597, 599}, // 29:9: cw_take_right_fork *choice
	{0x21, 598, 596, 591}, // 29:10: cw_put_right_fork
	{0x13, 594, 599, 595, 593}, // 29:11: cw_start_eating

	{0x22, 604, 601, 595 /* prev */ , 597 /* prev */ }, // 30:0: ccw_take_left_fork *choice
	{0x22, 604, 612, 609, 605}, // 30:1: take_right_fork *choice
	{0x21, 600, 601, 604}, // 30:2: ccw_put_left_fork
	{0x21, 610, 611, 603}, // 30:3: put_left_fork

	{0x31, 607, 610, 602, 608}, // 30:4: start_thinking
	{0x13, 609, 606, 608, 607}, // 30:5: start_eating
	{0x21, 602, 604, 612}, // 30:6: put_right_fork
	{0x31, 613, 620 /* next */ , 618, 614}, // 30:7: cw_start_thinking

	{0x13, 611, 603, 605, 606}, // 30:8: take_left_fork *choice
	{0x13, 611, 616, 617, 619}, // 30:9: cw_take_right_fork *choice
	{0x21, 618, 616, 611}, // 30:10: cw_put_right_fork
	{0x13, 614, 619, 615, 613}, // 30:11: cw_start_eating

	{0x22, 624, 621, 615 /* prev */ , 617 /* prev */ }, // 31:0: ccw_take_left_fork *choice
	{0x22, 624, 632, 629, 625}, // 31:1: take_right_fork *choice
	{0x21, 620, 621, 624}, // 31:2: ccw_put_left_fork
	{0x21, 630, 631, 623}, // 31:3: put_left_fork

	{0x31, 627, 630, 622, 628}, // 31:4: start_thinking
	{0x13, 629, 626, 628, 627}, // 31:5: start_eating
	{0x21, 622, 624, 632}, // 31:6: put_right_fork
	{0x31, 633, 640 /* next */ , 638, 634}, // 31:7: cw_start_thinking

	{0x13, 631, 623, 625, 626}, // 31:8: take_left_fork *choice
	{0x13, 631, 636, 637, 639}, // 31:9: cw_take_right_fork *choice
	{0x21, 638, 636, 631}, // 31:10: cw_put_right_fork
	{0x13, 634, 639, 635, 633}, // 31:11: cw_start_eating

	{0x22, 644, 641, 635 /* prev */ , 637 /* prev */ }, // 32:0: ccw_take_left_fork *choice
	{0x22, 644, 652, 649, 645}, // 32:1: take_right_fork *choice
	{0x21, 640, 641, 644}, // 32:2: ccw_put_left_fork
	{0x21, 650, 651, 643}, // 32:3: put_left_fork

	{0x31, 647, 650, 642, 648}, // 32:4: start_thinking
	{0x13, 649, 646, 648, 647}, // 32:5: start_eating
	{0x21, 642, 644, 652}, // 32:6: put_right_fork
	{0x31, 653, 660 /* next */ , 658, 654}, // 32:7: cw_start_thinking

	{0x13, 651, 643, 645, 646}, // 32:8: take_left_fork *choice
	{0x13, 651, 656, 657, 659}, // 32:9: cw_take_right_fork *choice
	{0x21, 658, 656, 651}, // 32:10: cw_put_right_fork
	{0x13, 654, 659, 655, 653}, // 32:11: cw_start_eating

	{0x22, 664, 661, 655 /* prev */ , 657 /* prev */ }, // 33:0: ccw_take_left_fork *choice
	{0x22, 664, 672, 669, 665}, // 33:1: take_right_fork *choice
	{0x21, 660, 661, 664}, // 33:2: ccw_put_left_fork
	{0x21, 670, 671, 663}, // 33:3: put_left_fork

	{0x31, 667, 670, 662, 668}, // 33:4: start_thinking
	{0x13, 669, 666, 668, 667}, // 33:5: start_eating
	{0x21, 662, 664, 672}, // 33:6: put_right_fork
	{0x31, 673, 680 /* next */ , 678, 674}, // 33:7: cw_start_thinking

	{0x13, 671, 663, 665, 666}, // 33:8: take_left_fork *choice
	{0x13, 671, 676, 677, 679}, // 33:9: cw_take_right_fork *choice
	{0x21, 678, 676, 671}, // 33:10: cw_put_right_fork
	{0x13, 674, 679, 675, 673}, // 33:11: cw_start_eating

	{0x22, 684, 681, 675 /* prev */ , 677 /* prev */ }, // 34:0: ccw_take_left_fork *choice
	{0x22, 684, 692, 689, 685}, // 34:1: take_right_fork *choice
	{0x21, 680, 681, 684}, // 34:2: ccw_put_left_fork
	{0x21, 690, 691, 683}, // 34:3: put_left_fork

	{0x31, 687, 690, 682, 688}, // 34:4: start_thinking
	{0x13, 689, 686, 688, 687}, // 34:5: start_eating
	{0x21, 682, 684, 692}, // 34:6: put_right_fork
	{0x31, 693, 700 /* next */ , 698, 694}, // 34:7: cw_start_thinking

	{0x13, 691, 683, 685, 686}, // 34:8: take_left_fork *choice
	{0x13, 691, 696, 697, 699}, // 34:9: cw_take_right_fork *choice
	{0x21, 698, 696, 691}, // 34:10: cw_put_right_fork
	{0x13, 694, 699, 695, 693}, // 34:11: cw_start_eating

	{0x22, 704, 701, 695 /* prev */ , 697 /* prev */ }, // 35:0: ccw_take_left_fork *choice
	{0x22, 704, 712, 709, 705}, // 35:1: take_right_fork *choice
	{0x21, 700, 701, 704}, // 35:2: ccw_put_left_fork
	{0x21, 710, 711, 703}, // 35:3: put_left_fork

	{0x31, 707, 710, 702, 708}, // 35:4: start_thinking
	{0x13, 709, 706, 708, 707}, // 35:5: start_eating
	{0x21, 702, 704, 712}, // 35:6: put_right_fork
	{0x31, 713, 720 /* next */ , 718, 714}, // 35:7: cw_start_thinking

	{0x13, 711, 703, 705, 706}, // 35:8: take_left_fork *choice
	{0x13, 711, 716, 717, 719}, // 35:9: cw_take_right_fork *choice
	{0x21, 718, 716, 711}, // 35:10: cw_put_right_fork
	{0x13, 714, 719, 715, 713}, // 35:11: cw_start_eating

	{0x22, 724, 721, 715 /* prev */ , 717 /* prev */ }, // 36:0: ccw_take_left_fork *choice
	{0x22, 724, 732, 729, 725}, // 36:1: take_right_fork *choice
	{0x21, 720, 721, 724}, // 36:2: ccw_put_left_fork
	{0x21, 730, 731, 723}, // 36:3: put_left_fork

	{0x31, 727, 730, 722, 728}, // 36:4: start_thinking
	{0x13, 729, 726, 728, 727}, // 36:5: start_eating
	{0x21, 722, 724, 732}, // 36:6: put_right_fork
	{0x31, 733, 740 /* next */ , 738, 734}, // 36:7: cw_start_thinking

	{0x13, 731, 723, 725, 726}, // 36:8: take_left_fork *choice
	{0x13, 731, 736, 737, 739}, // 36:9: cw_take_right_fork *choice
	{0x21, 738, 736, 731}, // 36:10: cw_put_right_fork
	{0x13, 734, 739, 735, 733}, // 36:11: cw_start_eating

	{0x22, 744, 741, 735 /* prev */ , 737 /* prev */ }, // 37:0: ccw_take_left_fork *choice
	{0x22, 744, 752, 749, 745}, // 37:1: take_right_fork *choice
	{0x21, 740, 741, 744}, // 37:2: ccw_put_left_fork
	{0x21, 750, 751, 743}, // 37:3: put_left_fork

	{0x31, 747, 750, 742, 748}, // 37:4: start_thinking
	{0x13, 749, 746, 748, 747}, // 37:5: start_eating
	{0x21, 742, 744, 752}, // 37:6: put_right_fork
	{0x31, 753, 760 /* next */ , 758, 754}, // 37:7: cw_start_thinking

	{0x13, 751, 743, 745, 746}, // 37:8: take_left_fork *choice
	{0x13, 751, 756, 757, 759}, // 37:9: cw_take_right_fork *choice
	{0x21, 758, 756, 751}, // 37:10: cw_put_right_fork
	{0x13, 754, 759, 755, 753}, // 37:11: cw_start_eating

	{0x22, 764, 761, 755 /* prev */ , 757 /* prev */ }, // 38:0: ccw_take_left_fork *choice
	{0x22, 764, 772, 769, 765}, // 38:1: take_right_fork *choice
	{0x21, 760, 761, 764}, // 38:2: ccw_put_left_fork
	{0x21, 770, 771, 763}, // 38:3: put_left_fork

	{0x31, 767, 770, 762, 768}, // 38:4: start_thinking
	{0x13, 769, 766, 768, 767}, // 38:5: start_eating
	{0x21, 762, 764, 772}, // 38:6: put_right_fork
	{0x31, 773, 780 /* next */ , 778, 774}, // 38:7: cw_start_thinking

	{0x13, 771, 763, 765, 766}, // 38:8: take_left_fork *choice
	{0x13, 771, 776, 777, 779}, // 38:9: cw_take_right_fork *choice
	{0x21, 778, 776, 771}, // 38:10: cw_put_right_fork
	{0x13, 774, 779, 775, 773}, // 38:11: cw_start_eating

	{0x22, 784, 781, 775 /* prev */ , 777 /* prev */ }, // 39:0: ccw_take_left_fork *choice
	{0x22, 784, 792, 789, 785}, // 39:1: take_right_fork *choice
	{0x21, 780, 781, 784}, // 39:2: ccw_put_left_fork
	{0x21, 790, 791, 783}, // 39:3: put_left_fork

	{0x31, 787, 790, 782, 788}, // 39:4: start_thinking
	{0x13, 789, 786, 788, 787}, // 39:5: start_eating
	{0x21, 782, 784, 792}, // 39:6: put_right_fork
	{0x31, 793, 800 /* next */ , 798, 794}, // 39:7: cw_start_thinking

	{0x13, 791, 783, 785, 786}, // 39:8: take_left_fork *choice
	{0x13, 791, 796, 797, 799}, // 39:9: cw_take_right_fork *choice
	{0x21, 798, 796, 791}, // 39:10: cw_put_right_fork
	{0x13, 794, 799, 795, 793}, // 39:11: cw_start_eating

	{0x22, 804, 801, 795 /* prev */ , 797 /* prev */ }, // 40:0: ccw_take_left_fork *choice
	{0x22, 804, 812, 809, 805}, // 40:1: take_right_fork *choice
	{0x21, 800, 801, 804}, // 40:2: ccw_put_left_fork
	{0x21, 810, 811, 803}, // 40:3: put_left_fork

	{0x31, 807, 810, 802, 808}, // 40:4: start_thinking
	{0x13, 809, 806, 808, 807}, // 40:5: start_eating
	{0x21, 802, 804, 812}, // 40:6: put_right_fork
	{0x31, 813, 820 /* next */ , 818, 814}, // 40:7: cw_start_thinking

	{0x13, 811, 803, 805, 806}, // 40:8: take_left_fork *choice
	{0x13, 811, 816, 817, 819}, // 40:9: cw_take_right_fork *choice
	{0x21, 818, 816, 811}, // 40:10: cw_put_right_fork
	{0x13, 814, 819, 815, 813}, // 40:11: cw_start_eating

	{0x22, 824, 821, 815 /* prev */ , 817 /* prev */ }, // 41:0: ccw_take_left_fork *choice
	{0x22, 824, 832, 829, 825}, // 41:1: take_right_fork *choice
	{0x21, 820, 821, 824}, // 41:2: ccw_put_left_fork
	{0x21, 830, 831, 823}, // 41:3: put_left_fork

	{0x31, 827, 830, 822, 828}, // 41:4: start_thinking
	{0x13, 829, 826, 828, 827}, // 41:5: start_eating
	{0x21, 822, 824, 832}, // 41:6: put_right_fork
	{0x31, 833, 840 /* next */ , 838, 834}, // 41:7: cw_start_thinking

	{0x13, 831, 823, 825, 826}, // 41:8: take_left_fork *choice
	{0x13, 831, 836, 837, 839}, // 41:9: cw_take_right_fork *choice
	{0x21, 838, 836, 831}, // 41:10: cw_put_right_fork
	{0x13, 834, 839, 835, 833}, // 41:11: cw_start_eating

	{0x22, 844, 841, 835 /* prev */ , 837 /* prev */ }, // 42:0: ccw_take_left_fork *choice
	{0x22, 844, 852, 849, 845}, // 42:1: take_right_fork *choice
	{0x21, 840, 841, 844}, // 42:2: ccw_put_left_fork
	{0x21, 850, 851, 843}, // 42:3: put_left_fork

	{0x31, 847, 850, 842, 848}, // 42:4: start_thinking
	{0x13, 849, 846, 848, 847}, // 42:5: start_eating
	{0x21, 842, 844, 852}, // 42:6: put_right_fork
	{0x31, 853, 860 /* next */ , 858, 854}, // 42:7: cw_start_thinking

	{0x13, 851, 843, 845, 846}, // 42:8: take_left_fork *choice
	{0x13, 851, 856, 857, 859}, // 42:9: cw_take_right_fork *choice
	{0x21, 858, 856, 851}, // 42:10: cw_put_right_fork
	{0x13, 854, 859, 855, 853}, // 42:11: cw_start_eating

	{0x22, 864, 861, 855 /* prev */ , 857 /* prev */ }, // 43:0: ccw_take_left_fork *choice
	{0x22, 864, 872, 869, 865}, // 43:1: take_right_fork *choice
	{0x21, 860, 861, 864}, // 43:2: ccw_put_left_fork
	{0x21, 870, 871, 863}, // 43:3: put_left_fork

	{0x31, 867, 870, 862, 868}, // 43:4: start_thinking
	{0x13, 869, 866, 868, 867}, // 43:5: start_eating
	{0x21, 862, 864, 872}, // 43:6: put_right_fork
	{0x31, 873, 880 /* next */ , 878, 874}, // 43:7: cw_start_thinking

	{0x13, 871, 863, 865, 866}, // 43:8: take_left_fork *choice
	{0x13, 871, 876, 877, 879}, // 43:9: cw_take_right_fork *choice
	{0x21, 878, 876, 871}, // 43:10: cw_put_right_fork
	{0x13, 874, 879, 875, 873}, // 43:11: cw_start_eating

	{0x22, 884, 881, 875 /* prev */ , 877 /* prev */ }, // 44:0: ccw_take_left_fork *choice
	{0x22, 884, 892, 889, 885}, // 44:1: take_right_fork *choice
	{0x21, 880, 881, 884}, // 44:2: ccw_put_left_fork
	{0x21, 890, 891, 883}, // 44:3: put_left_fork

	{0x31, 887, 890, 882, 888}, // 44:4: start_thinking
	{0x13, 889, 886, 888, 887}, // 44:5: start_eating
	{0x21, 882, 884, 892}, // 44:6: put_right_fork
	{0x31, 893, 900 /* next */ , 898, 894}, // 44:7: cw_start_thinking

	{0x13, 891, 883, 885, 886}, // 44:8: take_left_fork *choice
	{0x13, 891, 896, 897, 899}, // 44:9: cw_take_right_fork *choice
	{0x21, 898, 896, 891}, // 44:10: cw_put_right_fork
	{0x13, 894, 899, 895, 893}, // 44:11: cw_start_eating

	{0x22, 904, 901, 895 /* prev */ , 897 /* prev */ }, // 45:0: ccw_take_left_fork *choice
	{0x22, 904, 912, 909, 905}, // 45:1: take_right_fork *choice
	{0x21, 900, 901, 904}, // 45:2: ccw_put_left_fork
	{0x21, 910, 911, 903}, // 45:3: put_left_fork

	{0x31, 907, 910, 902, 908}, // 45:4: start_thinking
	{0x13, 909, 906, 908, 907}, // 45:5: start_eating
	{0x21, 902, 904, 912}, // 45:6: put_right_fork
	{0x31, 913, 920 /* next */ , 918, 914}, // 45:7: cw_start_thinking

	{0x13, 911, 903, 905, 906}, // 45:8: take_left_fork *choice
	{0x13, 911, 916, 917, 919}, // 45:9: cw_take_right_fork *choice
	{0x21, 918, 916, 911}, // 45:10: cw_put_right_fork
	{0x13, 914, 919, 915, 913}, // 45:11: cw_start_eating

	{0x22, 924, 921, 915 /* prev */ , 917 /* prev */ }, // 46:0: ccw_take_left_fork *choice
	{0x22, 924, 932, 929, 925}, // 46:1: take_right_fork *choice
	{0x21, 920, 921, 924}, // 46:2: ccw_put_left_fork
	{0x21, 930, 931, 923}, // 46:3: put_left_fork

	{0x31, 927, 930, 922, 928}, // 46:4: start_thinking
	{0x13, 929, 926, 928, 927}, // 46:5: start_eating
	{0x21, 922, 924, 932}, // 46:6: put_right_fork
	{0x31, 933, 940 /* next */ , 938, 934}, // 46:7: cw_start_thinking

	{0x13, 931, 923, 925, 926}, // 46:8: take_left_fork *choice
	{0x13, 931, 936, 937, 939}, // 46:9: cw_take_right_fork *choice
	{0x21, 938, 936, 931}, // 46:10: cw_put_right_fork
	{0x13, 934, 939, 935, 933}, // 46:11: cw_start_eating

	{0x22, 944, 941, 935 /* prev */ , 937 /* prev */ }, // 47:0: ccw_take_left_fork *choice
	{0x22, 944, 952, 949, 945}, // 47:1: take_right_fork *choice
	{0x21, 940, 941, 944}, // 47:2: ccw_put_left_fork
	{0x21, 950, 951, 943}, // 47:3: put_left_fork

	{0x31, 947, 950, 942, 948}, // 47:4: start_thinking
	{0x13, 949, 946, 948, 947}, // 47:5: start_eating
	{0x21, 942, 944, 952}, // 47:6: put_right_fork
	{0x31, 953, 960 /* next */ , 958, 954}, // 47:7: cw_start_thinking

	{0x13, 951, 943, 945, 946}, // 47:8: take_left_fork *choice
	{0x13, 951, 956, 957, 959}, // 47:9: cw_take_right_fork *choice
	{0x21, 958, 956, 951}, // 47:10: cw_put_right_fork
	{0x13, 954, 959, 955, 953}, // 47:11: cw_start_eating

	{0x22, 964, 961, 955 /* prev */ , 957 /* prev */ }, // 48:0: ccw_take_left_fork *choice
	{0x22, 964, 972, 969, 965}, // 48:1: take_right_fork *choice
	{0x21, 960, 961, 964}, // 48:2: ccw_put_left_fork
	{0x21, 970, 971, 963}, // 48:3: put_left_fork

	{0x31, 967, 970, 962, 968}, // 48:4: start_thinking
	{0x13, 969, 966, 968, 967}, // 48:5: start_eating
	{0x21, 962, 964, 972}, // 48:6: put_right_fork
	{0x31, 973, 980 /* next */ , 978, 974}, // 48:7: cw_start_thinking

	{0x13, 971, 963, 965, 966}, // 48:8: take_left_fork *choice
	{0x13, 971, 976, 977, 979}, // 48:9: cw_take_right_fork *choice
	{0x21, 978, 976, 971}, // 48:10: cw_put_right_fork
	{0x13, 974, 979, 975, 973}, // 48:11: cw_start_eating

	{0x22, 984, 981, 975 /* prev */ , 977 /* prev */ }, // 49:0: ccw_take_left_fork *choice
	{0x22, 984, 992, 989, 985}, // 49:1: take_right_fork *choice
	{0x21, 980, 981, 984}, // 49:2: ccw_put_left_fork
	{0x21, 990, 991, 983}, // 49:3: put_left_fork

	{0x31, 987, 990, 982, 988}, // 49:4: start_thinking
	{0x13, 989, 986, 988, 987}, // 49:5: start_eating
	{0x21, 982, 984, 992}, // 49:6: put_right_fork
	{0x31, 993, 1002 /* out */ , 998, 994}, // 49:7: cw_start_thinking

	{0x13, 991, 983, 985, 986}, // 49:8: take_left_fork *choice
	{0x13, 991, 996, 997, 999}, // 49:9: cw_take_right_fork *choice
	{0x21, 998, 996, 991}, // 49:10: cw_put_right_fork
	{0x13, 994, 999, 995, 993} // 49:11: cw_start_eating

};

#endif
