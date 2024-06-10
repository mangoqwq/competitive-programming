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
		int N, M; cin >> N >> M;
		ll ans = 0;
		for (int p = 1; p * p <= N; ++p) {
			for (int q = 1; q * q <= M; ++q) {
				if (gcd(p, q) != 1) continue;
				ans += min(N / p, M / q) / (p + q);
			}
		}
		cout << ans << '\n';
	}();
}
