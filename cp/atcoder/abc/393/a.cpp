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
    setIO();
    
    str s, t;
    cin >> s >> t;

    if (s == "sick" && t == "sick") {
        cout << 1 << "\n";
    } else if (s == "sick" && t == "fine") {
        cout << 2 << "\n";
    } else if (s == "fine" && t == "sick") {
        cout << 3 << "\n";
    } else if (s == "fine" && t == "fine") {
        cout << 4 << "\n";
    }
}