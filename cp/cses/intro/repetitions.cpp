#include <bits/stdc++.h>

using namespace std;

/* 
You are given a DNA sequence: a string consisting of characters A, C, G, 
and T. Your task is to find the longest repetition in the sequence. 
This is a maximum-length substring containing only one type of character.
*/

int main() {
    int global_count = 1;
    int local = 1;
    char prev, nxt;

    cin >> prev;

    while (cin >> nxt) {
        if (nxt == prev) {
            ++local;
        } else {
            global_count = max(local, global_count);
            prev = nxt;
            local = 1;
        }
    }

    global_count = max(local, global_count);

    cout << global_count << "\n";
}