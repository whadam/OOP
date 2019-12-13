#pragma once
#include "big_block.h"

class big_block;
class block;

class tree_block : public big_block {
private:
	int rotate_status;
public:
	tree_block(int c1, int c2, int c3);
	void rotate() override;
	bool can_left() override;
	bool can_right() override;
	bool can_down() override;
	bool down() override;
};