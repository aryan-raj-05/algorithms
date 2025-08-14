#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < (n); ++i)

char genome[1001][51];
int cows, genome_len;
const unordered_map<char, int> umap = {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};

int id(char a, char b, char c) { // acgt -> 0123
    int ia = umap.at(a);
    int ib = umap.at(b);
    int ic = umap.at(c);
    return ia * 16 + ib * 4 + ic;
}

bool isValid(int i, int j, int k) {
    vector<bool> arr(64, false);
    for (int r = 0; r < cows; r++)
        arr[id(genome[r][i], genome[r][j], genome[r][k])] = true;

    for (int r = cows; r < 2*cows; r++)
        if (arr[id(genome[r][i], genome[r][j], genome[r][k])])
            return false;

    return true;
}

int main() {
    freopen("cownomics.in", "r", stdin);
    freopen("cownomics.out", "w", stdout);
    
    cin >> cows >> genome_len;
    rep(i, 2*cows) rep(j, genome_len) cin >> genome[i][j];
    
    int answer = 0;
    for(int i = 0; i < genome_len; i++) 
        for(int j = i + 1; j < genome_len; j++) 
            for(int k = j + 1; k < genome_len; k++) 
                if (isValid(i, j, k)) answer++;
            
    cout << answer << '\n';
}