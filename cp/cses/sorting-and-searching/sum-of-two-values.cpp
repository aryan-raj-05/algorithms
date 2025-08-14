#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); ++i)

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int n, x;
	cin >> n >> x;

	unordered_map<int, int> umap;
	umap.reserve(200000);

	rep(i, 0, n) {
		int val;
		cin >> val;
		auto complement = umap.find(x - val);
		if (complement != umap.end()) {
			cout << i + 1 << " " << complement->second + 1 << '\n';
			return 0;
		}
		umap.insert({val, i});
	}

	cout << "IMPOSSIBLE" << '\n';
}