#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> v;
	v.push_back(10);
	v.push_back(20);

	for (int n : v){
		cout << n << '\n';
	}
	return 0;
}

