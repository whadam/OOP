#include "big_block.h"
#include "block.h"
#include "array_2d.h"

big_block::big_block() {
	this->v.clear();
}

big_block::~big_block() {}

void big_block::left() {
	if (this->can_left()) {
        for (auto& i : this->v) {
            i->left();
        }
	}
}

void big_block::right() {
	if (this->can_right()) {
        for (auto& i : this->v) {
            i->right();
        }
	}
}

bool big_block::down_all() {
	while (this->down());
	return false;
}

bool big_block::move(int input) {
	switch (input) {
	    case 97:	// a
			this->left();
			break;
	    case 115:	// s
			if (!this->down()) {
				return false;
			}
			break;
	    case 100:	// d
			this->right();
			break;
		case 101:	// e
			this->rotate();
			break;
	    case 120:	// x
			return this->down_all();
	}
	array_2d::insert(this->v);
	return true;
}
