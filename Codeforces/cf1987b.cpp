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
		vector<int> a(N);
		int mx = 0;
		ll worst = 0, add = 0;
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
			if (a[i] < mx) {
				add += mx - a[i];
				worst = max(worst, (ll)mx - a[i]);
			}
			else mx = a[i];
		}
		cout << add + worst << '\n';
	}();
}
