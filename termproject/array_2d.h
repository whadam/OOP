#pragma once
#include <vector>
#include <set>

using namespace std;

class color_block;
class block;

class array_2d {
private:
	static block* block_array[12][5];
	static set<color_block*> explosion_s;
	static int score;
public:
	array_2d();
	static bool can_make(int type);
	static void delete_block(int x, int y);
	static void insert(vector<block*> v);
	static void insert(int x, int y, block* b);
	static block* get_block(int x, int y);
	static bool can_move(int x, int y);
	static void print();
	static void insert_explosion(color_block* group);
	static void remove_explosion(color_block* group);
	static bool can_explosion();
	static void explosion();
};