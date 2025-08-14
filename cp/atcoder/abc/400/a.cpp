#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b)    for (int i = a; i < (b); i++)

int main() {
	unordered_set<int> factors;
	rep(i, 1, 401) {
		if (400 % i == 0) { factors.insert(i); }
	}

	int a;
	cin >> a;
	if (factors.find(a) == factors.end()) {
		cout << -1;
	} else {
		cout << 400 / a << '\n';
	}
}