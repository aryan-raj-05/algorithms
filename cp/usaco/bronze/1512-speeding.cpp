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

#define mp 				make_pair
#define pb 				push_back
#define f 				first
#define s 				second
#define pf 				printf
#define sf 				scanf

void setIO(str name = "") {
	cin.tie(0)->sync_with_stdio(0); 
	if (len(name)) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
    setIO("speeding");

    int n, m;
    cin >> n >> m;

    vi limit(100), bessie(100);

    // for speed limits
    int pos = 0, length, speed;
    rep(i, n) {
    	cin >> length >> speed;
    	range(j, pos, pos + length)
    		limit[j] = speed;
    	pos += length;
    }

    // for bessie
    pos = 0;
    rep(i, m) {
    	cin >> length >> speed;
    	range(j, pos, pos + length)
    		bessie[j] = speed;
    	pos += length;
    }

    // calulation of over the limits
    int maxOverLimit = 0;
    rep(i, 100) {
    	maxOverLimit = max(maxOverLimit, bessie[i] - limit[i]);
    }
    cout << maxOverLimit << '\n';
}