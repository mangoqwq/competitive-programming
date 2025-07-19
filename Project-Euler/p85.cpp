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
	struct Item { ll w, h, cnt; };
	vector<Item> items;
	for (ll w = 1; w <= 1000; ++w) {
		for (ll h = 1; h <= 1000; ++h) {
			items.push_back({w, h, w * (w+1) * h * (h+1) / 4});
		}
	}

	const ll target = 2e6;
	ranges::sort(items, {}, [&](Item item) { return abs(item.cnt - target); });
	auto [w, h, cnt] = items[0];
	debug(items[0]);
	cout << w * h << '\n';
}
