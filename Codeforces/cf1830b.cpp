#include <bits/stdc++.h>
#pragma GCC optimize ("O3")

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
		ll N; cin >> N;
		ll ans = 0;
		vector<vector<int>> vec(N+1);
		vector<unordered_map<int, int>> freq(N+1);
		
		vector<int> a(N);
		vector<int> b(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		for (int i = 0; i < N; ++i) {
			cin >> b[i];
		}
		for (int i = 0; i < N; ++i) {
			// if (a[i] * a[i] == b[i] + b[i]) ans--;
			vec[a[i]].push_back(b[i]);
			freq[a[i]][b[i]]++;
		}
		for (int i = 1; i <= N; ++i) {
			for (auto [x, cnt] : freq[i]) {
				ll need = 1LL * i * i - x;
				if (need == x) ans += 1LL * cnt * (cnt-1) / 2;
				else if (need < x) {
					if (freq[i].count(need)) {
						ans += 1LL * cnt * (freq[i][need]);
					}
				}
			}
		}
		// cout << ans << '\n';
		int B = sqrt(2 * N);
		for (int i = 1; i <= N; ++i) {
			for (int j = i+1; 1LL * j * i <= 2*N && j <= N; ++j) {
				int small = i, big = j;
				if (vec[i].size() > vec[j].size()) swap(small, big);
				for (auto [x, cnt] : freq[small]) {
					ll need = 1LL * i * j - x;
					// debug(i, j, need);
					if (freq[big].count(need)) {
						ans += 1LL * cnt * freq[big][need];
					}
				}
			}
		}
		cout << ans << '\n';
	}();
}
