#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define range(i, a, b) for (int i = a; i < (b); ++i)
int main() {
    int n, m;
    cin >> n >> m;
    
    vector<int> guarding(n + 1, 0);
    rep (i, m) {
        int l, r;
        cin >> l >> r;
        l--;
        guarding[l]++;
        guarding[r]--;
    }

    range(i, 1, n + 1) 
        guarding[i] += guarding[i - 1];
    int result = 1e9;
    rep (i, n)
        result = min(result, guarding[i]);
    cout << result << '\n';
}