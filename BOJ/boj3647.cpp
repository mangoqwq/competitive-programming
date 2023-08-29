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
	using i128 = __int128_t;
	const i128 INF = i128(LLONG_MAX) * LLONG_MAX;

	auto overflows = [&](i128 a, i128 b, i128 c) {
		return a > c/b;
	};

	auto factor = [&](int x) {
		map<int, int> mp;
		for (int i = 2; i*i <= x; ++i) {
			int mult = 0;
			while (x % i == 0) mp[i]++, x /= i;
		}
		if (x != 1) mp[x]++;
		return mp;
	};

	auto non_square_factors = [&](ll x, const map<int, int> &mp) {
		set<int> ret;
		for (auto [f, cnt] : mp) {
			if (cnt % 2 == 1) ret.insert(f);
		}
		return ret;
	};

	auto isqrt = [&](i128 x) {
		i128 lo = 0, hi = LLONG_MAX;
		while (lo < hi) {
			i128 mi = (lo+hi) / 2;
			if (mi * mi < x) lo = mi+1;
			else hi = mi;
		}
		return (ll)lo;
	};

	auto is_square = [&](i128 x) {
		ll s = isqrt(x);
		return s*s == x;
	};

	auto candidates = [&](int l, int r) -> vector<int> {
		vector<int> ret;
		for (int i = l; i <= r; ++i) {
			map<int, int> mp = factor(i);
			auto lone = non_square_factors(i, mp);
			if (!lone.empty()) {
				ll big = *(--lone.end());
				if (i + big > r && i - big < l) continue;
				ret.push_back(i);
			}
		}
		return ret;
	};

	auto solve = [&](int l, int r) -> ll {
		struct Item { i128 val; set<int> s; };
		vector<Item> rep;
		for (int x : candidates(l, r)) {
			rep.push_back({x, non_square_factors(x, factor(x))});
		}

		map<int, int> factor_cnts;
		map<int, int> bitmap; int T = 0;
		for (auto v : rep) {
			for (auto f : v.s) factor_cnts[f]++;
		}
		for (auto [a, b] : factor_cnts) {
			if (b != 2) {
				bitmap[a] = T++;
				continue;
			}
			bool bad = 0;
			ll combined_tot = 1;
			set<int> combined;
			vector<Item> nxt;
			for (auto [val, s] : rep) {
				if (!s.count(a)) nxt.push_back({val, s});
				else {
					if (overflows(combined_tot, val, INF)) {
						bad = 1;
						continue;
					}
					combined_tot *= val;
					for (int f : s) {
						if (combined.count(f)) combined.erase(f);
						else combined.insert(f);
					}
				}
			}

			if (!bad && combined_tot != 1) {
				nxt.push_back({combined_tot, combined});
			}
			swap(nxt, rep);
		}

		// debug(bitmap);
		// debug(factor_cnts);
		// for (auto [val, s] : rep) {
		// 	debug((ll)val, s);
		// }

		struct Num { i128 val; int msk; };
		vector<Num> nums;
		for (auto [val, s] : rep) {
			int msk = 0;
			for (int f : s) msk += (1 << bitmap[f]);
			nums.push_back({val, msk});
		}

		auto chmin = [&](i128 &a, i128 b) -> void {
			if (a == -1 || a > b) a = b;
		};

		vector<i128> dp(1 << T, -1);
		for (auto [val, msk] : nums) {
			vector<i128> nxt = dp;
			chmin(nxt[msk], val);
			for (int i = 0; i < (1 << T); ++i) {
				if (dp[i] != -1 && !overflows(val, dp[i], INF)) {
					chmin(nxt[i ^ msk], val * dp[i]);
				}
			}
			swap(dp, nxt);
		}
		if (dp[0] == -1) return -1;
		return isqrt(dp[0]);
	};

	// debug(solve(2337, 2392));
	ll a, b;
	while (cin >> a >> b) [&]() {
		for (int i = a; i <= b; ++i) {
			if (is_square(i)) {
				cout << isqrt(i) << '\n';
				return;
			}
		}
		ll ans = solve(a, b);
		if (ans == -1) cout << "none" << '\n';
		else cout << ans << '\n';
	}();
}
