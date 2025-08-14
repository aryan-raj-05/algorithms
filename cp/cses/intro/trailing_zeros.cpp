#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

/*
Your task is to calculate the number of trailing zeros in the factorial n!.

For example, 20!=2432902008176640000 and it has 4 trailing zeros.
*/

/*
        APPROACH __1__

int count_factor_occurance(int number, int factor) {
    int count = 0;
    while (number > 0) {
        if (number % factor != 0)   return count;
        number = number / factor;
        ++count;
    }
    return count;
}

int cal_trail_zero(int n) {
    int fives = 0;
    while (n > 0) {
        fives += count_factor_occurance(n, 5);
        --n;
    }
    return fives;
}

*/

ll cal_trail_zeros(ll n) {
    ll factor_five = 0;
    ll div = 5;
    while (n >= div) {
        factor_five += (n / div);
        div *= 5;
    }
    return factor_five;
}

int main() {
    ll n;
    cin >> n;
    cout << cal_trail_zeros(n) << "\n";
}