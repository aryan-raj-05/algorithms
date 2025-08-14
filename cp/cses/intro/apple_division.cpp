#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> weights;
ll min_diff = INT_MAX;

void divide(ll cur_sum, ll cur_i, ll rem_sum) {
    if ((size_t)cur_i >= weights.size()) return;

    // option 1: include
    ll new_sum = cur_sum + weights[cur_i];
    ll new_rem = rem_sum - weights[cur_i];
    ll diff = abs(new_sum - new_rem);
    min_diff = (min_diff > diff) ? diff : min_diff;
    divide(new_sum, cur_i + 1, new_rem);

    // option 2: don't include
    divide(cur_sum, cur_i + 1, rem_sum);
}

int main() {
    ll n, sum = 0;
    cin >> n;
    weights.resize(n);

    for (ll i = 0; i < n; i++) {
        cin >> weights[i];
        sum += weights[i];
    }

    divide(0, 0, sum);
    cout << min_diff << '\n';
}