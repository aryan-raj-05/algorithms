#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);

    int n, k;
    cin >> n >> k;

    vector<int> sizes(n);
    rep(i, n) cin >> sizes[i];
    
    int max_count = 0;
    for (int x : sizes) {
        int count = 0;
        for (int y : sizes) 
            if (x <= y && y <= x + k) count++;
        max_count = max(count, max_count);
    }

    cout << max_count << '\n';
}