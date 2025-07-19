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
	int N = 10000;
	int ans = 0;
	for (int n = 1; n <= N; ++n) {
		if (abs(n - (ll)sqrt(n) * (ll)sqrt(n)) <= 1e-9) continue;
		// (a sqrt(n) + b) / c
		ll a = 1, b = 0, c = 1;
		map<tuple<ll, ll, ll>, int> hist;
		for (int it = 0;; ++it) {
			if (hist.count({a, b, c})) {
				if (it % 2 == 0) ans++;
				break;
			}
			hist[{a, b, c}] = it;
			//   k + ((a sqrt(n) + b) / c - k)
			// = k + 1 / (c / (a sqrt(n) + b - kc))
			// = k + 1 / (c / (a sqrt(n) + b - kc) * (a sqrt(n) + kc - b) / (a sqrt(n) + kc - b))
			// = k + 1 / ((ac sqrt(n) + kc^2 - bc) / (a^2n - (b - kc)^2))
			ll k = floor((a * sqrt(n) + b) / c);
			tie(a, b, c) = tuple{a * c, k * c * c - b * c, a * a * n - (b - k * c) * (b - k * c)};
			ll g = gcd(gcd(a, b), c);
			a /= g, b /= g, c /= g;
		}
	}
	cout << ans << '\n';
}

