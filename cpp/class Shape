//가로 2, 세로 3인 경우 삼각형과 사각형의 면적을 구하는 코드를 작성하시오

#include<iostream> //클래스 하나만 사용함
using namespace std;

class M {
	int wid;
	int hig;
public:
	M() {wid = 2; hig = 3;}
	int Tarea() {return wid * hig;}
	int Rarea() {return (wid * hig) / 2;}
};

int main() {
	M me;
	cout << me.Tarea() << '\n';
	cout << me.Rarea();
}

//단점: 역할이 섞여있고, 객체지향적으로 애매함(하나의 클래스가 여러 역할을 함), 클래스 확장이 번거로워 기존 코드를 계속 수정해야 함, 유지보수 어려움



/*
교수님 코드, 클래스 두 개 사용
=>도형별로 클래스를 분리하여 역할이 명확하고 객체의 의미가 분명함. 
  = 유지보수 및 추가 시 기존 코드를 건들 필요 없이 클래스 하나를 추가하면 됨 (확장이 쉬움)
#include<iostream>
using namespace std;

class r {
	int wid, hig;
public:
	r() {wid = 2; hig = 3;}
	int Tarea() {return wid * hig;}
};

class t {
	int wid;
	int hig;
public:
	t() {wid = 2; hig = 3;}
	int Rarea() {return (wid * hig) / 2;}
};

int main() {
	r re;
	t tr;
	cout << re.Tarea() << '\n';
	cout << tr.Rarea();
}
*/
