#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// divide the numbers 1,2, ...,n into two sets of equal sum.

int main() {
    int n;
    cin >> n;

    ll sum = (ll) n * (n + 1) / 2;
    if (sum % 2 != 0) {
        cout << "NO\n";
        return 0;
    }

    cout << "YES\n";
    vector<int> vi, vj;

    int counter = n;
    int temp = -1;
    ll total = 0;
    for (;;) {
        if (total == (sum / 2)) {
            temp = 0;
            break;
        } else if ((counter + total) <= (sum / 2)) {
            vi.push_back(counter);
            total += counter;
            counter--;
        } else {
            temp = (sum / 2) - total;
            vi.push_back(temp);
            break;
        }
    }

    for (int i = 1; i <= counter; ++i) {
        if (i == temp)  continue;
        vj.push_back(i);
    }

    cout << vj.size() << "\n";
    for (auto iter : vj)    cout << iter << " ";
    cout << "\n" << vi.size() << "\n";
    for (auto iter : vi)    cout << iter << " ";
    cout << "\n";
}