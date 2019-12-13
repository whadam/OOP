#include "fold_block.h"
#include "block.h"
#include "array_2d.h"

fold_block::fold_block(int c1, int c2, int c3) {
	this->v.emplace_back(new block(c1));
	this->v.emplace_back(new block(c2));
	this->v.emplace_back(new block(c3));
	this->v[0]->set_location(0, 2);
	this->v[1]->set_location(1, 1);
	this->v[2]->set_location(1, 2); // basis

	this->rotate_status = 0;
}

void fold_block::rotate() {
	int temp;

	switch (rotate_status % 4) {
	case 0:
		if (!this->v[2]->can_right()) {
			return;
		}
		this->v[1]->set_location(this->v[1]->get_x(), this->v[1]->get_y() + 2);
		temp = this->v[0]->get_color();
		this->v[0]->set_color(this->v[1]->get_color());
		this->v[1]->set_color(temp);
		break;
	case 1:
		if (!this->v[2]->can_down()) {
			return;
		}
		this->v[0]->set_location(this->v[0]->get_x() + 2, this->v[0]->get_y());
		temp = this->v[0]->get_color();
		this->v[0]->set_color(this->v[1]->get_color());
		this->v[1]->set_color(temp);
		break;
	case 2:
		if (!this->v[2]->can_left()) {
			return;
		}
		this->v[1]->set_location(this->v[1]->get_x(), this->v[1]->get_y() - 2);
		temp = this->v[0]->get_color();
		this->v[0]->set_color(this->v[1]->get_color());
		this->v[1]->set_color(temp);
		break;
	case 3:
		this->v[0]->set_location(this->v[0]->get_x() - 2, this->v[0]->get_y());
		temp = this->v[0]->get_color();
		this->v[0]->set_color(this->v[1]->get_color());
		this->v[1]->set_color(temp);
	}

	rotate_status++;
}

bool fold_block::can_left() {
	switch (rotate_status % 4) {
	case 0:
		if (this->v[1]->can_left()) {
			return true;
		}
		break;
	case 1:
		if (this->v[2]->can_left()) {
			return true;
		}
		break;
	case 2:
		if (this->v[0]->can_left()) {
			return true;
		}
		break;
	case 3:
		if (this->v[0]->can_left() && this->v[1]->can_left()) {
			return true;
		}
	}
	return false;
}

bool fold_block::can_right() {
	switch (rotate_status % 4) {
	case 0:
		if (this->v[2]->can_right()) {
			return true;
		}
		break;
	case 1:
		if (this->v[1]->can_right()) {
			return true;
		}
		break;
	case 2:
		if (this->v[0]->can_right() && this->v[1]->can_right()) {
			return true;
		}
		break;
	case 3:
		if (this->v[0]->can_right()) {
			return true;
		}
	}
	return false;
}

bool fold_block::can_down() {
	switch (rotate_status % 4) {
	case 0:
	case 1:
		if (this->v[1]->can_down() && this->v[2]->can_down()) {
			return true;
		}
		break;
	case 2:
	case 3:
		if (this->v[0]->can_down() && this->v[1]->can_down()) {
			return true;
		}
	}

	return false;
}

bool fold_block::down() {
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
		switch (rotate_status % 4) {
		case 0:
		case 1:
			while (this->v[1]->can_down()) {
				this->v[1]->down();
			}
			while (this->v[2]->can_down()) {
				this->v[2]->down();
			}
			array_2d::insert(this->v[1]->get_x(), this->v[1]->get_y(), this->v[1]);
			array_2d::insert(this->v[2]->get_x(), this->v[2]->get_y(), this->v[2]);
			while (this->v[0]->can_down()) {
				this->v[0]->down();
			}
			array_2d::insert(this->v[0]->get_x(), this->v[0]->get_y(), this->v[0]);
			break;
		case 2:
		case 3:
			while (this->v[1]->can_down()) {
				this->v[1]->down();
			}
			while (this->v[0]->can_down()) {
				this->v[0]->down();
			}
			array_2d::insert(this->v[1]->get_x(), this->v[1]->get_y(), this->v[1]);
			array_2d::insert(this->v[0]->get_x(), this->v[0]->get_y(), this->v[0]);
			while (this->v[2]->can_down()) {
				this->v[2]->down();
			}
			array_2d::insert(this->v[2]->get_x(), this->v[2]->get_y(), this->v[2]);
		}
		return false;
	}
}
