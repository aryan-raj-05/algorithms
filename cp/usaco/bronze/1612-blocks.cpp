#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using str = string;
using vi = vector<int>;

#define all(x)          x.begin(), x.end()
#define iter(a, x)      for (auto& a : x)
#define len(x)          (int) (x).size()
#define range(i, a, b)  for (int i = a; i < (b); ++i)
#define rep(i, n)       for (int i = 0; i < (n); ++i)

#define mp make_pair
#define pb push_back
#define ff first
#define ss second

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); 
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

vi countFreq(str s) {
	vi freq(26, 0);
	for(char c : s)
		freq[c - 'a']++;
	return freq;
}

int main() {
	setIO("blocks");

	int n;
	cin >> n;

	vector<pair<str, str>> words(n);
	for(auto &[w1, w2] : words)
		cin >> w1 >> w2;

	vi maxBlocks(26, 0);
	for(const auto &[w1, w2] : words) {
		cerr << "Are we stuck\n";
		vi freq1 = countFreq(w1);
		vi freq2 = countFreq(w2);
		rep(c, 26) {
			maxBlocks[c] += max(freq1[c], freq2[c]);
		}
	}

	rep(i, 26) {
		cout << maxBlocks[i] << '\n';
	}
}