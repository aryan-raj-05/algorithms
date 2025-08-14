#include <bits/stdc++.h>

using namespace std;

// 1, 5, 10, 20, 100

int give_bill(int n) {
	if (n >= 100)					return 100;
	else if (n >= 20 && n < 100)	return 20;
	else if (n >= 10 && n < 20)		return 10;
	else if (n >= 5 && n < 10)		return 5;
	else if (n >= 1 && n < 5)		return 1;
	else
		return -1;
}

int cal_bills(int n) {
	int count = 0;
	while (n > 0) {
		int bill = give_bill(n);
		n -= bill;
		count++;
	}
	return count;
}

int main() {
	int n;
	cin >> n;
	int count = cal_bills(n);
	cout << count << "\n";
}