#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    while (1) {
        cout << n << " ";
        if (n == 1) {
            break;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            n = 3 * n + 1;
        }
    }
    cout << "\n";
}