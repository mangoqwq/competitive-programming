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
	int T; cin >> T;
	while (T--) [&]() {
		int N; cin >> N;
		vector<ll> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		ll mn = *ranges::min_element(a);
		ll g = 0, used = 0;
		for (ll x : a) {
			if (x == mn && !used) {
				used = 1;
				continue;
			}
			if (x % mn == 0) {
				g = gcd(g, x);
			}
		}
		cout << (g == mn ? "YES" : "NO") << '\n';
	}();
}
