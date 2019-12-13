#include "tree_block.h"
#include "block.h"
#include "array_2d.h"

tree_block::tree_block(int c1, int c2, int c3) {
    this->v.emplace_back(new block(c1));
    this->v.emplace_back(new block(c2));
    this->v.emplace_back(new block(c3));
    this->v[0]->set_location(0, 2);
    this->v[1]->set_location(1, 2);
    this->v[2]->set_location(2, 2);

	this->rotate_status = 0;
}

void tree_block::rotate() {
	if (this->v[1]->get_y() == 0 || this->v[1]->get_y() == 4) { // vertical, edge
		return;
	}
	if (rotate_status % 2 == 0) { // vertical
		if (!(this->v[1]->can_left() && this->v[1]->can_right())) {
			return;
		}
		if (this->v[0]->get_x() < this->v[2]->get_x()) {
			this->v[0]->set_location(this->v[0]->get_x() + 1, this->v[0]->get_y() + 1);
			this->v[2]->set_location(this->v[2]->get_x() - 1, this->v[2]->get_y() - 1);
			rotate_status++;
		}
		else {
			this->v[0]->set_location(this->v[0]->get_x() - 1, this->v[0]->get_y() - 1);
			this->v[2]->set_location(this->v[2]->get_x() + 1, this->v[2]->get_y() + 1);
			rotate_status++;
		}
	}
	else {	// horizontal
		if (!this->v[1]->can_down()) {
			return;
		}
		if (this->v[0]->get_y() > this->v[2]->get_y()) {
			this->v[0]->set_location(this->v[0]->get_x() + 1, this->v[0]->get_y() - 1);
			this->v[2]->set_location(this->v[2]->get_x() - 1, this->v[2]->get_y() + 1);
			rotate_status++;
		}
		else {
			this->v[0]->set_location(this->v[0]->get_x() - 1, this->v[0]->get_y() + 1);
			this->v[2]->set_location(this->v[2]->get_x() + 1, this->v[2]->get_y() - 1);
			rotate_status++;
		}
	}
}

bool tree_block::can_left() {
	if (rotate_status % 2 == 0) {	// vertical
		for (auto& i : this->v) {
			if (!i->can_left()) {
				return false;
			}
		}
		return true;
	}
	else {	// horizontal
		if (this->v[0]->get_y() > this->v[2]->get_y()) {
			return v[2]->can_left();
		}
		else if (this->v[0]->get_y() < this->v[2]->get_y()) {
			return v[0]->can_left();
		}
	}
}

bool tree_block::can_right() {
	if (rotate_status % 2 == 0) {	// vertical
		for (auto& i : this->v) {
			if (!i->can_right()) {
				return false;
			}
		}
		return true;
	}
	else {	// horizontal
		if (this->v[0]->get_y() > this->v[2]->get_y()) {
			return v[0]->can_right();
		}
		else if (this->v[0]->get_y() < this->v[2]->get_y()) {
			return v[2]->can_right();
		}
	}
}

bool tree_block::can_down() {
	if (rotate_status % 2 == 0) { // vertical
		if (this->v[0]->get_x() > this->v[2]->get_x()) {
			return this->v[0]->can_down();
		}
		else {
			return this->v[2]->can_down();
		}
	}
	else {	// horizontal
		for (auto& i : this->v) {
			if (! i->can_down()) {
				return false;
			}
		}
		return true;
	}
}

bool tree_block::down() {
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
		array_2d::insert(this->v);
		for (auto& i : this->v) {
			while (i->can_down()) {
				array_2d::delete_block(i->get_x(), i->get_y());
				i->down();
			}
			array_2d::insert(i->get_x(), i->get_y(), i);
		}

		return false;
	}
}
