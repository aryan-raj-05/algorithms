#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for (int i = 0; i < (n); ++i)

namespace sol1 {
	// slow will give TLE
	// also incorrect
	void solve() {
		int n, q;
		cin >> n >> q;
		unordered_map<int, int> pn;
		for (int i = 0; i < n; i++) {
			pn[i + 1] = i + 1;
		}

		for (int i = 0; i < q; i++) {
			int op, a, b;
			cin >> op >> a;
			if (op == 3) {
				cout << pn[a] << "\n";
			} else if (op == 2) {
				cin >> b;
				for (auto &[key, val] : pn) {
					if (val == a)	val = b;
				}
			} else if (op == 1) {
				pn[a] = b;
			}
		}
	}	
}

namespace sol2 {
	// man wtf is this 
	// i don't know what i am doing
	struct UF {
		vector<int> id;
		vector<int> sz;

		UF(int n) {
			id.resize(n + 1);
			sz.resize(n + 1, 1);
		}

		int find(int x) {
			int root = x;
			while (root != id[root])
				root = id[root];
			while (x != root) {
				int next = id[x];
				id[x] = root;
				x = next;
			}
			return root;
		}

		void merge(int p, int q) {
			int root1 = find(p);
			int root2 = find(q);

			if (root1 == root2) {
				return;
			}

			if (sz[root1] < sz[root2]) {
				sz[root2] += sz[root1];
				id[root1] = root2;
			} else {
				sz[root1] += sz[root2];
				id[root2] = root1;
			}
	 	}

	};

	void solve() {
		int n, q;
		cin >> n >> q;

		sol2::UF nests(n);
		vector<int> results;

		while (q--) {
			int op, a, b;
			cin >> op;
			if (op == 1) {
				cin >> a >> b;
				nests.id[a] = b;
			} else if (op == 2) {
				cin >> a >> b;
				nests.merge(a, b);
			} else if (op == 3) {
				cin >> a;
				cout << nests.find(a) << "\n";
			}
		}
	}

}

namespace sol3 {
	void solve() {
		int n, q;
		cin >> n >> q;

		vector<int> p2b(n);
		vector<int> b2h(n);
		vector<int> h2b(n);

		rep(i,n) p2b[i] = i;
		rep(i,n) b2h[i] = i;
		rep(i,n) h2b[i] = i;

		rep(qi, q) {
			int type;
			cin >> type;

			if (type == 1) {
				int a, b;
				cin >> a >> b;
				a--; b--;
				p2b[a] = h2b[b];
			} else if (type == 2) {
				int a, b;
				cin >> a >> b;
				a--; b--;
				swap(h2b[a], h2b[b]);
				b2h[h2b[a]] = a;
				b2h[h2b[b]] = b;
			} else {
				int a;
				cin >> a;
				a--;
				int ans = b2h[p2b[a]];
				cout << ans + 1 << "\n";
			}
		}
	}
}

int main() {
	sol3::solve();
}


