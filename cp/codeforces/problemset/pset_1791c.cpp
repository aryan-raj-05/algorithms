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

int lenBeforeOperations(str &s, int sz) {
	int l = 0, r = sz - 1, ogLen = sz;
	while (l < r && !(s.at(l) == s.at(r))) {
		++l;
		--r;
		ogLen -= 2;
	}
	return ogLen;
}

int main() {
	setIO();

    int n;
    cin >> n;

    while(n--) {
    	str s;
    	int sz;
    	cin >> sz >> s;
    	cout << lenBeforeOperations(s, sz) << '\n';
    }
}