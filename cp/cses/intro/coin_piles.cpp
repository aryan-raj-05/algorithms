#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        if ((a + b) % 3 == 0 && max(a, b) <= 2 * min(a, b)) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
    }
}