#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using str = string;
using vi = vector<int>;

#define all(x)          x.begin(), x.end()
#define iter(a, x)      for(auto& a : x)
#define len(x)          (int) (x).size()
#define range(i, a, b)  for(int i = a; i < (b); ++i)
#define rep(i, n)       range(i, 0, n)

void setIO(str name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

namespace sol1 {
    int solve(str s) {
        int n = len(s);
        int count = 0;

        rep(i, n) {
            range(j, i+1, n) {
                range(k, j+1, n) {
                    if ((j - i) == (k - j) && s[i] == 'A' && s[j] == 'B' && s[k] == 'C') {
                        ++count;
                    }
                }
            }
        }

        return count;
    }
}

namespace sol2 {
    int solve(str s) {
        int n = len(s);
        int count = 0;

        rep(i, n) {
            if (s[i] != 'A')
                continue;
            range(j, i+1, n) {
                if (s[j] != 'B')
                    continue;
                int k = 2 * j - i; // <-- important part right here
                if (k < n && k >= 0 && s[k] == 'C') {
                    count++;
                }
            }
        }

        return count;
    }
}

int main() {
    setIO();
    
    str s;
    cin >> s;

    cout << sol1::solve(s) << endl;
    cout << sol2::solve(s) << endl;
}