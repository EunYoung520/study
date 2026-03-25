#include<iostream>
using namespace std;

int main() {
	int z(8);
	int x(2), y(3);
	//람다 함수: [캡처](인자){본문}
	auto add = [z](int a, int b) {return a + b;};
	cout << add(x, y);
	return 0;



/*
#include<iostream>
using namespace std;

int main() {
	int z(1);
	int x(2), y(3);
	//람다 함수: [캡처](인자){본문}
	cout << [z](int a, int b) {
		return a + b + z;
		}(x, y);
	return 0;
}

*/
