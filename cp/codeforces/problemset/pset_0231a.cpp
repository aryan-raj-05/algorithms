#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int n;
	vector<int> v(3);
	cin >> n;
	int sol = 0;

	for (int i = 0; i < n; ++i) {
		cin >> v[0] >> v[1] >> v[2];

		int count = 0;
		for (auto x : v) {
			if (x == 1)	++count;
		}

		if (count >= 2) {
			++sol;
		}
	}

	cout << sol << endl;
}