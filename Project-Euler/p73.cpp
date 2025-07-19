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
	const int MD = 12000;
	int ans = 0;
	for (int d = 1; d <= MD; ++d) {
		for (int n = 1; n < d; ++n) {
			if (gcd(n, d) != 1) continue;
			if (n * 3 > d && n * 2 < d) {
				ans++;
			}
		}
	}
	cout << ans << '\n';
}
