#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); i++)

int main() {
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);

    int arr[25][25];
    int sessions, n; // sessions, # cows
    cin >> sessions >> n;
    rep(i, n) rep(j, n) arr[i][j] = 999;

    rep(i, sessions) {
        unordered_map<int, int> ranking; // cowID -> rank
        rep(j, n) {
            int cowID;
            cin >> cowID;
            ranking.insert({cowID - 1, j});
        }

        rep(j, n) {
            for (int k = j + 1; k < n; k++) {
                int polarity = (ranking.at(j) - ranking.at(k)) > 0 ? 1 : -1;
                if (arr[j][k] == 999) arr[j][k] = polarity;
                else if (arr[j][k] + polarity == 0) arr[j][k] = 0;
            }
        }
    }

    int count = 0;
    rep(i, n) rep(j, n) {
        if (abs(arr[i][j]) == 1) count++;
    }

    cout << count << endl;
}

// [1] create 2d array
// [2] iterating over the ranking across sessions
// [3] for each combination (a, b) assign array[a][b] = +1
//                  if rank(a) > rank(b) else -1;
// [4] if in later iterations the value changes put zero
// [5] count number of non-zeros in the array