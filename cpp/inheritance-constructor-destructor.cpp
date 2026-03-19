// C++ 상속 구조에서 생성자와 소멸자의 호출 순서를 확인하는 예제
// 부모 클래스 → 자식 클래스 순으로 생성되고,
// 자식 클래스 → 부모 클래스 순으로 소멸된다.

#include<iostream>
using namespace std;

// 부모 클래스 (추상 클래스)
class CPoly {
protected:
	int wid, hig;

public:
	// 생성자: 객체 생성 시 가장 먼저 실행됨
	CPoly(int w, int h) : wid(w), hig(h) {
		cout << "C:Parent" << endl;
	}

	// 순수 가상 함수 (자식 클래스에서 반드시 구현)
	virtual int Area() = 0;

	// 소멸자: 객체 소멸 시 가장 나중에 실행됨
	~CPoly() {
		cout << "D:parent" << '\n';
	}
};

// 자식 클래스
class CRect : public CPoly {
public:
	// 생성자: 부모 생성자 호출 후 실행됨
	CRect(int w, int h) : CPoly(w, h) {
		cout << "C:Son" << endl;
	}

	// 오버라이딩: 부모의 순수 가상 함수 구현
	int Area() override {
		return wid * hig;
	}

	// 소멸자: 먼저 실행됨
	~CRect() {
		cout << "D:son" << '\n';
	}
};

int main() {
	// 객체 생성
	CRect r(2,3);

	// 프로그램 종료 시 자동 소멸
	return 0;
}
