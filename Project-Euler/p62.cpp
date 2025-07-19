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
	map<string, vector<ll>> classes;
	for (ll i = 1; i <= 10000; ++i) {
		string cube = to_string(i*i*i);
		ranges::sort(cube);
		classes[cube].push_back(i*i*i);
	}
	ll ans = 1e18;
	for (auto [rep, nums] : classes) {
		if (nums.size() >= 5) {
			ans = min(ans, *ranges::min_element(nums));
		}
	}
	cout << ans << '\n';
}
