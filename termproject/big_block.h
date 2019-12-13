#ifndef bigBlock
#define bigBlock

#include <vector>
using namespace std;

class block;

class big_block {
protected:
	virtual void rotate() = 0;
	virtual bool can_left() = 0;
	virtual bool can_right() = 0;
	virtual bool can_down() = 0;
	virtual bool down() = 0;
public:
	vector<block*> v;

	big_block();
	~big_block();
	
	void left();
	void right();
	
	bool down_all();
	bool move(int input);
};

#endif

