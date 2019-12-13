#pragma once
#include "big_block.h"

class big_block;
class block;

class cross_block : public big_block {
public:
	cross_block(int c1, int c2, int c3, int c4, int c5);
	void rotate() override;
	bool can_left() override;
	bool can_right() override;
	bool can_down() override;
	bool down() override;
};