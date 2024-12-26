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
	map<ll, int> cache;
	auto length = [&](auto self, ll n) -> ll {
		if (n == 1) return 1;
		if (cache.contains(n)) return cache[n];
		int &cur = cache[n];
		if (n % 2 == 0) return cur = 1 + self(self, n / 2);
		else return cur = 1 + self(self, 3 * n + 1);
	};
	auto ans = *ranges::max_element(ranges::views::iota(1, 1000000), {}, [&](int n) { return length(length, n); });
	cout << ans << '\n';
}
