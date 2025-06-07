#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int X, Y, Z; cin >> X >> Y >> Z;
	int x = 0, y = 0, z = 0;
	for (int i = 0; i < 6; ++i) {
		int s; cin >> s;
		x += s;
		y += s == 100;
		z += s > 0;
	}
	bool ans = x >= X && y >= Y && z >= Z;
	cout << (ans ? "MASTER" : "REJECTED AGAIN") << '\n';
}
