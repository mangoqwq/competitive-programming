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
	int L, N; cin >> L >> N;
	struct Item { int x, y; };
	vector<Item> v = {{0, 1}, {L, L+1}};
	for (int i = 0; i < N; ++i) {
		int x, y; cin >> x >> y;
		v.push_back({x,y});
	}

	sort(v.begin(), v.end(), [&](const Item &a, const Item &b) {
		return tie(a.x, a.y) < tie(b.x, b.y);
	});
	for (int i = 1; i < v.size(); ++i) {
		v[i].y = min(v[i-1].y + v[i].x - v[i-1].x, v[i].y);
	}
	for (int i = v.size() - 2; i >= 0; --i) {
		v[i].y = min(v[i+1].y + v[i+1].x - v[i].x, v[i].y);
	}

	ll ans = 1;
	for (int i = 1; i < v.size(); ++i) {
		ans = max(ans, ((ll)v[i].x - v[i-1].x + v[i].y + v[i-1].y) / 2);
	}
	cout << ans << '\n';

}
