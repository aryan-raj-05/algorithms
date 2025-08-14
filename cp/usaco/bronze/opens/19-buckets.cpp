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
#define rep(i, n)       range(i, 0, n)

void setIO(str name = "") {
    cin.tie(0)->sync_with_stdio(0);
    if (!name.empty()) {
        freopen((name + ".in").c_str(), "r", stdin);
        freopen((name + ".out").c_str(), "w", stdout);
    }
}

int main() {
    setIO("buckets");

    int bi, bj, ri, rj, li, lj;
    
    rep(i, 10) {
        str row;
        cin >> row;
        rep(j, 10) {
            if (row[j] == 'B') {
                bi = i; bj = j;
            } else if (row[j] == 'R') {
                ri = i; rj = j;
            } else if (row[j] == 'L') {
                li = i; lj = j;
            }
        }
    }

    int cows = abs(bi - li) + abs(bj - lj) - 1;

    if (bi == li && ri == bi &&
        ((lj < rj && rj < bj) ||
         (bj < rj && rj < lj))) {
        cows += 2;
    } else if (bj == lj && rj == bj && 
        ((li < ri && ri < bi) ||
         (bi < ri && ri < li))) {
        cows += 2;
    }

    cout << cows << endl;
}