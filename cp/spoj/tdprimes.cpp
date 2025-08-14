// You are to write all primes less than 10^8.
// write out only the 1st, 101st, 201st, ... (n mod 100)th number
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
#define rep(i, n)       range(i, 0, n)

#define pb push_back
#define f first
#define s second
#define mp make_pair

#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MAX = 1e8;

vector<bool> isPrime(MAX + 1, true);
vi primes;

void sieve() {
	isPrime[0] = isPrime[1] = false;
    for (int i = 2; i * i <= MAX; i++) 
    	if (isPrime[i]) 
    		for (int j = i * i; j <= MAX; j += i) 
    			isPrime[j] = false;

    rep(i, len(isPrime)) {
    	if (isPrime[i]) primes.pb(i);
    }
}

int main() {
	fast

	sieve();

    for (int i = 0; i < len(primes); i += 100) {
    	cout << primes[i] << '\n';
    }
}