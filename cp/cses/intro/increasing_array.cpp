#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n, x, y, count = 0;
    cin >> n;
    cin >> x;
    for (ll i = 1; i < n; i++) {
        cin >> y;
        if (x > y) {
            ll diff = (x - y);
            count += diff;
            continue;
        }
        x = y;
    }
    cout << count << "\n";
}