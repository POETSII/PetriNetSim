#ifndef _D_HHYPE_PINIT_H_
#define _D_HHYPE_PINIT_H_

#define PINIT_NAME "D_HHYPE"

// Places:
// 0: p0
// 1: p1a
// 2: p1
// 3: p2
// 4: p3
// 5: p4
// 6*: p5
// 7: p6
// 8: p7
// 9: p8
// 10: p9
// 11: p10
// 12: p12
// 13: p11
// 14: p14
// 15: p13
// 16*: p15
// 17*: p4a
// 18: p2a
// 19*: p0a
// 20: p5a
// 21*: p3a
// 22: prev_p1 (out)
// 23: prev_p3 (out)
// 24: next_p0 (out)
// 25: next_p2 (out)

// Initial marking: 
const uint8_t initPlaces[localPlaces] = {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 1};
const uint16_t tileInitPlaces = 22;

// Output mapping:
const OutMap tOutMap[outPlaces] = {
};

#endif
