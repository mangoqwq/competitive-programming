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
	const int ML = 1.5e6;
	vector<int> cnt(ML + 1, 0);
	for (int m = 1; m * m <= ML; ++m) {
		for (int n = 1; n < m; ++n) {
			if (gcd(m, n) != 1) continue;
			if (m % 2 == 1 && n % 2 == 1) continue;
			int a = m * m - n * n;
			int b = 2 * m * n;
			int c = m * m + n * n;
			int l = a + b + c;
			for (int k = 1; k * l <= ML; ++k) {
				cnt[k * l]++;
			}
		}
	}
	cout << ranges::count(cnt, 1) << '\n';
}
