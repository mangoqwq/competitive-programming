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
	auto precomp = [&](int N) {
		vector<int> check;
		for (int i = 1; i < (1 << N); ++i) {
			vector<int> a(N+1);
			for (int j = 0; j < N; ++j) {
				if (!(1 & (i >> j))) continue;
				for (int k = j+1; k <= N; k += j+1) a[k] ^= 1;
			}
			int on = accumulate(a.begin()+1, a.end(), 0);
			if (on <= N/5) {
				check.push_back(i);
			}
		}
		return check;
	};
	vector<vector<int>> checks(20);
	for (int i = 1; i <= 19; ++i) {
		checks[i] = precomp(i);
	}

	int T; cin >> T;
	while (T--) [&]() {
		int N, M; cin >> N >> M;
		vector<pair<int, int>> reqs(M);
		for (auto &[a, b] : reqs) cin >> a >> b;
		if (N >= 20) {
			cout << N << '\n';
			for (int i = 1; i <= N; ++i) {
				cout << i << (i == N ? '\n' : ' ');
			}
		}
		else {
			for (int msk : checks[N]) {
				bool ok = [&]() -> bool {
					for (auto [i, j] : reqs) {
						i--, j--;
						if ((1 & (msk >> i)) && !(1 & (msk >> j))) return 0;
					}
					return 1;
				}();
				if (ok) {
					vector<int> idxs;
					for (int i = 0; i < N; ++i) {
						if (1 & (msk >> i)) idxs.push_back(i+1);
					}
					cout << idxs.size() << '\n';
					for (int i = 0; i < idxs.size(); ++i) {
						cout << idxs[i] << (i == idxs.size() - 1 ? '\n' : ' ');
					}
					return;
				}
			}
			cout << -1 << '\n';
		}
	}();
}
