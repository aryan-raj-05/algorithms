#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using str = string;
using vi = vector<int>;

#define all(x)          x.begin(), x.end()
#define iter(a, x)      for (auto& a : x)
#define len(x)          (int) (x).size()
#define range(i, a, b)  for (int i = a; i < (b); ++i)
#define rep(i, n)       for (int i = 0; i < (n); ++i)

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); 
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	// setIO("cbarn");

	int n;
	cin >> n;

	vector<int> cows(n);
	rep(i, n) {  cin >> cows[i];  }

	int res = INT_MAX;

	rep(barnPos, n) {
		int curdist = 0;
		for(int pos = 0; pos < n; pos++) {
			curdist += pos * cows[(barnPos + pos) % n];
		}
		res = min(res, curdist);
	}

	cout << res << '\n';
}