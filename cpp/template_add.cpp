#include<iostream>
using namespace std;

template <typename T>
T add(T a, T b) { return a + b; }

int main() {
	int x(2), y(3);
	double i(2.5), j(3.7);

	cout << add<int>(x, y) << endl;
	cout << add<double>(i, j) << endl;

	return 0;
}

