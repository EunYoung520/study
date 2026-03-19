#include<iostream>
using namespace std;

class CRect {
	int w, h;
public:
	CRect():w(3),h(4){}
	CRect(int a, int b):w(a), h(b){}
	CRect(int a) :w(a), h(a) {}
	int Area() {
		return w * h;
	}
};

int main() {
	CRect me;
	cout << me.Area() << '\n';
	CRect he(8);
	cout << he.Area() << '\n';
	CRect r(2,3);
	cout << r.Area();
}

/* 
컴파일러는 전달된 인자를 보고 생성자를 선택한다. 
public에서 생성된 생성자와 main에서 사용된 순서가 달라도 전달되는 인자가 0, 1, 2같은 숫자로 전달되기에 해당 수를 받고 알맞은 생성자를 선택해 출력한다. 
*/
