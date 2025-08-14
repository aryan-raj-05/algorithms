#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);

    int x, y, m;
    cin >> x >> y >> m;

    int iterx = (m / x) + 1;
    int itery = (m / y) + 1;

    int max = 0;
    for (int i = 0; i < iterx; i++) {
        for (int j = 0; j < itery; j++) {
            int amount = x * i + y * j;
            if (amount > max && amount <= m) max = amount;
        }
    }

    cout << max << '\n';
}