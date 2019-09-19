#include <iostream>

using namespace std;

void* code() {
	
}

int data = 0;
int bss;

int main() {
	int * heap = new int[2];
	int stack;

	cout << "code\t" << (void*) code << endl;
	cout << "Rodata\t" << (void*) "Hello world" << endl;
	cout << "data\t" << &data << endl;
	cout << "BSS\t" << &bss << endl;
	cout << "HEAP\t" << heap << endl;
	cout << "Stack\t" << &stack << endl;

	delete[] heap;

	return 0;
}
