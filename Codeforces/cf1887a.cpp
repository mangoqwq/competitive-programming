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
		int N, M; cin >> N >> M;
		vector<int> a(N), b(N);
		map<int, int> mp;
		a[0] = 1;
		for (int i = 1; i < N; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < N; ++i) {
			cin >> b[i];
			mp[b[i]]++;
		}
		sort(a.begin(), a.end());
		debug(a, b);
		ll ans = 0;
		for (int i = 1; i < N; ++i) {
			auto it = mp.upper_bound(a[i]);
			if (it == mp.end()) {
				it = mp.begin();
				ans++;
			}
			it->second--;
			if (it->second == 0) mp.erase(it);
		}

		int left = mp.begin()->first;
		int add = max(0, M-left+1);
		cout << ans*M + add << '\n';
	}();
}
