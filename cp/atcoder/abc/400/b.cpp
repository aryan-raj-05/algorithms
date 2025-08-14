#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define rep(i, a, b) for(int i = a; i < (b); i++)
const int MAX = 1'000'000'000;

int main() {
	ll n, m;
	cin >> n >> m;

	ll res = 1;
	ll toAdd = 1;
	rep(i, 0, m) {
		toAdd *= n;
		if (MAX - res < toAdd) {
			cout << "inf\n";
			exit(0);
		}
		res += toAdd;
	}

	cout << res << '\n';
}