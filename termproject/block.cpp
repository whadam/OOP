#include "block.h"
#include "array_2d.h"
#include "color_block.h"
block::block(int color) {
	this->color = color;
	this->x = -1;
	this->y = -1;
	this->group = nullptr;
}

block::~block() {
	array_2d::delete_block(this->x, this->y);
}


int block::get_color() {
	return this->color;
}

void block::set_color(int newColor) {
	this->color = newColor;
}

int block::get_x() {
	return this->x;
}

int block::get_y() {
	return this->y;
}

void block::set_group(color_block* newGroup) {
	this->group = newGroup;
}

color_block* block::get_group() {
	return this->group;
}

void block::set_location(int x, int y) {
	this->x = x;
	this->y = y;
}

bool block::can_left() {
	return array_2d::can_move(this->x, this->y - 1);
}

bool block::can_right() {
	return array_2d::can_move(this->x, this->y + 1);
}

bool block::can_down() {
	return array_2d::can_move(this->x + 1, this->y);
}

void block::left() {
	this->y--;
}

void block::right() {
	this->y++;
}

void block::down() {
	this->x++;
}

void block::down_all() {
	while (can_down()) {
		this->down();
	}
}

bool block::can_merge(block* b) {
	return !(b == nullptr ||	// block not exist
			this->color != b->get_color() ||	// different color
			this->get_group() == b->get_group());	// same group
}

bool block::can_explosion(block* b) {
	return false;
}

void block::merge(block* b) {
	if (this->can_merge(b)) {
		if (b->get_group() == nullptr) {
			b->set_group(this->group);
			this->group->insert(b);
		}
		else { // b != nullptr (has group)
			for (auto& i : b->get_group()->get_set()) {
				i->set_group(this->group);
				this->group->insert(i);
			}
		}
	}
}

void block::find_merge() {
	if (this->color == 3) {
		return;
	}
	if (this->group == nullptr) {
		this->group = new color_block(this);
	}

	this->merge(array_2d::get_block(this->x, this->y + 1)); // right
	this->merge(array_2d::get_block(this->x - 1, this->y)); // up

	array_2d::insert_explosion(this->get_group());
}
