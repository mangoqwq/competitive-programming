#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

vector<ll> p10 = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int A, B, C; cin >> A >> B >> C;
		ll K; cin >> K;
		auto ans = [&]() -> string {
			for (ll a = p10[A-1]; a < p10[A]; ++a) {
				ll lo = max(p10[C-1] - a, p10[B-1]);
				ll hi = min(p10[C] - a, p10[B]);
				if (lo >= hi) continue;
				if (hi-lo >= K) {
					ll b = lo + K - 1;
					ll c = a + b;
					return to_string(a) + " + " + to_string(b) + " = " + to_string(c);
				}
				K -= hi-lo;
			}
			return "-1";
		}();
		cout << ans << '\n';
	}();
}
