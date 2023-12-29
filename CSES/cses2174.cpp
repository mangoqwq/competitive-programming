#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

/*
let f(n) denote min # steps for n
observation: x <= y ==> f(x) <= f(y) (use induction)
so it's always optimal to pick largest digit to subtract
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N; cin >> N;
	map<pair<ll, int>, pair<ll, int>> cache;
	auto solve = [&](auto self, ll n, int big) -> pair<ll, int> {
		debug(n, big);
		if (n == 0) return {0, 0};
		if (n < 10) return {1, min(0, (int)n-big)};
		if (cache.count({n, big})) return cache[{n, big}];
		string s = to_string(n);
		int head = s[0] - '0';
		ll tail = stoll(s.substr(1));
		if (tail == 0) {
			auto [steps, minus] = self(self, n - max(big, head), big);
			return cache[{n, big}] = {steps+1, minus};
		}
		auto [steps, minus] = self(self, tail, max(big, head));
		auto [steps2, minus2] = self(self, n - tail + minus, big);
		return cache[{n, big}] = {steps + steps2, minus2};
	};
	auto [ans, _] = solve(solve, N, 0);
	cout << ans << '\n';
}
