#ifndef _PIPE_TMAP_H_
#define _PIPE_TMAP_H_

#define TMAP_NAME "PIPE"

const uint16_t localPlaces = 1012;
const uint8_t outPlaces = 4;
const uint16_t transitions = 460; // (10 aligned to 1) x 46 steps

#if (MAX_TRANS_CONNECTS<6)
#error "not enough connectivity in Transition"
#endif

const Transition tmap[transitions] = {
	// {0xoi, inp-s, outp-s}
	{0x33, 8, 10, 14, 12, 11, 9}, // 0:0: t4
	{0x33, 11, 16, 18, 14, 13, 15}, // 0:1: t5
	{0x22, 13, 19, 16, 17}, // 0:2: t6
	{0x22, 17, 1, 22 /* next */ , 19}, // 0:3: t7
	{0x22, 15, 20, 18, 21}, // 0:4: t8
	{0x22, 21, 3, 24 /* next */ , 20}, // 0:5: t9
	{0x22, 0, 5, 4, 1012 /* out */ }, // 0:6: t0
	{0x22, 4, 9, 5, 8}, // 0:7: t1
	{0x22, 2, 7, 6, 1013 /* out */ }, // 0:8: t2
	{0x22, 6, 12, 10, 7}, // 0:9: t3
	{0x33, 30, 32, 36, 34, 33, 31}, // 1:0: t4
	{0x33, 33, 38, 40, 36, 35, 37}, // 1:1: t5
	{0x22, 35, 41, 38, 39}, // 1:2: t6
	{0x22, 39, 23, 44 /* next */ , 41}, // 1:3: t7
	{0x22, 37, 42, 40, 43}, // 1:4: t8
	{0x22, 43, 25, 46 /* next */ , 42}, // 1:5: t9
	{0x22, 22, 27, 26, 1 /* prev */ }, // 1:6: t0
	{0x22, 26, 31, 27, 30}, // 1:7: t1
	{0x22, 24, 29, 28, 3 /* prev */ }, // 1:8: t2
	{0x22, 28, 34, 32, 29}, // 1:9: t3
	{0x33, 52, 54, 58, 56, 55, 53}, // 2:0: t4
	{0x33, 55, 60, 62, 58, 57, 59}, // 2:1: t5
	{0x22, 57, 63, 60, 61}, // 2:2: t6
	{0x22, 61, 45, 66 /* next */ , 63}, // 2:3: t7
	{0x22, 59, 64, 62, 65}, // 2:4: t8
	{0x22, 65, 47, 68 /* next */ , 64}, // 2:5: t9
	{0x22, 44, 49, 48, 23 /* prev */ }, // 2:6: t0
	{0x22, 48, 53, 49, 52}, // 2:7: t1
	{0x22, 46, 51, 50, 25 /* prev */ }, // 2:8: t2
	{0x22, 50, 56, 54, 51}, // 2:9: t3
	{0x33, 74, 76, 80, 78, 77, 75}, // 3:0: t4
	{0x33, 77, 82, 84, 80, 79, 81}, // 3:1: t5
	{0x22, 79, 85, 82, 83}, // 3:2: t6
	{0x22, 83, 67, 88 /* next */ , 85}, // 3:3: t7
	{0x22, 81, 86, 84, 87}, // 3:4: t8
	{0x22, 87, 69, 90 /* next */ , 86}, // 3:5: t9
	{0x22, 66, 71, 70, 45 /* prev */ }, // 3:6: t0
	{0x22, 70, 75, 71, 74}, // 3:7: t1
	{0x22, 68, 73, 72, 47 /* prev */ }, // 3:8: t2
	{0x22, 72, 78, 76, 73}, // 3:9: t3
	{0x33, 96, 98, 102, 100, 99, 97}, // 4:0: t4
	{0x33, 99, 104, 106, 102, 101, 103}, // 4:1: t5
	{0x22, 101, 107, 104, 105}, // 4:2: t6
	{0x22, 105, 89, 110 /* next */ , 107}, // 4:3: t7
	{0x22, 103, 108, 106, 109}, // 4:4: t8
	{0x22, 109, 91, 112 /* next */ , 108}, // 4:5: t9
	{0x22, 88, 93, 92, 67 /* prev */ }, // 4:6: t0
	{0x22, 92, 97, 93, 96}, // 4:7: t1
	{0x22, 90, 95, 94, 69 /* prev */ }, // 4:8: t2
	{0x22, 94, 100, 98, 95}, // 4:9: t3
	{0x33, 118, 120, 124, 122, 121, 119}, // 5:0: t4
	{0x33, 121, 126, 128, 124, 123, 125}, // 5:1: t5
	{0x22, 123, 129, 126, 127}, // 5:2: t6
	{0x22, 127, 111, 132 /* next */ , 129}, // 5:3: t7
	{0x22, 125, 130, 128, 131}, // 5:4: t8
	{0x22, 131, 113, 134 /* next */ , 130}, // 5:5: t9
	{0x22, 110, 115, 114, 89 /* prev */ }, // 5:6: t0
	{0x22, 114, 119, 115, 118}, // 5:7: t1
	{0x22, 112, 117, 116, 91 /* prev */ }, // 5:8: t2
	{0x22, 116, 122, 120, 117}, // 5:9: t3
	{0x33, 140, 142, 146, 144, 143, 141}, // 6:0: t4
	{0x33, 143, 148, 150, 146, 145, 147}, // 6:1: t5
	{0x22, 145, 151, 148, 149}, // 6:2: t6
	{0x22, 149, 133, 154 /* next */ , 151}, // 6:3: t7
	{0x22, 147, 152, 150, 153}, // 6:4: t8
	{0x22, 153, 135, 156 /* next */ , 152}, // 6:5: t9
	{0x22, 132, 137, 136, 111 /* prev */ }, // 6:6: t0
	{0x22, 136, 141, 137, 140}, // 6:7: t1
	{0x22, 134, 139, 138, 113 /* prev */ }, // 6:8: t2
	{0x22, 138, 144, 142, 139}, // 6:9: t3
	{0x33, 162, 164, 168, 166, 165, 163}, // 7:0: t4
	{0x33, 165, 170, 172, 168, 167, 169}, // 7:1: t5
	{0x22, 167, 173, 170, 171}, // 7:2: t6
	{0x22, 171, 155, 176 /* next */ , 173}, // 7:3: t7
	{0x22, 169, 174, 172, 175}, // 7:4: t8
	{0x22, 175, 157, 178 /* next */ , 174}, // 7:5: t9
	{0x22, 154, 159, 158, 133 /* prev */ }, // 7:6: t0
	{0x22, 158, 163, 159, 162}, // 7:7: t1
	{0x22, 156, 161, 160, 135 /* prev */ }, // 7:8: t2
	{0x22, 160, 166, 164, 161}, // 7:9: t3
	{0x33, 184, 186, 190, 188, 187, 185}, // 8:0: t4
	{0x33, 187, 192, 194, 190, 189, 191}, // 8:1: t5
	{0x22, 189, 195, 192, 193}, // 8:2: t6
	{0x22, 193, 177, 198 /* next */ , 195}, // 8:3: t7
	{0x22, 191, 196, 194, 197}, // 8:4: t8
	{0x22, 197, 179, 200 /* next */ , 196}, // 8:5: t9
	{0x22, 176, 181, 180, 155 /* prev */ }, // 8:6: t0
	{0x22, 180, 185, 181, 184}, // 8:7: t1
	{0x22, 178, 183, 182, 157 /* prev */ }, // 8:8: t2
	{0x22, 182, 188, 186, 183}, // 8:9: t3
	{0x33, 206, 208, 212, 210, 209, 207}, // 9:0: t4
	{0x33, 209, 214, 216, 212, 211, 213}, // 9:1: t5
	{0x22, 211, 217, 214, 215}, // 9:2: t6
	{0x22, 215, 199, 220 /* next */ , 217}, // 9:3: t7
	{0x22, 213, 218, 216, 219}, // 9:4: t8
	{0x22, 219, 201, 222 /* next */ , 218}, // 9:5: t9
	{0x22, 198, 203, 202, 177 /* prev */ }, // 9:6: t0
	{0x22, 202, 207, 203, 206}, // 9:7: t1
	{0x22, 200, 205, 204, 179 /* prev */ }, // 9:8: t2
	{0x22, 204, 210, 208, 205}, // 9:9: t3
	{0x33, 228, 230, 234, 232, 231, 229}, // 10:0: t4
	{0x33, 231, 236, 238, 234, 233, 235}, // 10:1: t5
	{0x22, 233, 239, 236, 237}, // 10:2: t6
	{0x22, 237, 221, 242 /* next */ , 239}, // 10:3: t7
	{0x22, 235, 240, 238, 241}, // 10:4: t8
	{0x22, 241, 223, 244 /* next */ , 240}, // 10:5: t9
	{0x22, 220, 225, 224, 199 /* prev */ }, // 10:6: t0
	{0x22, 224, 229, 225, 228}, // 10:7: t1
	{0x22, 222, 227, 226, 201 /* prev */ }, // 10:8: t2
	{0x22, 226, 232, 230, 227}, // 10:9: t3
	{0x33, 250, 252, 256, 254, 253, 251}, // 11:0: t4
	{0x33, 253, 258, 260, 256, 255, 257}, // 11:1: t5
	{0x22, 255, 261, 258, 259}, // 11:2: t6
	{0x22, 259, 243, 264 /* next */ , 261}, // 11:3: t7
	{0x22, 257, 262, 260, 263}, // 11:4: t8
	{0x22, 263, 245, 266 /* next */ , 262}, // 11:5: t9
	{0x22, 242, 247, 246, 221 /* prev */ }, // 11:6: t0
	{0x22, 246, 251, 247, 250}, // 11:7: t1
	{0x22, 244, 249, 248, 223 /* prev */ }, // 11:8: t2
	{0x22, 248, 254, 252, 249}, // 11:9: t3
	{0x33, 272, 274, 278, 276, 275, 273}, // 12:0: t4
	{0x33, 275, 280, 282, 278, 277, 279}, // 12:1: t5
	{0x22, 277, 283, 280, 281}, // 12:2: t6
	{0x22, 281, 265, 286 /* next */ , 283}, // 12:3: t7
	{0x22, 279, 284, 282, 285}, // 12:4: t8
	{0x22, 285, 267, 288 /* next */ , 284}, // 12:5: t9
	{0x22, 264, 269, 268, 243 /* prev */ }, // 12:6: t0
	{0x22, 268, 273, 269, 272}, // 12:7: t1
	{0x22, 266, 271, 270, 245 /* prev */ }, // 12:8: t2
	{0x22, 270, 276, 274, 271}, // 12:9: t3
	{0x33, 294, 296, 300, 298, 297, 295}, // 13:0: t4
	{0x33, 297, 302, 304, 300, 299, 301}, // 13:1: t5
	{0x22, 299, 305, 302, 303}, // 13:2: t6
	{0x22, 303, 287, 308 /* next */ , 305}, // 13:3: t7
	{0x22, 301, 306, 304, 307}, // 13:4: t8
	{0x22, 307, 289, 310 /* next */ , 306}, // 13:5: t9
	{0x22, 286, 291, 290, 265 /* prev */ }, // 13:6: t0
	{0x22, 290, 295, 291, 294}, // 13:7: t1
	{0x22, 288, 293, 292, 267 /* prev */ }, // 13:8: t2
	{0x22, 292, 298, 296, 293}, // 13:9: t3
	{0x33, 316, 318, 322, 320, 319, 317}, // 14:0: t4
	{0x33, 319, 324, 326, 322, 321, 323}, // 14:1: t5
	{0x22, 321, 327, 324, 325}, // 14:2: t6
	{0x22, 325, 309, 330 /* next */ , 327}, // 14:3: t7
	{0x22, 323, 328, 326, 329}, // 14:4: t8
	{0x22, 329, 311, 332 /* next */ , 328}, // 14:5: t9
	{0x22, 308, 313, 312, 287 /* prev */ }, // 14:6: t0
	{0x22, 312, 317, 313, 316}, // 14:7: t1
	{0x22, 310, 315, 314, 289 /* prev */ }, // 14:8: t2
	{0x22, 314, 320, 318, 315}, // 14:9: t3
	{0x33, 338, 340, 344, 342, 341, 339}, // 15:0: t4
	{0x33, 341, 346, 348, 344, 343, 345}, // 15:1: t5
	{0x22, 343, 349, 346, 347}, // 15:2: t6
	{0x22, 347, 331, 352 /* next */ , 349}, // 15:3: t7
	{0x22, 345, 350, 348, 351}, // 15:4: t8
	{0x22, 351, 333, 354 /* next */ , 350}, // 15:5: t9
	{0x22, 330, 335, 334, 309 /* prev */ }, // 15:6: t0
	{0x22, 334, 339, 335, 338}, // 15:7: t1
	{0x22, 332, 337, 336, 311 /* prev */ }, // 15:8: t2
	{0x22, 336, 342, 340, 337}, // 15:9: t3
	{0x33, 360, 362, 366, 364, 363, 361}, // 16:0: t4
	{0x33, 363, 368, 370, 366, 365, 367}, // 16:1: t5
	{0x22, 365, 371, 368, 369}, // 16:2: t6
	{0x22, 369, 353, 374 /* next */ , 371}, // 16:3: t7
	{0x22, 367, 372, 370, 373}, // 16:4: t8
	{0x22, 373, 355, 376 /* next */ , 372}, // 16:5: t9
	{0x22, 352, 357, 356, 331 /* prev */ }, // 16:6: t0
	{0x22, 356, 361, 357, 360}, // 16:7: t1
	{0x22, 354, 359, 358, 333 /* prev */ }, // 16:8: t2
	{0x22, 358, 364, 362, 359}, // 16:9: t3
	{0x33, 382, 384, 388, 386, 385, 383}, // 17:0: t4
	{0x33, 385, 390, 392, 388, 387, 389}, // 17:1: t5
	{0x22, 387, 393, 390, 391}, // 17:2: t6
	{0x22, 391, 375, 396 /* next */ , 393}, // 17:3: t7
	{0x22, 389, 394, 392, 395}, // 17:4: t8
	{0x22, 395, 377, 398 /* next */ , 394}, // 17:5: t9
	{0x22, 374, 379, 378, 353 /* prev */ }, // 17:6: t0
	{0x22, 378, 383, 379, 382}, // 17:7: t1
	{0x22, 376, 381, 380, 355 /* prev */ }, // 17:8: t2
	{0x22, 380, 386, 384, 381}, // 17:9: t3
	{0x33, 404, 406, 410, 408, 407, 405}, // 18:0: t4
	{0x33, 407, 412, 414, 410, 409, 411}, // 18:1: t5
	{0x22, 409, 415, 412, 413}, // 18:2: t6
	{0x22, 413, 397, 418 /* next */ , 415}, // 18:3: t7
	{0x22, 411, 416, 414, 417}, // 18:4: t8
	{0x22, 417, 399, 420 /* next */ , 416}, // 18:5: t9
	{0x22, 396, 401, 400, 375 /* prev */ }, // 18:6: t0
	{0x22, 400, 405, 401, 404}, // 18:7: t1
	{0x22, 398, 403, 402, 377 /* prev */ }, // 18:8: t2
	{0x22, 402, 408, 406, 403}, // 18:9: t3
	{0x33, 426, 428, 432, 430, 429, 427}, // 19:0: t4
	{0x33, 429, 434, 436, 432, 431, 433}, // 19:1: t5
	{0x22, 431, 437, 434, 435}, // 19:2: t6
	{0x22, 435, 419, 440 /* next */ , 437}, // 19:3: t7
	{0x22, 433, 438, 436, 439}, // 19:4: t8
	{0x22, 439, 421, 442 /* next */ , 438}, // 19:5: t9
	{0x22, 418, 423, 422, 397 /* prev */ }, // 19:6: t0
	{0x22, 422, 427, 423, 426}, // 19:7: t1
	{0x22, 420, 425, 424, 399 /* prev */ }, // 19:8: t2
	{0x22, 424, 430, 428, 425}, // 19:9: t3
	{0x33, 448, 450, 454, 452, 451, 449}, // 20:0: t4
	{0x33, 451, 456, 458, 454, 453, 455}, // 20:1: t5
	{0x22, 453, 459, 456, 457}, // 20:2: t6
	{0x22, 457, 441, 462 /* next */ , 459}, // 20:3: t7
	{0x22, 455, 460, 458, 461}, // 20:4: t8
	{0x22, 461, 443, 464 /* next */ , 460}, // 20:5: t9
	{0x22, 440, 445, 444, 419 /* prev */ }, // 20:6: t0
	{0x22, 444, 449, 445, 448}, // 20:7: t1
	{0x22, 442, 447, 446, 421 /* prev */ }, // 20:8: t2
	{0x22, 446, 452, 450, 447}, // 20:9: t3
	{0x33, 470, 472, 476, 474, 473, 471}, // 21:0: t4
	{0x33, 473, 478, 480, 476, 475, 477}, // 21:1: t5
	{0x22, 475, 481, 478, 479}, // 21:2: t6
	{0x22, 479, 463, 484 /* next */ , 481}, // 21:3: t7
	{0x22, 477, 482, 480, 483}, // 21:4: t8
	{0x22, 483, 465, 486 /* next */ , 482}, // 21:5: t9
	{0x22, 462, 467, 466, 441 /* prev */ }, // 21:6: t0
	{0x22, 466, 471, 467, 470}, // 21:7: t1
	{0x22, 464, 469, 468, 443 /* prev */ }, // 21:8: t2
	{0x22, 468, 474, 472, 469}, // 21:9: t3
	{0x33, 492, 494, 498, 496, 495, 493}, // 22:0: t4
	{0x33, 495, 500, 502, 498, 497, 499}, // 22:1: t5
	{0x22, 497, 503, 500, 501}, // 22:2: t6
	{0x22, 501, 485, 506 /* next */ , 503}, // 22:3: t7
	{0x22, 499, 504, 502, 505}, // 22:4: t8
	{0x22, 505, 487, 508 /* next */ , 504}, // 22:5: t9
	{0x22, 484, 489, 488, 463 /* prev */ }, // 22:6: t0
	{0x22, 488, 493, 489, 492}, // 22:7: t1
	{0x22, 486, 491, 490, 465 /* prev */ }, // 22:8: t2
	{0x22, 490, 496, 494, 491}, // 22:9: t3
	{0x33, 514, 516, 520, 518, 517, 515}, // 23:0: t4
	{0x33, 517, 522, 524, 520, 519, 521}, // 23:1: t5
	{0x22, 519, 525, 522, 523}, // 23:2: t6
	{0x22, 523, 507, 528 /* next */ , 525}, // 23:3: t7
	{0x22, 521, 526, 524, 527}, // 23:4: t8
	{0x22, 527, 509, 530 /* next */ , 526}, // 23:5: t9
	{0x22, 506, 511, 510, 485 /* prev */ }, // 23:6: t0
	{0x22, 510, 515, 511, 514}, // 23:7: t1
	{0x22, 508, 513, 512, 487 /* prev */ }, // 23:8: t2
	{0x22, 512, 518, 516, 513}, // 23:9: t3
	{0x33, 536, 538, 542, 540, 539, 537}, // 24:0: t4
	{0x33, 539, 544, 546, 542, 541, 543}, // 24:1: t5
	{0x22, 541, 547, 544, 545}, // 24:2: t6
	{0x22, 545, 529, 550 /* next */ , 547}, // 24:3: t7
	{0x22, 543, 548, 546, 549}, // 24:4: t8
	{0x22, 549, 531, 552 /* next */ , 548}, // 24:5: t9
	{0x22, 528, 533, 532, 507 /* prev */ }, // 24:6: t0
	{0x22, 532, 537, 533, 536}, // 24:7: t1
	{0x22, 530, 535, 534, 509 /* prev */ }, // 24:8: t2
	{0x22, 534, 540, 538, 535}, // 24:9: t3
	{0x33, 558, 560, 564, 562, 561, 559}, // 25:0: t4
	{0x33, 561, 566, 568, 564, 563, 565}, // 25:1: t5
	{0x22, 563, 569, 566, 567}, // 25:2: t6
	{0x22, 567, 551, 572 /* next */ , 569}, // 25:3: t7
	{0x22, 565, 570, 568, 571}, // 25:4: t8
	{0x22, 571, 553, 574 /* next */ , 570}, // 25:5: t9
	{0x22, 550, 555, 554, 529 /* prev */ }, // 25:6: t0
	{0x22, 554, 559, 555, 558}, // 25:7: t1
	{0x22, 552, 557, 556, 531 /* prev */ }, // 25:8: t2
	{0x22, 556, 562, 560, 557}, // 25:9: t3
	{0x33, 580, 582, 586, 584, 583, 581}, // 26:0: t4
	{0x33, 583, 588, 590, 586, 585, 587}, // 26:1: t5
	{0x22, 585, 591, 588, 589}, // 26:2: t6
	{0x22, 589, 573, 594 /* next */ , 591}, // 26:3: t7
	{0x22, 587, 592, 590, 593}, // 26:4: t8
	{0x22, 593, 575, 596 /* next */ , 592}, // 26:5: t9
	{0x22, 572, 577, 576, 551 /* prev */ }, // 26:6: t0
	{0x22, 576, 581, 577, 580}, // 26:7: t1
	{0x22, 574, 579, 578, 553 /* prev */ }, // 26:8: t2
	{0x22, 578, 584, 582, 579}, // 26:9: t3
	{0x33, 602, 604, 608, 606, 605, 603}, // 27:0: t4
	{0x33, 605, 610, 612, 608, 607, 609}, // 27:1: t5
	{0x22, 607, 613, 610, 611}, // 27:2: t6
	{0x22, 611, 595, 616 /* next */ , 613}, // 27:3: t7
	{0x22, 609, 614, 612, 615}, // 27:4: t8
	{0x22, 615, 597, 618 /* next */ , 614}, // 27:5: t9
	{0x22, 594, 599, 598, 573 /* prev */ }, // 27:6: t0
	{0x22, 598, 603, 599, 602}, // 27:7: t1
	{0x22, 596, 601, 600, 575 /* prev */ }, // 27:8: t2
	{0x22, 600, 606, 604, 601}, // 27:9: t3
	{0x33, 624, 626, 630, 628, 627, 625}, // 28:0: t4
	{0x33, 627, 632, 634, 630, 629, 631}, // 28:1: t5
	{0x22, 629, 635, 632, 633}, // 28:2: t6
	{0x22, 633, 617, 638 /* next */ , 635}, // 28:3: t7
	{0x22, 631, 636, 634, 637}, // 28:4: t8
	{0x22, 637, 619, 640 /* next */ , 636}, // 28:5: t9
	{0x22, 616, 621, 620, 595 /* prev */ }, // 28:6: t0
	{0x22, 620, 625, 621, 624}, // 28:7: t1
	{0x22, 618, 623, 622, 597 /* prev */ }, // 28:8: t2
	{0x22, 622, 628, 626, 623}, // 28:9: t3
	{0x33, 646, 648, 652, 650, 649, 647}, // 29:0: t4
	{0x33, 649, 654, 656, 652, 651, 653}, // 29:1: t5
	{0x22, 651, 657, 654, 655}, // 29:2: t6
	{0x22, 655, 639, 660 /* next */ , 657}, // 29:3: t7
	{0x22, 653, 658, 656, 659}, // 29:4: t8
	{0x22, 659, 641, 662 /* next */ , 658}, // 29:5: t9
	{0x22, 638, 643, 642, 617 /* prev */ }, // 29:6: t0
	{0x22, 642, 647, 643, 646}, // 29:7: t1
	{0x22, 640, 645, 644, 619 /* prev */ }, // 29:8: t2
	{0x22, 644, 650, 648, 645}, // 29:9: t3
	{0x33, 668, 670, 674, 672, 671, 669}, // 30:0: t4
	{0x33, 671, 676, 678, 674, 673, 675}, // 30:1: t5
	{0x22, 673, 679, 676, 677}, // 30:2: t6
	{0x22, 677, 661, 682 /* next */ , 679}, // 30:3: t7
	{0x22, 675, 680, 678, 681}, // 30:4: t8
	{0x22, 681, 663, 684 /* next */ , 680}, // 30:5: t9
	{0x22, 660, 665, 664, 639 /* prev */ }, // 30:6: t0
	{0x22, 664, 669, 665, 668}, // 30:7: t1
	{0x22, 662, 667, 666, 641 /* prev */ }, // 30:8: t2
	{0x22, 666, 672, 670, 667}, // 30:9: t3
	{0x33, 690, 692, 696, 694, 693, 691}, // 31:0: t4
	{0x33, 693, 698, 700, 696, 695, 697}, // 31:1: t5
	{0x22, 695, 701, 698, 699}, // 31:2: t6
	{0x22, 699, 683, 704 /* next */ , 701}, // 31:3: t7
	{0x22, 697, 702, 700, 703}, // 31:4: t8
	{0x22, 703, 685, 706 /* next */ , 702}, // 31:5: t9
	{0x22, 682, 687, 686, 661 /* prev */ }, // 31:6: t0
	{0x22, 686, 691, 687, 690}, // 31:7: t1
	{0x22, 684, 689, 688, 663 /* prev */ }, // 31:8: t2
	{0x22, 688, 694, 692, 689}, // 31:9: t3
	{0x33, 712, 714, 718, 716, 715, 713}, // 32:0: t4
	{0x33, 715, 720, 722, 718, 717, 719}, // 32:1: t5
	{0x22, 717, 723, 720, 721}, // 32:2: t6
	{0x22, 721, 705, 726 /* next */ , 723}, // 32:3: t7
	{0x22, 719, 724, 722, 725}, // 32:4: t8
	{0x22, 725, 707, 728 /* next */ , 724}, // 32:5: t9
	{0x22, 704, 709, 708, 683 /* prev */ }, // 32:6: t0
	{0x22, 708, 713, 709, 712}, // 32:7: t1
	{0x22, 706, 711, 710, 685 /* prev */ }, // 32:8: t2
	{0x22, 710, 716, 714, 711}, // 32:9: t3
	{0x33, 734, 736, 740, 738, 737, 735}, // 33:0: t4
	{0x33, 737, 742, 744, 740, 739, 741}, // 33:1: t5
	{0x22, 739, 745, 742, 743}, // 33:2: t6
	{0x22, 743, 727, 748 /* next */ , 745}, // 33:3: t7
	{0x22, 741, 746, 744, 747}, // 33:4: t8
	{0x22, 747, 729, 750 /* next */ , 746}, // 33:5: t9
	{0x22, 726, 731, 730, 705 /* prev */ }, // 33:6: t0
	{0x22, 730, 735, 731, 734}, // 33:7: t1
	{0x22, 728, 733, 732, 707 /* prev */ }, // 33:8: t2
	{0x22, 732, 738, 736, 733}, // 33:9: t3
	{0x33, 756, 758, 762, 760, 759, 757}, // 34:0: t4
	{0x33, 759, 764, 766, 762, 761, 763}, // 34:1: t5
	{0x22, 761, 767, 764, 765}, // 34:2: t6
	{0x22, 765, 749, 770 /* next */ , 767}, // 34:3: t7
	{0x22, 763, 768, 766, 769}, // 34:4: t8
	{0x22, 769, 751, 772 /* next */ , 768}, // 34:5: t9
	{0x22, 748, 753, 752, 727 /* prev */ }, // 34:6: t0
	{0x22, 752, 757, 753, 756}, // 34:7: t1
	{0x22, 750, 755, 754, 729 /* prev */ }, // 34:8: t2
	{0x22, 754, 760, 758, 755}, // 34:9: t3
	{0x33, 778, 780, 784, 782, 781, 779}, // 35:0: t4
	{0x33, 781, 786, 788, 784, 783, 785}, // 35:1: t5
	{0x22, 783, 789, 786, 787}, // 35:2: t6
	{0x22, 787, 771, 792 /* next */ , 789}, // 35:3: t7
	{0x22, 785, 790, 788, 791}, // 35:4: t8
	{0x22, 791, 773, 794 /* next */ , 790}, // 35:5: t9
	{0x22, 770, 775, 774, 749 /* prev */ }, // 35:6: t0
	{0x22, 774, 779, 775, 778}, // 35:7: t1
	{0x22, 772, 777, 776, 751 /* prev */ }, // 35:8: t2
	{0x22, 776, 782, 780, 777}, // 35:9: t3
	{0x33, 800, 802, 806, 804, 803, 801}, // 36:0: t4
	{0x33, 803, 808, 810, 806, 805, 807}, // 36:1: t5
	{0x22, 805, 811, 808, 809}, // 36:2: t6
	{0x22, 809, 793, 814 /* next */ , 811}, // 36:3: t7
	{0x22, 807, 812, 810, 813}, // 36:4: t8
	{0x22, 813, 795, 816 /* next */ , 812}, // 36:5: t9
	{0x22, 792, 797, 796, 771 /* prev */ }, // 36:6: t0
	{0x22, 796, 801, 797, 800}, // 36:7: t1
	{0x22, 794, 799, 798, 773 /* prev */ }, // 36:8: t2
	{0x22, 798, 804, 802, 799}, // 36:9: t3
	{0x33, 822, 824, 828, 826, 825, 823}, // 37:0: t4
	{0x33, 825, 830, 832, 828, 827, 829}, // 37:1: t5
	{0x22, 827, 833, 830, 831}, // 37:2: t6
	{0x22, 831, 815, 836 /* next */ , 833}, // 37:3: t7
	{0x22, 829, 834, 832, 835}, // 37:4: t8
	{0x22, 835, 817, 838 /* next */ , 834}, // 37:5: t9
	{0x22, 814, 819, 818, 793 /* prev */ }, // 37:6: t0
	{0x22, 818, 823, 819, 822}, // 37:7: t1
	{0x22, 816, 821, 820, 795 /* prev */ }, // 37:8: t2
	{0x22, 820, 826, 824, 821}, // 37:9: t3
	{0x33, 844, 846, 850, 848, 847, 845}, // 38:0: t4
	{0x33, 847, 852, 854, 850, 849, 851}, // 38:1: t5
	{0x22, 849, 855, 852, 853}, // 38:2: t6
	{0x22, 853, 837, 858 /* next */ , 855}, // 38:3: t7
	{0x22, 851, 856, 854, 857}, // 38:4: t8
	{0x22, 857, 839, 860 /* next */ , 856}, // 38:5: t9
	{0x22, 836, 841, 840, 815 /* prev */ }, // 38:6: t0
	{0x22, 840, 845, 841, 844}, // 38:7: t1
	{0x22, 838, 843, 842, 817 /* prev */ }, // 38:8: t2
	{0x22, 842, 848, 846, 843}, // 38:9: t3
	{0x33, 866, 868, 872, 870, 869, 867}, // 39:0: t4
	{0x33, 869, 874, 876, 872, 871, 873}, // 39:1: t5
	{0x22, 871, 877, 874, 875}, // 39:2: t6
	{0x22, 875, 859, 880 /* next */ , 877}, // 39:3: t7
	{0x22, 873, 878, 876, 879}, // 39:4: t8
	{0x22, 879, 861, 882 /* next */ , 878}, // 39:5: t9
	{0x22, 858, 863, 862, 837 /* prev */ }, // 39:6: t0
	{0x22, 862, 867, 863, 866}, // 39:7: t1
	{0x22, 860, 865, 864, 839 /* prev */ }, // 39:8: t2
	{0x22, 864, 870, 868, 865}, // 39:9: t3
	{0x33, 888, 890, 894, 892, 891, 889}, // 40:0: t4
	{0x33, 891, 896, 898, 894, 893, 895}, // 40:1: t5
	{0x22, 893, 899, 896, 897}, // 40:2: t6
	{0x22, 897, 881, 902 /* next */ , 899}, // 40:3: t7
	{0x22, 895, 900, 898, 901}, // 40:4: t8
	{0x22, 901, 883, 904 /* next */ , 900}, // 40:5: t9
	{0x22, 880, 885, 884, 859 /* prev */ }, // 40:6: t0
	{0x22, 884, 889, 885, 888}, // 40:7: t1
	{0x22, 882, 887, 886, 861 /* prev */ }, // 40:8: t2
	{0x22, 886, 892, 890, 887}, // 40:9: t3
	{0x33, 910, 912, 916, 914, 913, 911}, // 41:0: t4
	{0x33, 913, 918, 920, 916, 915, 917}, // 41:1: t5
	{0x22, 915, 921, 918, 919}, // 41:2: t6
	{0x22, 919, 903, 924 /* next */ , 921}, // 41:3: t7
	{0x22, 917, 922, 920, 923}, // 41:4: t8
	{0x22, 923, 905, 926 /* next */ , 922}, // 41:5: t9
	{0x22, 902, 907, 906, 881 /* prev */ }, // 41:6: t0
	{0x22, 906, 911, 907, 910}, // 41:7: t1
	{0x22, 904, 909, 908, 883 /* prev */ }, // 41:8: t2
	{0x22, 908, 914, 912, 909}, // 41:9: t3
	{0x33, 932, 934, 938, 936, 935, 933}, // 42:0: t4
	{0x33, 935, 940, 942, 938, 937, 939}, // 42:1: t5
	{0x22, 937, 943, 940, 941}, // 42:2: t6
	{0x22, 941, 925, 946 /* next */ , 943}, // 42:3: t7
	{0x22, 939, 944, 942, 945}, // 42:4: t8
	{0x22, 945, 927, 948 /* next */ , 944}, // 42:5: t9
	{0x22, 924, 929, 928, 903 /* prev */ }, // 42:6: t0
	{0x22, 928, 933, 929, 932}, // 42:7: t1
	{0x22, 926, 931, 930, 905 /* prev */ }, // 42:8: t2
	{0x22, 930, 936, 934, 931}, // 42:9: t3
	{0x33, 954, 956, 960, 958, 957, 955}, // 43:0: t4
	{0x33, 957, 962, 964, 960, 959, 961}, // 43:1: t5
	{0x22, 959, 965, 962, 963}, // 43:2: t6
	{0x22, 963, 947, 968 /* next */ , 965}, // 43:3: t7
	{0x22, 961, 966, 964, 967}, // 43:4: t8
	{0x22, 967, 949, 970 /* next */ , 966}, // 43:5: t9
	{0x22, 946, 951, 950, 925 /* prev */ }, // 43:6: t0
	{0x22, 950, 955, 951, 954}, // 43:7: t1
	{0x22, 948, 953, 952, 927 /* prev */ }, // 43:8: t2
	{0x22, 952, 958, 956, 953}, // 43:9: t3
	{0x33, 976, 978, 982, 980, 979, 977}, // 44:0: t4
	{0x33, 979, 984, 986, 982, 981, 983}, // 44:1: t5
	{0x22, 981, 987, 984, 985}, // 44:2: t6
	{0x22, 985, 969, 990 /* next */ , 987}, // 44:3: t7
	{0x22, 983, 988, 986, 989}, // 44:4: t8
	{0x22, 989, 971, 992 /* next */ , 988}, // 44:5: t9
	{0x22, 968, 973, 972, 947 /* prev */ }, // 44:6: t0
	{0x22, 972, 977, 973, 976}, // 44:7: t1
	{0x22, 970, 975, 974, 949 /* prev */ }, // 44:8: t2
	{0x22, 974, 980, 978, 975}, // 44:9: t3
	{0x33, 998, 1000, 1004, 1002, 1001, 999}, // 45:0: t4
	{0x33, 1001, 1006, 1008, 1004, 1003, 1005}, // 45:1: t5
	{0x22, 1003, 1009, 1006, 1007}, // 45:2: t6
	{0x22, 1007, 991, 1014 /* out */ , 1009}, // 45:3: t7
	{0x22, 1005, 1010, 1008, 1011}, // 45:4: t8
	{0x22, 1011, 993, 1015 /* out */ , 1010}, // 45:5: t9
	{0x22, 990, 995, 994, 969 /* prev */ }, // 45:6: t0
	{0x22, 994, 999, 995, 998}, // 45:7: t1
	{0x22, 992, 997, 996, 971 /* prev */ }, // 45:8: t2
	{0x22, 996, 1002, 1000, 997} // 45:9: t3
};

#endif
