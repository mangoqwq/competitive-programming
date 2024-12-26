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
		int N, M; cin >> N >> M;
		vector<int> a(M);
		for (int i = 0; i < M; ++i) {
			cin >> a[i];
		}
		reverse(a.begin(), a.end());
		vector<int> divs(N + 1), ans(N + 1);
		for (int i = 1; i <= N; ++i) {
			if (divs[i] >= M) {
				cout << -1 << '\n';
				return;
			}
			ans[i] = a[divs[i]];
			for (int j = 2*i; j <= N; j += i) divs[j] = max(divs[j], divs[i] + 1);
		}
		for (int i = 1; i <= N; ++i) {
			cout << ans[i] << (i == N ? '\n' : ' ');
		}
	}();
}
