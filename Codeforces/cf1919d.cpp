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
		vector<int> a(N);
		vector<set<int>> idxs(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
			idxs[a[i]].insert(i);
		}

		if (idxs[0].size() != 1) {
			cout << "NO" << '\n';
			return;
		}

		set<int> cul = idxs[0];
		for (int x = 1; x < N; ++x) {
			for (int i : idxs[x]) {
				bool ok = 0;
				auto it = idxs[x-1].lower_bound(i);
				if (it != idxs[x-1].begin()) {
					--it;
					auto it2 = --cul.lower_bound(i);
					ok |= *it == *it2;
				}
				it = idxs[x-1].upper_bound(i);
				if (it != idxs[x-1].end()) {
					auto it2 = cul.upper_bound(i);
					ok |= *it == *it2;
				}
				if (!ok) {
					cout << "NO" << '\n';
					return;
				}
			}
			for (int i : idxs[x]) cul.insert(i);
		}
		cout << "YES" << '\n';
	}();
}
