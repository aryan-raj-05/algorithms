#include <cstdio>
#include <iostream>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

int main() {
	freopen("promote.in", "r", stdin);
	freopen("promote.out", "w", stdout);

	int b_bf, b_af;
	int s_bf, s_af;
	int g_bf, g_af;
	int p_bf, p_af;

	cin >> b_bf >> b_af;
	cin >> s_bf >> s_af;
	cin >> g_bf >> g_af;
	cin >> p_bf >> p_af;

	int pG, pS, pB;
	pG = p_af - p_bf;
	pS = g_af - g_bf + pG;
	pB = s_af - s_bf + pS;

	cout << pB << endl;
	cout << pS << endl;
	cout << pG << endl;

	return 0;
}