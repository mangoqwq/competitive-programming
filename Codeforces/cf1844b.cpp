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
		if (N == 1) cout << 1 << '\n';
		else if (N == 2) {
			cout << 1 << " " << 2 << '\n';
		}
		else {
			vector<int> ans(N);
			iota(ans.begin(), ans.end(), 1);
			swap(ans[0], ans[1]);
			swap(ans[2], ans.back());
			int med = N/2;
			swap(ans[1], ans[med]);
			for (int i = 0; i < N; ++i) {
				cout << ans[i] << (i == N-1 ? '\n' : ' ');
			}
		}
				
	}();
}
