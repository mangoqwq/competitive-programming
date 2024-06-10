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
		for (ll b = 1; b <= M; ++b) {
			for (ll i = b*b; i - b <= N; i += b*b) {
				ll a = i - b;
				if (1 <= a && a <= N) ans++;
			}
		}
		cout << ans << '\n';
	}();
}
