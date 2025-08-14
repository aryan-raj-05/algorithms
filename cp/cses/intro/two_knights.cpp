#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        if (i == 1) {
            cout << 0 << "\n";
            continue;
        }
        ll total_ways = (ll) (i * i)*(i * i - 1) / 2;
        ll attacks = (ll) 4 * (i - 1) * (i - 2);
        ll ans = total_ways - attacks;
        cout << ans << "\n";
    }
}