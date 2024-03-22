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
		int N, K; cin >> N >> K; N++;
		vector<int> cnt(N);
		for (int i = 0; i < N; ++i) {
			cin >> cnt[i];
		}
		debug(N, K);
		auto attempt = [&](int mex) -> bool {
			vector<int> vec(cnt.begin(), cnt.begin() + mex);
			debug(mex, cnt, vec);
			sort(vec.begin(), vec.end());
			for (int m = 1; m <= mex; ++m) {
				map<ll, ll> mp;
				for (int i = 0; i < m; ++i) mp[vec[i]]++;
				for (int i = 0; i < m; ++i) {
					if (mp.begin()->first <= 0) return 0;
					mp.begin()->second--;
					if (mp.begin()->second == 0) mp.erase(mp.begin());
					if (i == m-1) break;
					int rem = K;
					while (rem) {
						auto [num, occurs] = *(--mp.end());
						mp.erase(--mp.end());
						if (rem < occurs) {
							mp[num-1] += rem;
							mp[num] += occurs - rem;
							rem = 0;
						}
						else {
							ll mx = (mp.empty() ? K : num - (--mp.end())->first);
							ll delta = min(rem / occurs, mx);
							rem -= delta * occurs;
							mp[num - delta] += occurs;
						}
					}
					debug(mp);
				}
			}
			return 1;
		};
		int lo = 0, hi = N;
		while (lo < hi) {
			int mi = (lo + hi + 1) >> 1;
			if (attempt(mi)) lo = mi;
			else hi = mi - 1;
		}
		cout << lo << '\n';
	}();
}
