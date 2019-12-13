#pragma once

class block {
private:
	int color;
	int x, y;
	class color_block* group;
public:
    explicit block(int color);
    ~block();
	int get_color();
	void set_color(int newColor);
	int get_x();
	int get_y();
	void set_group(class color_block*);
	class color_block* get_group();
	void set_location(int x, int y);
	bool can_left();
	bool can_right();
	bool can_down();
	void right();
	void left();
	void down();
	void down_all();
	bool can_merge(block* b);
	bool can_explosion(block* b);
	void merge(block* b);
	void find_merge();
};