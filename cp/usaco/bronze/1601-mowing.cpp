#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using vi = vector<int>;

#define all(x)          x.begin(), x.end()
#define iter(a, x)      for (auto& a : x)
#define len(x)          (int) (x).size()
#define rep(i, a, b)    for (int i = a; i < (b); i++)

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); 
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

namespace sol1 {

const int OFFSET = 1000;
const int SIZE = 2005;

int lastVisit[SIZE][SIZE];

void solve() {
	int n;
    cin >> n;

    // directions: N, E, S, W
    map<char, pair<int, int>> dir = {
        {'N', {0, 1}},
        {'E', {1, 0}},
        {'S', {0, -1}},
        {'W', {-1, 0}}
    };

    // initialize last visit times to -1 (unvisited)
    memset(lastVisit, -1, sizeof(lastVisit));

    int x = OFFSET, y = OFFSET;
    int time = 0;
    lastVisit[x][y] = 0; // start position mowed at time 0

    int minDiff = INT_MAX;
    for (int i = 0; i < n; i++) {
        char d;
        int steps;
        cin >> d >> steps;
        auto [dx, dy] = dir[d];

        for (int s = 0; s < steps; s++) {
            x += dx;
            y += dy;
            time++;

            if (lastVisit[x][y] != -1) {
                int diff = time - lastVisit[x][y];
                minDiff = min(minDiff, diff);
            }

            lastVisit[x][y] = time;
        }
    }

    if (minDiff == INT_MAX)
        cout << -1 << '\n';
    else
        cout << minDiff << '\n';
}

};

int main() {
	setIO("mowing");
	sol1::solve();
}