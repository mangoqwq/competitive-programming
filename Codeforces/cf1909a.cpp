#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int x_pos, x_neg, y_pos, y_neg;
		x_pos = x_neg = y_pos = y_neg = 1;
		int N; cin >> N;
		for (int i = 0; i < N; ++i) {
			int x, y; cin >> x >> y;
			x_pos &= x >= 0;
			x_neg &= x <= 0;
			y_pos &= y >= 0;
			y_neg &= y <= 0;
		}
		cout << ((x_pos || x_neg || y_pos || y_neg) ? "Yes" : "No") << '\n';
	}();
}
