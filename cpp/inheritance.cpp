#include<iostream>
using namespace std;

class CPoly {
protected:
	int w, h;
public:
	CPoly(int a, int b) :w(a), h(b) {}
	virtual void Area() {
		cout << "CPoly" << endl;
	}
	virtual ~CPoly() {}
};

class CRect :public CPoly {
public:
	CRect(int w, int h) :CPoly(w, h) {}
	void Area() override {
		cout << "Rect:" << w * h << endl;
	}
};

class CTri :public CPoly {
public:
	CTri(int w, int h) :CPoly(w, h) {}
	void Area() override {
		cout << "Tri:" << (w * h)/2 << endl;
	}
};

int main() {
	CRect r(2, 3);
	CTri t(2, 3);
	CPoly* p = &r;
	p->Area();
}
