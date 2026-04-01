#include <iostream>
using namespace std;

template <typename T>
T add(T a, T b) {
    return a + b;
}
int main() {
    // 정수(int), 실수(double) 등 어떤 타입이든 이 함수 하나로 해결!
    cout << add<int>(10, 20) << " ";     // int 버전
    cout << add<double>(1.1, 2.2);          // double 버전
    return 0;
}
