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
    setIO("word");
    
    int n, k;
    cin >> n >> k;
    str res;
    int charInLine = 0;

    while (n--) {
        str word;
        cin >> word;

        if (len(word) + charInLine <= k) {
            res.append(word);
            res.append(" ");
            charInLine += len(word);
        } else {
            res.pop_back();
            res.append("\n");
            charInLine = len(word);
            res.append(word);
            res.append(" ");
        }

    }
    res.pop_back();
    cout << res;
}