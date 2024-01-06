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
		int N; cin >> N;
		int val1 = 0, val2 = 0, ans = 0;
		for (int i = 0; i < N; ++i) {
			int x; cin >> x;
			x = N - x + 1;
			if (x >= val1 && x >= val2) {
				if (val1 >= val2) val1 = x;
				else val2 = x;
			}
			else if (x >= val1) val1 = x;
			else if (x >= val2) val2 = x;
			else {
				ans++;
				if (val1 >= val2) val1 = x;
				else val2 = x;
			}
		}
		cout << ans << '\n';
	}();
}
