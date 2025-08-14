#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	int prev = -1;
	int cur;
	for (int i = 0; i < n; i++) {
		cin >> cur;
		if (prev >= cur) {
			cout << "No\n";
			return 0;
		}

		prev = cur;
	}

	cout << "Yes\n";
	return 0;
}