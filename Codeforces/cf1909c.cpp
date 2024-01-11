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
		vector<int> idxs;
		map<int, int> a;
		for (int i = 0; i < N; ++i) {
			int idx; cin >> idx; idx--;
			a[idx] = 1;
			idxs.push_back(idx);
		}
		for (int i = 0; i < N; ++i) {
			int idx; cin >> idx; idx--;
			a[idx] = -1;
			idxs.push_back(idx);
		}
		sort(idxs.begin(), idxs.end());
		vector<ll> c(N);
		for (int i = 0; i < N; ++i) {
			cin >> c[i];
		}
		vector<int> lens, stk;
		for (int i : idxs) {
			if (a[i] == 1) stk.push_back(i);
			else if (a[i] == -1) {
				lens.push_back(i - stk.back());
				stk.pop_back();
			}
		}
		sort(lens.begin(), lens.end());
		sort(c.begin(), c.end(), greater<ll>());
		ll ans = 0;
		for (int i = 0; i < N; ++i) {
			ans += c[i] * lens[i];
		}
		cout << ans << '\n';
	}();
}
