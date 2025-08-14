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

#define mp make_pair
#define pb push_back
#define f first
#define s second
#define pf printf
#define sf scanf

void setIO(str name = "") {
	cin.tie(0)->sync_with_stdio(0); 
	if (len(name)) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

const int MAX = 1e9 + 7;
const int LIM = (int) sqrt(MAX);

vector<char> mark(LIM + 1, false);
vector<ll> primes;

void precompute() {
	for(ll i = 2; i <= LIM; i++) {
		if (!mark[i]) {
			primes.push_back(i);
			for(ll j = i * i; j <= LIM; j += i) {
				mark[j] = true;
			}
		}
	}
}

void printRange(ll lo, ll hi) {
	vector<char> isPrime(hi - lo + 1, true);

	for(ll i : primes){
		for(ll j = max(i * i, (lo + i - 1) / i * i); j <= hi; j += i){
			isPrime[j - lo] = false;
		}
	}
	
	if (lo == 1){
		isPrime[0] = false;
	}

	rep(i, len(isPrime)) {
		if (isPrime[i])
			pf("%lld\n", lo + i);
	}
}

int main() {
	precompute();

	int n;
	sf("%d", &n);

	while (n--) {
		int lo, hi;
		sf("%d %d", &lo, &hi);
		printRange(lo, hi);
		pf("\n");
	}
}