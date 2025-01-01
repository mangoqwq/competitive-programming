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
	ll lim = 1e7, ans = 0;
	for (int i = 2; i < lim; ++i) {
		ll x = 0;
		for (char c : to_string(i)) {
			int v = c - '0';
			x += v*v*v*v*v;
		}
		ans += (x == i) * i;
	}
	cout << ans << '\n';
}
