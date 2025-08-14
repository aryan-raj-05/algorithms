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
	// setIO("cowsignal");

	// inputs
    int m, n, k;
    cin >> m >> n >> k;

    vector<vector<char>> sign(m, vector<char>(n));
    rep(i, m) {
    	rep(j, n) {
    		cin >> sign[i][j];
    	}
    }

    // enlarge
    vector<vector<char>> res;
    iter(row, sign) {
    	vector<char> item;
    	iter(ch, row) {
    		rep(_, k)	item.pb(ch);
    	}
    	rep(_, k)	res.pb(item);
    }

    // print
    iter(row, res) {
    	iter(ch, row) {
    		cout << ch;
    	}
    	cout << '\n';
    }
}