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

const int MAX = 1e6 + 1;

vector<bool> isPrime(MAX, true);
unordered_set<int> primes;

void sieve(int n) {
	isPrime[0] = isPrime[1] = false;
	for(int i = 2; 1LL * i * i < n; i++) {
		if (isPrime[i]) {
			for(int j = i * i; j < n; j += i) {
				isPrime[j] = false;
			}
		}
	}

	rep(i, MAX) 
		if(isPrime[i])
			primes.insert(i);
}

int main() {
	setIO();
	
    int n;
    cin >> n;

    sieve(n);

    for(int i = 4; i < n/2 + 1; i++) {
    	int c = n - i;
    	if (primes.find(c) == primes.end() && 
    		primes.find(i) == primes.end()) {
    		cout << i << ' ' << c << '\n';
    		break;
    	}
    }
}