#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
	vector<int> val(7);
	rep(i, 7) {
		cin >> val[i];
	}

	sort(val.begin(), val.end());

	int a = val.at(6) - val.at(5);
	int b = val.at(6) - val.at(4);
	int c = val.at(6) - (a + b);

	cout << a << " " << b << " " << c << endl;
}