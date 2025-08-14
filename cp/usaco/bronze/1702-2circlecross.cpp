#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n); ++i)

const int MAX = 52;
char road[MAX];

int index(int cur) {
    for(int i = cur + 1; i < MAX; i++) {
        if (road[i] == road[cur]) return i;
    }
    return -1;
}

int main() {
    freopen("circlecross.in", "r", stdin);
    freopen("circlecross.out", "w", stdout);

    rep(i, MAX) cin >> road[i];
    int crosses = 0;

    rep(i, MAX) {
        int second_point = index(i);
        for (int j = i + 1; j < second_point; j++) {
            int other_point = index(j);
            if (other_point > second_point) crosses++;
        }
    }

    cout << crosses << '\n';
}