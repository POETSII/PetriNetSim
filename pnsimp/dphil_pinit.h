#ifndef _DPHIL_PINIT_H_
#define _DPHIL_PINIT_H_

// Places:
// 0: ccw_before_put_left_fork
// 1*: ccw_left_hand_empty
// 2: before_put_right_fork
// 3*: left_hand_empty
// 4*: fork1_free
// 5: ordering
// 6: after_take_left_fork
// 7: eating
// 8*: thinking
// 9: after_take_right_fork
// 10: before_put_left_fork
// 11*: fork2_free
// 12*: right_hand_empty
// 13: cw_eating
// 14*: cw_thinking
// 15: cw_after_take_left_fork
// 16*: cw_right_hand_empty
// 17: cw_ordering
// 18: cw_before_put_right_fork
// 19: cw_after_take_right_fork
// 20: ccw_ordering (out)
// 21: ccw_after_take_left_fork (out)
// 22: cw_before_put_left_fork (out)

// Initial marking: 
const uint8_t initPlaces[localPlaces] = {0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 1, 1, 0, 1, 0, 1, 0, 0, 0};
const uint16_t tileInitPlaces = 20;

// Output mapping:
const OutMap tOutMap[outPlaces] = {
	{-1, 997}, // ccw_ordering to cw_ordering
	{-1, 995}, // ccw_after_take_left_fork to cw_after_take_left_fork
	{1, 0} // cw_before_put_left_fork to ccw_before_put_left_fork
};

#endif
