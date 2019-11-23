#include <iostream>

using namespace std;

int fibo(int i) {
	if (i == 1) return 0;
	else if (i == 2) return 1;
	else return fibo(i-1) + fibo(i-2);
}

int main() {
	int n;
	cin >> n;
	
	cout << fibo(n) << endl;

	return 0;
}
