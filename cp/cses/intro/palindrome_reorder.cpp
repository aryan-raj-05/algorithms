/*

Given a string, your task is to reorder its letters in such a way that it becomes a palindrome 
(i.e., it reads the same forwards and backwards).

Input: The only input line has a string of length n consisting of characters A–Z.
Output: Print a palindrome consisting of the characters of the original string. 
You may print any valid solution. If there are no solutions, print "NO SOLUTION".

*/

#include <bits/stdc++.h>

using namespace std;

void solve(string& s) {
    vector<int> mp(26, 0);
    int len = s.size();

    for (auto ch : s) {
        mp[ch - 'A']++;
    }

    int cnt = 0;
    char oddChar = 0;
    for (int i = 0; i < 26; ++i) {
        int val = mp[i];
        if (val % 2 != 0) {
            ++cnt;
            oddChar = 'A' + i;
        }
    }

    if (cnt > 1) {
        cout << "NO SOLUTION\n";
        return;
    }

    int i = 0, j = len - 1;

    for (int iter = 0; iter < 26; ++iter) {
        while (mp[iter] > 1) {
            s[i] = s[j] = 'A' + iter;
            ++i; --j;
            mp[iter] -= 2;
        }
    }

    if (cnt == 1) {
        s[i] = oddChar;
    }

    cout << s << "\n";
}

int main() {
    string s;
    getline(cin, s);
    solve(s);
}