#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, num;
	unordered_set<int> us;
	us.reserve(200000);
	scanf("%d", &n);

	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		us.insert(num);
	}

	printf("%lld\n", us.size());
}