#include <bits/stdc++.h> 
using namespace std;

using ll = long long;
using pii = pair<int,int>;
using str = string;
using vi = vector<int>;

#define all(x)          x.begin(), x.end()
#define iter(a, x)      for (auto& a : x)
#define len(x)          (int) (x).size()
#define range(i, a, b)  for (int i = a; i < (b); ++i)
#define rep(i, n)       for (int i = 0; i < (n); ++i)

#define mp 				make_pair
#define pb 				push_back
#define f 				first
#define s 				second
#define pf 				printf
#define sf 				scanf

void setIO(str name = "") {
	cin.tie(0)->sync_with_stdio(0); 
	if (len(name)) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

#define nxt(i) ((i + 1) % 3)

int main() {
 	// setIO("mixmilk");

 	vector<ll> cap(3);
 	vector<ll> milk(3);
 	rep(i, 3) {
 		cin >> cap[i] >> milk[i];
 	}

 	int cur = 0, next = 1;
 	
 	rep(i, 100) {
 		ll newVal = milk.at(cur) + milk.at(next);
 		if (newVal <= cap.at(next)) {
 			milk.at(next) = newVal;
 			milk.at(cur) = 0;
 		} else {
 			milk.at(next) = cap.at(next);
 			milk.at(cur) = newVal - cap.at(next);
 		}
 		cur = next;
 		next = nxt(next);
 	}

 	iter(x, milk) 
 		cout << x << '\n';
}