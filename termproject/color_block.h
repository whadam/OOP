#pragma once
#include <set>

using namespace std;

class block;

class color_block {
private:
	set<block*> s;
public:
	explicit color_block(block* b);
	void insert(set<block*> s);
	void insert(block* b);
	set<block* > get_set();
	int get_set_size();
	void explosion();
};