#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); i++)

int n, m, k;
vector<int> desired_size; // size = n
vector<int> size_avail; // size = m

namespace sol2 {
	int apartments() {
		int i = 0, j = 0, count = 0;
		while (i < n && j < m) {
			if (abs(desired_size[i] - size_avail[j]) <= k) {
				count++;
				i++;
				j++;
			} else if (size_avail[j] < desired_size[i] - k) {
				j++;
			} else {
				i++;
			}
		}
		return count;
	}
}

// tle
namespace sol1 {
	int apartments() {
		vector<bool> isEmpty(m, true);
		int count = 0;
		for(int size : desired_size) {
			rep(j, 0, m) {
				if (!isEmpty[j]) continue;
				if ((size_avail[j] > size + k)) break;
				if (size_avail[j] >= size - k && size_avail[j] <= size + k) {
					count++;
					isEmpty[j] = false;
					break;
				}
			}
		}
		return count;
	}
}

int main() {
	cin >> n >> m >> k;

	desired_size.resize(n);
	size_avail.resize(m);

	rep(i, 0, n) cin >> desired_size[i];
	rep(i, 0, m) cin >> size_avail[i];

	sort(desired_size.begin(), desired_size.end());
	sort(size_avail.begin(), size_avail.end());

	cout << sol2::apartments() << "\n";
}