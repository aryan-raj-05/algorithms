#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
int main() {
    int n;
    cin >> n;
    unordered_set<int> uset;
    vector<int> nums;

    rep(i, n) {
        int num;
        cin >> num;
        if (uset.find(num) == uset.end()) {
            uset.insert(num);
            nums.push_back(num);
        }
    }

    sort(nums.begin(), nums.end());
    cout << nums.size() << '\n';
    for (int x : nums) cout << x << ' ';
    cout << '\n';
}