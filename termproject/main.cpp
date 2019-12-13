#include <iostream>
#include <ctime>
#include "conio.h"
#include "array_2d.h"
#include "big_block.h"
#include "fold_block.h"
#include "tree_block.h"
#include "cross_block.h"
#include "block.h"

using namespace std;

int make_block_type() {
	srand((unsigned int)time(0));

	int block_type = rand() % 3;

	return block_type;
}

big_block* make_block(int type) {
	int c1 = rand() % 4;
	int c2 = rand() % 4;
	int c3 = rand() % 4;
	if (type == 0) {		// fold
		return new fold_block(c1, c2, c3);
	}
	else if (type == 1) {	// tree
	    return new tree_block(c1, c2, c3);
	}
	else { // type == 2		// cross
        int c4 = rand() % 4;
        int c5 = rand() % 4;
        return new cross_block(c1, c2, c3, c4, c5);
	}
}

void play() {
	while (true) {
		int blockType = make_block_type();
		if (!array_2d::can_make(blockType)) {
			break;
		}
		big_block* bb = make_block(blockType);
        array_2d::insert(bb->v);

		while (true) {	// keyboard hit
			system("clear");
			array_2d::print();

			for (auto& i : bb->v) {
				array_2d::delete_block(i->get_x(), i->get_y());
			}

			int input = getch();
			if (! bb->move(input)) {
				system("clear");
				array_2d::print();
				while (true) {
					// merge
					for (int x = 11; x >= 0; x--) {
						for (int y = 0; y < 5; y++) {
							if (array_2d::get_block(x, y) != nullptr) {
								array_2d::get_block(x, y)->find_merge();
							}
						}
					}
					if (!array_2d::can_explosion()) {
						break;
					}
					array_2d::explosion();
				}
				break;
			}
			system("clear");
			array_2d::print();
		}
		system("clear");
		array_2d::print();
	}
}

int main() {
	new array_2d();
	play();
	
	return 0;
}
