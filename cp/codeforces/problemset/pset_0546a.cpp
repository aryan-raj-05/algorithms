#include <bits/stdc++.h>

using namespace std;

int solve(int k, int n, int w) {
	int totalCost = k * (w * (w + 1) / 2);
	if (totalCost > n) {
		return totalCost - n;
	} else {
		return 0;
	}
}

int main() {
	int k, n, w;
	cin >> k >> n >> w;
	cout << solve(k, n, w) << endl;
}