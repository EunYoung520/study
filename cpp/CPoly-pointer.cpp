#include<iostream>
using namespace std;

class CPoly {
protected:
	int wid, hig;
public:
	CPoly(int w, int h) : wid(w), hig(h) {}
	virtual int Area() = 0; 
//vittual: 자식 클래스에서 재정의 될 수 있게 만드는 함수
// 순수 가상 함수, 반드시 구현을 강제하기 위함
};

class CRect : public CPoly {
public:
	CRect(int w, int h) : CPoly(w,h) {}
	int Area() override {return wid * hig;}
//override 부모 함수를 제대로 정의했는지 확인해주는 안전장치
};

class CTri : public CPoly {
public:
	CTri(int w, int h) : CPoly(w, h) {}
	int Area() override {return (wid * hig)/2;}
};

int main() {
	CPoly* p; 
	CRect r(2, 4);
	CTri t(3, 4);
	p = &r;
	cout << p->Area()<<'\n';
	p = &t;
	cout << p->Area();
	return 0;
  //p를 new로 정의한 것이 아니기 때문에 delete를 사용하지 않아도 된다. (않아야 한다.) 
}

