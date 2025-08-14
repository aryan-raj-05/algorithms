#include <bits/stdc++.h>
using namespace std;
#define rep(i, b) for(int i = 0; i < (b); i++)

vector<int> petals;

int find_avg_in_range(int a, int b) {
    int count = b - a + 1;
    int sum = 0;
    for (int i = a; i <= b; i++) {
        sum += petals[i];
    }
    
    if (sum % count == 0) {
        int avg = sum / count;
        for (int i = a; i <= b; i++) {
            if (petals[i] == avg) return 1;
        }
    }
    
    return 0;
}

int main() {
    int n;
    cin >> n;
    petals.resize(n);
    rep(i, n) cin >> petals[i];

    int total = n;
    rep(i, n) {
        for (int j = i + 1; j < n; j++)
            total += find_avg_in_range(i, j);
    }

    cout << total << '\n';
}