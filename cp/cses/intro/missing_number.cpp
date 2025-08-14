#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
    ll n;
    cin >> n;
    ll sum = n * (n + 1) / 2;
    ll num;
    for (ll i = 0; i < n - 1; i++) {
        cin >> num;
        sum -= num;
    }
    cout << sum << "\n";
}