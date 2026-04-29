
//1 객체 생성과 초기
#include<iostream>
using namespace std;

class CRect {
	int w, h;
public:
	CRect(int w = 1, int h = 1) :w(w), h(h) {};
	void Area() { cout << w * h << endl; }
};

int main() {
	CRect r(2, 3);
	r.Area();
}


//2
#include<iostream>
using namespace std;

class CRect {
	int w, h;
public:
	CRect(int w = 1, int h = 1) :w(w), h(h) {};
	void Area() { cout << w * h << endl; }
};

int main() {
	CRect *p=new CRect(2,3);
	p->Area();
	delete p;
}

//3
#include<iostream>
using namespace std;

class CRect {
	int w, h;
public:
	CRect(int w = 1, int h = 1) :w(w), h(h) {};
	void Area() { cout << w * h << endl; }
};

int main() {
	auto p=make_unique<CRect>(2,3);
	p->Area();
}

//4 범위기반 for
#include<iostream>
using namespace std;

class CRect {
	int w, h;
public:
	CRect(int w = 1, int h = 1) :w(w), h(h) {};
	void Area() { cout << w * h << endl; }
};

int main() {
	CRect we[2] = { {2,3},{3,4} };
	for (auto& r:we){
		r.Area();
	}
}

//5STL컨테이너
#include<iostream>
#include<vector>
using namespace std;

class CRect {
	int w, h;
public:
	CRect(int w = 1, int h = 1) :w(w), h(h) {};
	void Area() { cout << w * h << endl; }
};

int main() {
	vector <CRect> v = { CRect(2,3), CRect(3,4) };
	v.push_back(CRect(5, 6));
	for (auto& r : v)r.Area();
}

//6연산자 오버로딩
#include<iostream>
#include<vector>
using namespace std;

class CRect {
	int w, h;
public:
	CRect(int w = 1, int h = 1) :w(w), h(h) {};
	void Area() { cout << w * h << endl; }
	CRect operator+(const CRect& t) {
		return CRect(w + t.w, h + t.h);
	}
};

int main() {
	CRect a(2, 3), b(3, 4);
	CRect c = a+b;
	c.Area();
}


//7
#include<iostream>
#include<vector>
using namespace std;

template<typename T>

class CRect {
	T w, h;
public:
	CRect(T w = 1, T h = 1) :w(w), h(h) {};
	void Area() { cout << w * h << endl; }
	CRect operator+(const CRect& t) {
		return CRect(w + t.w, h + t.h);
	}
};

int main() {
	CRect a(2.1, 3.1), b(3.1, 4.1);
	CRect c = a+b;
	c.Area();
}
