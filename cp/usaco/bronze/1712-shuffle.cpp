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
#define f first
#define s second
#define pf printf
#define sf scanf

void setIO(str name = "") {
	cin.tie(0)->sync_with_stdio(0); 
	if (len(name)) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
    // setIO("shuffle");

	int n;
	cin >> n;

	vi sh(n), pos(n), temp(n);

	rep(i, n) {
		cin >> sh[i];
		sh[i]--;
	}

	rep(i, n) pos[i] = i;

	rep(_, 3) {
		rep(i, n)	temp[sh[i]] = pos[i];
		swap(pos, temp);
	}

	rep(i, n) 	cin >> sh[i];
	rep(i, n) 	temp[pos[i]] = sh[i];
	rep(i, n)	cout << temp[i] << '\n';
}