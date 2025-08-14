#include <bits/stdc++.h>

using namespace std;

int main() {
	freopen("teleport.in", "r", stdin);
	freopen("teleport.out", "w", stdout);

	int a, b, x, y;
	cin >> a >> b >> x >> y;

	int c1 = abs(a - b);
	int c2 = abs(min(a, b) - min(x, y)) + abs(max(a, b) - max(x, y));
	cout << min(c1, c2) << "\n";
}