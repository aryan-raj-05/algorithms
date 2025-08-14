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

void solve() {
	int n;
	cin >> n;

	vi a(1007, 0);
	rep(i, n) {
		int si, ti, b;
		cin >> si >> ti >> b;
		range(j, si, ti) {
			a[j] += b;
		}
	}

	int ans = 0;
	iter(x, a)	ans = max(ans, x);
	cout << ans << '\n';
}

int main() {
    // setIO("blist");
    
    solve();
}