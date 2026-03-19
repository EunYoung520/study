#include<iostream>
using namespace std;

class CPoly { //부모 클래스
protected: //자식 클래스에서는 접근 가능, 외부에서는 접근 불가. 
    int wid, hig;
};

class CRect : public CPoly { //사각형
//자식 클래스 접근 방식 class 변수명 : public 부모 클래스
public:
    CRect() {
        wid = 2;
        hig = 3;
    }
    int Area() {
        return wid * hig;
    }
};
 
class CTri : public CPoly {
public:
    CTri() {
        wid = 2;
        hig = 3;
    }
    int Area() {
        return (wid * hig) / 2;
    }
};

class CSqr : public CPoly {
public:
    CSqr() {
        wid = 2; 
        hig = 2; //정사각형은 가로와 세로가 같아야 함
    }
    int Area() {
        return wid * hig;
    }
};

int main() {
    CRect r;
    CTri t;
    CSqr s;

    cout << "Rectangle Area : " << r.Area() << '\n';
    cout << "Triangle Area  : " << t.Area() << '\n';
    cout << "Square Area    : " << s.Area() << '\n';
}

/*
private: 같은 클래스에서만 접근 가능
protected: 같은 클래스, 자식 클래스에서 접근 가능 (외부는 불가. ex main)
public: 같은 클래스, 자식 클래스, 외부에서 접근 가능 (main에서 다룰 수 있음) 

오버라이딩: 상속에서 다른 객체를 지정하여 실행한다. / 부모의 함수를 자식이 다시 정의하는 것 (같은 이름, 같 형태)  
  부모 기능을 자식이 바꾸기
오버로딩: 매개변수의 개수, 형태를 가지고 구분한다. / 함수 이름은 같고, 매개변수가 다름
  같은 버튼인데 입력이 다름
다형성: 오버로딩, 오버라이딩의 템플릿 / 오버로딩, 오버라이딩을 포함하는 개념 / 같은 이름의 함수가 상황에 따라 다르게 동작하는 것. 
  같은 버튼인데 상황마다 다르게 작동
상속: 부모 클래스의 변수와 함수를 자식이 물려받는 것
  부모 재산 물려받기
*/

