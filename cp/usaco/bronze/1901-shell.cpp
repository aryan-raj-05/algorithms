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

void change(int *pos, int a, int b) {
	if (*pos == a) 		*pos = b;
	else if (*pos == b) *pos = a;
	else 				return;
}

int main() {
    // setIO("shell");
    int n;
    cin >> n;

    int sca = 0, scb = 0, scc = 0;
    int posa = 1, posb = 2, posc = 3;
    while (n--) {
    	int a, b, g;
    	cin >> a >> b >> g;
    	change(&posa, a, b);
    	change(&posb, a, b);
    	change(&posc, a, b);

    	if (g == posa)		sca++;
    	else if (g == posb)	scb++;
    	else if (g == posc)	scc++;
    }

    cout << max({sca, scb, scc}) << '\n';
}