#include <bits/stdc++.h>

using namespace std;

int main() {
	int n;
	cin >> n;

	if (n <= 3) {
		cout << "NO\n";
		return 0;
	}

	if (n % 2 == 0) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}


}