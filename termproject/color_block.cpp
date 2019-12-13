#include "color_block.h"
#include "block.h"
#include "array_2d.h"

color_block::color_block(block* b) {
	this->s.insert(b);
}

void color_block::insert(set<block*> s) {
	for (auto& i : s) {
		this->s.insert(i);
	}
}

void color_block::insert(block* b) {
	this->s.insert(b);
}

set<block*> color_block::get_set() {
	return this->s;
}

int color_block::get_set_size() {
	return this->s.size();
}

void color_block::explosion() {
	for (auto& i : this->s) {
		if (array_2d::get_block(i->get_x(), i->get_y()-1) != nullptr &&	// left
			array_2d::get_block(i->get_x(), i->get_y()-1)->get_color() == 3) {
			array_2d::get_block(i->get_x(), i->get_y()-1)->~block();
		}
		if (array_2d::get_block(i->get_x(), i->get_y()+1) != nullptr &&	// right
			array_2d::get_block(i->get_x(), i->get_y()+1)->get_color() == 3) {
			array_2d::get_block(i->get_x(), i->get_y()+1)->~block();
		}
		if (array_2d::get_block(i->get_x()-1, i->get_y()) != nullptr &&	// up
			array_2d::get_block(i->get_x()-1, i->get_y())->get_color() == 3) {
			array_2d::get_block(i->get_x()-1, i->get_y())->~block();
		}
		if (array_2d::get_block(i->get_x()+1, i->get_y()) != nullptr &&	//down
			array_2d::get_block(i->get_x()+1, i->get_y())->get_color() == 3) {
			array_2d::get_block(i->get_x()+1, i->get_y())->~block();
		}
		i->~block();
	}
}
