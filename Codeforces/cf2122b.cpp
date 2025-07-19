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
	int T; cin >> T;
	while (T--) [&]() {
		int N; cin >> N;
		ll ans = 0;
		for (int i = 0; i < N; ++i) {
			ll a, b, c, d; cin >> a >> b >> c >> d;
			if (b > d) {
				ans += a + (b - d);
			}
			else if (a > c) {
				ans += (a - c);
			}
		}
		cout << ans << '\n';
	}();
}
