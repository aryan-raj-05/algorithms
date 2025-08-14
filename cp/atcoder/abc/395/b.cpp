#include <bits/stdc++.h>

using namespace std;

void printVector(const vector<vector<char>>& mat) {
	for (const auto &row : mat) {
		for (char val : row) {
			cout << val;
		}
		cout << "\n";
	}
}

int main() {
	int n;
	cin >> n;

	vector<vector<char>> vec(n, vector<char>(n, '?'));

	char color;

	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			color = '#';
		} else {
			color = '.';
		}

		// cerr << "Color is: " << color << "\n";

		int j = n - i - 1;
		// change of i required

		// cerr << "(i, j) = " << i << ", " << j << "\n";

		if (j >= i) {
			// cerr << "We are in loop: " << i << "\n";
			for (int a = i; a <= j; a++) {
				for (int b = i; b <= j; b++) {
					// cerr << "\tFilling Color Loop, Parent Loop: " << i << ", (a, b) = " << a << ", " << b << "\n";
					vec.at(a).at(b) = color;
				}
			}
		}

	}

	printVector(vec);
}