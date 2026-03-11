//클래스의 활용법, 사각형 넓이 구하기
#include<iostream>
using namespace std;

class CRect{
private:
    int wid, hig;

public:
    CRect(){ wid=4; hig=3;}
    int Area(){
        return wid * hig;
    }
};

int main(){
    CRect r;
    cout << r.Area();
}


/* 
main으로부터 값을 받아 private 안의 변수를 다룰 수 있다.
-> private안의 값은 원래 다루지 못하지만 public 안의 "CRect(int a, int b) {wid =a; hig=b;}"를 통해 값을 부여할 수 있음 
    -> 이것으로 private안의 변수에 들어갈 값을 제한할 수 있음 
#include<iostream>
using namespace std;

class CRect{
private:
    int wid, hig;

public:
    CRect(){ wid=4; hig=3;}
    CRect(int a, int b) {wid =a; hig=b;}
    int Area(){
        return wid * hig;
    }
};

int main(){
    CRect me;
    CRect r(2,3);
    cout << r.Area();
}

CRect() ↔ CRect me;
→ 객체 me가 생성될 때 기본 생성자가 실행되어 wid=4, hig=3이 됨

CRect(int a,int b) ↔ CRect r(2,3);
→ 객체 r이 생성될 때 매개변수 생성자가 실행되어
a=2, b=3 값이 wid와 hig에 저장됨


Q. struct도 private와 public이 사용 가능한데 그럼 cpp 에서 class와 struct의 차이점은
   class는 기본값이 private이고, struct는 기본값이 public인 것 뿐인가? 

#include<iostream>
using namespace std;

class CRect {
	int w, h;
public:
	CRect() :w(2), h(3) {} //본문대입
	int Area() {
		return w * h;
	}
};

int main() {
	CRect r1;
	cout << r1.Area() << '\n'
}

쪽지시험 내용 
*/



