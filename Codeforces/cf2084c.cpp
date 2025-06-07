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
		vector<int> a(N), b(N), idx(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i]; a[i]--;
			idx[a[i]] = i;
		}
		for (int i = 0; i < N; ++i) {
			cin >> b[i]; b[i]--;
		}
		vector<int> pairs;
		for (int i = 0; i < N; ++i) {
			if (a[i] == b[i]) pairs.emplace_back(i);
			else {
				if (b[idx[b[i]]] != a[i]) {
					cout << -1 << '\n';
					return;
				}
			}
		}
		if ((int)pairs.size() > (N % 2)) {
			cout << -1 << '\n';
			return;
		}
		vector<pair<int, int>> ans;
		auto swp = [&](int i, int j) {
			ans.emplace_back(i, j);
			idx[a[j]] = i;
			idx[a[i]] = j;
			swap(a[i], a[j]);
			swap(b[i], b[j]);
		};
		debug(pairs);
		if ((int)pairs.size()) {
			int i = pairs[0];
			if (i != N / 2) {
				swp(i, N/2);
			}
		}
		for (int i = 0; i < N/2; ++i) {
			int want = b[N-i-1];
			int j = idx[want];
			if (j == i) continue;
			swp(i, j);
		}

		cout << ans.size() << '\n';
		for (auto [i, j] : ans) {
			cout << i+1 << " " << j+1 << '\n';
		}
		debug(a);
		debug(b);
	}();
}
