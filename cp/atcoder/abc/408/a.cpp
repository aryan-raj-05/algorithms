#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)
int main() {
    int n, s;
    cin >> n >> s;
    int prev_time = 0;
    rep(i, n) {
        int cur_time;
        cin >> cur_time;
        if (((double)cur_time - prev_time) > (s + 0.5)) {
            cout << "No\n";
            return 0;
        }
        prev_time = cur_time;
    }
    cout << "Yes\n";
}