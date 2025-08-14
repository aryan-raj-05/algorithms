#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    
    char genomes[500][500];
    int n, m;
    cin >> n >> m;
    rep(i, 2*n) rep(j, m) cin >> genomes[i][j];

    int count = 0;
    rep(c, m) {
        unordered_set<char> uset;
        rep(i, n) uset.insert(genomes[i][c]);
        bool flag = false; // second part contains any char from 1st part
        for (int i = n; i < 2*n; i++) {
            if (uset.find(genomes[i][c]) != uset.end()) flag = true;
        }
        if (!flag) count++;
    }

    cout << count << '\n';
}