#include <bits/stdc++.h>
using  namespace std;
#define rep(i, a, b) for(int i = (a); i < (b); ++i)

int main() {
	int n, x;
	cin >> n >> x;

	vector<int> nums(n);
	rep(i, 0, n) { cin >> nums[i]; }
	sort(nums.begin(), nums.end());

	int l = 0, r = n - 1;
	int count = 0;
	while (l < r) {
		if (nums[r] > x) {
			r--;
		} else if (nums[r] == x || nums[r] + nums[l] > x) {
			count++;
			r--;
		} else {
			l++; r--;
			count++;
		}
	}
	if (l == r) count++;
	
	cout << count << '\n';
}