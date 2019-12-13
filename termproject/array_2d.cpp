#include "array_2d.h"
#include <iostream>
#include "block.h"
#include "color_block.h"

block* array_2d::block_array[12][5];
set<color_block*> array_2d::explosion_s;
int array_2d::score = 0;

array_2d::array_2d() {
	for (auto & i : block_array) {
		for (auto & j : i) {
			j = nullptr;
		}
	}
}

bool array_2d::can_make(int type) {
	switch (type) {
	case 0:	// fold
		if (block_array[0][2] == nullptr &&
			block_array[1][1] == nullptr &&
			block_array[1][2] == nullptr) {
			return true;
		}
	case 1: // tree
		if (block_array[0][2] == nullptr &&
			block_array[1][2] == nullptr &&
			block_array[2][2] == nullptr) {
			return true;
		}
	case 2:	// cross
		if (block_array[0][2] == nullptr &&
			block_array[1][1] == nullptr &&
			block_array[1][2] == nullptr &&
			block_array[1][3] == nullptr &&
			block_array[2][2] == nullptr) {
			return true;
		}
	default:
		return false;
	}
}

void array_2d::delete_block(int x, int y) {
	block_array[x][y] = nullptr;
}

void array_2d::insert(vector<block*> v) {
	for (auto& i : v) {
		block_array[i->get_x()][i->get_y()] = i;
	}
}

void array_2d::insert(int x, int y, block* b) {
	block_array[x][y] = b;
}

block* array_2d::get_block(int x, int y) {
	if (x < 0 || y < 0 || x > 11 || y > 4) {
		return nullptr;
	}
	else {
		return block_array[x][y];
	}
}

bool array_2d::can_move(int x, int y) {
	if (x < 0 || y < 0 || x > 11 || y > 4) {
		return false;
	}
    return get_block(x, y) == nullptr;
}

void array_2d::print() {
    std::cout << "score : " << score << std::endl;
	for (auto & i : block_array) {
		for (auto & j : i) {
			if (j == nullptr) {
				std::cout << "\t";
			}
			else {
				switch (j->get_color()) {
				case 0:	// red
                    std::cout << 'R' << "\t";
					break;
				case 1:	// blue
                    std::cout << 'B' << "\t";
					break;
				case 2: // green
                    std::cout << 'G' << "\t";
					break;
				case 3: // gray
                    std::cout << 'g' << "\t";
					break;
				default:
                    std::cout << -1 << "\t";
				}
			}
		}
		std::cout << std::endl;
	}
	std::cout << "----------------------------------l" << std::endl;
}

void array_2d::insert_explosion(color_block* group) {
	if (explosion_s.find(group) == explosion_s.end()) { // not found
		explosion_s.insert(group);
	}
}

void array_2d::remove_explosion(color_block* group) {
	explosion_s.erase(group);
}

bool array_2d::can_explosion() {
	for (auto& i : explosion_s) {
		if (i->get_set_size() >= 4) {
			return true;
		}
	}
	return false;
}

void array_2d::explosion() {

	// explosion
	for (auto& i : explosion_s) {
		if (i->get_set_size() >= 4) {
			i->explosion();
			remove_explosion(i);
			break;
		}
	}

	// all block down
	block* temp;
	for (int x = 10; x >= 0; x--) {
		for (int y = 0; y < 5; y++) {
			if (block_array[x][y] != nullptr) {
				temp = block_array[x][y];
				delete_block(x, y);
				temp->down_all();
				insert(temp->get_x(), temp->get_y(), temp);
			}
		}
	}

	score++;
}
