#include <bits/stdc++.h>
using namespace std;

void setIO(string name = "") {
	cin.tie(0)->sync_with_stdio(0); 
	if (!name.empty()) {
		freopen((name + ".in").c_str(), "r", stdin); 
		freopen((name + ".out").c_str(), "w", stdout);
	}
}

int main() {
	// setIO("tttt");

	vector<string> game(3);
	for (int i = 0; i < 3; ++i) {
		cin >> game[i];
	}

	set<char> individuals;
	set<pair<char, char>> teams;

	vector<vector<char>> lines;

	for (int i = 0; i < 3; ++i)
		lines.push_back({game[i][0], game[i][1], game[i][2]});

	for (int j = 0; j < 3; ++j)
		lines.push_back({game[0][j], game[1][j], game[2][j]});

	lines.push_back({game[0][0], game[1][1], game[2][2]});
	lines.push_back({game[0][2], game[1][1], game[2][0]});

	for (auto& line : lines) {
		set<char> chars(line.begin(), line.end());
		if (chars.size() == 1) {
			individuals.insert(*chars.begin());
		} else if (chars.size() == 2) {
			char a = *chars.begin();
			char b = *next(chars.begin());

			bool hasA = false, hasB = false;
			for (char c : line) {
				if (c == a) hasA = true;
				if (c == b) hasB = true;
			}
			if (hasA && hasB) {
				if (a > b) swap(a, b);
				teams.insert({a, b});
			}
		}
	}

	cout << individuals.size() << '\n' << teams.size() << '\n';
}
