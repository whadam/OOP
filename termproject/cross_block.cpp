#include "cross_block.h"
#include "block.h"
#include "array_2d.h"

cross_block::cross_block(int c1, int c2, int c3, int c4, int c5) {
    this->v.emplace_back(new block(c1));
    this->v.emplace_back(new block(c2));
    this->v.emplace_back(new block(c3));
    this->v.emplace_back(new block(c4));
    this->v.emplace_back(new block(c5));
    this->v[0]->set_location(2, 2);
    this->v[1]->set_location(1, 1);
    this->v[2]->set_location(1, 2);
    this->v[3]->set_location(1, 3);
    this->v[4]->set_location(0, 2);
}

void cross_block::rotate() {
	int temp = this->v[0]->get_color();
	this->v[0]->set_color(this->v[3]->get_color());
	this->v[3]->set_color(this->v[4]->get_color());
	this->v[4]->set_color(this->v[1]->get_color());
	this->v[1]->set_color(temp);
}

bool cross_block::can_left() {
	return this->v[0]->can_left() && this->v[1]->can_left();
}

bool cross_block::can_right() {
	return this->v[0]->can_right() && this->v[3]->can_right();
}

bool cross_block::can_down() {
	return this->v[0]->can_down() &&
		this->v[1]->can_down() &&
		this->v[3]->can_down();
}

bool cross_block::down() {
	for (auto& i : this->v) {
		array_2d::delete_block(i->get_x(), i->get_y());
	}
	if (this->can_down()) {
		for (auto& i : this->v) {
			i->down();
		}
		array_2d::insert(this->v);
		return true;
	}
	else {
		for (auto& i : this->v) {
			while (i->can_down()) {
				i->down();
			}
			array_2d::insert(i->get_x(), i->get_y(), i);
		}

		return false;
	}
}