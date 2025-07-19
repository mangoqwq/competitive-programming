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
	const ll mod = 10000000000;
	auto power = [&](ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (1 & e) ret = __int128(ret) * b % mod;
			b = __int128(b) * b % mod; e >>= 1;
		}
		return ret;
	};
	int N = 1000;
	ll ans = 0;
	for (int i = 1; i <= N; ++i) {
		ans = (ans + power(i, i)) % mod;
	}
	cout << ans << '\n';
}
