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
	auto cycle = [&](int d) -> int {
		map<int, int> vis;
		int t = 0, val = 1;
		while (true) {
			if (val == 0) return 0;
			if (vis.contains(val)) return t - vis[val];
			vis[val] = t++;
			val = val * 10 % d;
		}
	};
	int ans = *ranges::max_element(ranges::views::iota(1, 1000), {}, cycle);
	cout << ans << '\n';
}
