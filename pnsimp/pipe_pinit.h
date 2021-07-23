#ifndef _PIPE_PINIT_H_
#define _PIPE_PINIT_H_

#define PINIT_NAME "PIPE"

// Places:
// 0*: p0
// 1: p1
// 2*: p2
// 3: p3
// 4: p4
// 5*: p5
// 6: p6
// 7*: p7
// 8*: p8
// 9: p9
// 10*: p10
// 11: p12
// 12: p11
// 13*: p14
// 14*: p13
// 15*: p16
// 16: p15
// 17: p18
// 18: p17
// 19*: p19
// 20*: p21
// 21: p20
// 22: prev_p1 (out)
// 23: prev_p3 (out)
// 24: next_p0 (out)
// 25: next_p2 (out)

// Initial marking: 
const uint8_t initPlaces[localPlaces] = {1, 0, 1, 0, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0};
const uint16_t tileInitPlaces = 22;

// Output mapping:
const OutMap tOutMap[outPlaces] = {
	{-1, 991}, // prev_p1 to p1
	{-1, 993}, // prev_p3 to p3
	{1, 0}, // next_p0 to p0
	{1, 2} // next_p2 to p2
};

#endif
