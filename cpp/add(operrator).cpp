#include<iostream>
using namespace std;

class CPoly {
protected:
	int wid, hig;
public:
	CPoly(int w, int h) :wid(w), hig(h) {}
	~CPoly() {}
	virtual void Area() = 0;
};

class CRect :public CPoly {
public:
	CRect(int w=1, int h=1) :CPoly(w, h) {}
	~CRect() {}
	void Area() override {
		cout << wid * hig << endl;
	}
	CRect Add(CRect r) {
		return CRect(wid + r.wid, hig + r.hig);
	}
};

int main() {
	CRect r1(2, 3), r2(3, 4), r3;
	r1.Area();
	r2.Area();
	r3 = r1.Add(r2);
	r3.Area();
}
