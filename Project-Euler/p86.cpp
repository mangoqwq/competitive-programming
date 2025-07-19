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
	auto cnt = [&](int M) {
		int ans = 0;
		for (int m = 1; m <= M; ++m) {
			for (int n = 1; n < m; ++n) {
				if (gcd(n, m) > 1) continue;
				if (n % 2 && m % 2) continue;
				for (int k = 1; k <= M; ++k) {
					int x = k * (m * m - n * n);
					int y = k * (2 * n * m);
					if (x > y) swap(x, y);
					if (x > M) break;
					if (y <= M) ans += x / 2;
					if (x <= M) ans += max(0, (2 * x - y + 2) / 2);
				}
			}
		}
		return ans;
		cout << ans << '\n';
	};
	int lo = 1, hi = 10000;
	while (lo < hi) {
		int mi = (lo + hi) >> 1;
		debug(mi);
		if (cnt(mi) >= 1e6) hi = mi;
		else lo = mi + 1;
	}
	cout << lo << '\n';
}
