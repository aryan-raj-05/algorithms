#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

namespace sol1 {
	int findSolution(vector<int> &v, int n) {
		unordered_map<int, int> ump;
		int minLen = INT_MAX;

		rep(i, n) {
			if (ump.find(v[i]) != ump.end()) {
				minLen = min(minLen, i - ump.at(v[i]) + 1);
			}
			ump[v[i]] = i;
		}

		return (minLen == INT_MAX) ? -1 : minLen;
	}
}

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);

	rep(ni, n) {
		cin >> vec[ni];
	}

	int result = sol1::findSolution(vec, n);
	cout << result << "\n";
}