#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)
int main() {
    int n;
    cin >> n;

    vector<int> X(n);
    vector<int> Y(n);

    rep(i, n) cin >> X[i];
    rep(i, n) cin >> Y[i];

    int max_dist = 0;
    rep(i, n) {
        for (int j = i + 1; j < n; j++) {
            int dx = X[j] - X[i];
            int dy = Y[j] - Y[i];
            max_dist = max(max_dist, dx * dx + dy * dy);
        }
    }

    cout << max_dist << '\n';
}