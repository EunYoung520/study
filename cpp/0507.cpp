#include <iostream>   // cout
#include <algorithm>  // find
#include <vector>     // vector
using namespace std;

int main() {
    vector<int> v = { 4,2,5,1,3 };
    auto it = find(v.begin(), v.end(), 3);
    if (it != v.end()) cout << *it << " 찾았다";
    else cout << "없엉요";
}

//

#include <iostream>   // cout
#include <algorithm>  // find
#include <vector>     // vector
using namespace std;

class CPnt {
    int x, y;
public:
    CPnt(int a, int b) :x(a), y(b) {}
    void Pr() const{
        cout << x << "," << y << endl;
    };
};

int main() {
    CPnt p1{ 2,3 }, p2(3, 4);
    p1.Pr();
    p2.Pr();

}

//

#include <iostream>   // cout
#include <algorithm>  // find
#include <vector>     // vector
using namespace std;

class CRect {
    int w, h;
public:
    CRect(int a, int b) :w(a), h(b) {}
    void Area()const {
        cout << w * h << endl;
    }
};

int main() {
    vector<CRect>v = { CRect(1,2), CRect(2,3) };
    v.push_back(CRect(4, 5));
    for (auto it = v.begin(); it != v.end(); it++) {
        it->Area();
    }
}


