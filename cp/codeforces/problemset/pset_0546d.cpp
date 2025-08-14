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

#define FAST ios_base::sync_with_stdio(false); cin.tie(NULL);

const int MAX = 5000001;

namespace sol1 {
    // TLE
    vector<bool> isPrime(MAX, true);
    vi primes;

    void sieve() {
        isPrime[0] = isPrime[1] = false;
        for (int i = 2; i < MAX; i++) {
            if (isPrime[i]) {
                primes.pb(i);
                for (int j = i * 2; j < MAX; j += i) {
                    isPrime[j] = false;
                }
            }
        }
    }

    int expOfPinNfact(int p, int n) {
        int count = 0;
        for (int pow = p; pow <= n; pow *= p) {
            count += (n / pow);
        }
        return count;
    }

    int solve(int a, int b) {
        int res = 0;
        iter (p, primes) {
            if (p > a) break;
            res += (expOfPinNfact(p, a) - expOfPinNfact(p, b));
        }
        return res;
    }
}

namespace sol2 {
    // AC
    vi primeFactorsInN(MAX, 0);
    vi noOfFactorsInNfactorial(MAX, 0);

    void sieve() {
        range(i, 2, MAX) {
            if (primeFactorsInN[i] == 0) {
                for (int j = i; j < MAX; j += i) {
                    int x = j, count = 0;
                    while (x % i == 0) {
                        x /= i;
                        count++;
                    }
                    primeFactorsInN[j] += count;
                }
            }
        }

        range(i, 2, MAX) {
            noOfFactorsInNfactorial[i] = noOfFactorsInNfactorial[i - 1] + 
                primeFactorsInN[i];
        }
    }

    int solve(int a, int b) {
        return noOfFactorsInNfactorial[a] - noOfFactorsInNfactorial[b];
    }
}

int main() {
    sol2::sieve();

    int n;
    scanf("%d", &n);

    while (n--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", sol2::solve(a, b));
    }
}