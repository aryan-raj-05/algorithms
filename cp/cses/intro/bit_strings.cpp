#include <bits/stdc++.h>

using namespace std;

#define MOD 1000000007
typedef long long ll;

ll exp(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1)
            result = (result * base) % MOD;
        base = (base * base) % MOD;
        exp /= 2;
    }
    return result;
}

int main() {
    int n;
    cin >> n;
    cout << exp(2, n) << "\n";
}