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
	int T; cin >> T;
	while (T--) [&]() {
		int N; cin >> N;
		int mx[] = {(int)-1e9, (int)-1e9};
		ll best[] = {0, 0};
		ll num[] = {0, 0};
		for (int i = 0; i < N; ++i) {
			int a; cin >> a;
			int p = i%2;
			mx[p] = max(mx[p], a);
			if (a >= 0) {
				num[p]++;
				best[p] += a;
			}
		}
		if (num[0] || num[1]) {
			cout << max(best[0], best[1]) << '\n';
		}
		else {
			cout << max(mx[0], mx[1]) << '\n';
		}
	}();
}
