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
		int N, M, K; cin >> N >> M >> K;
		vector<vector<ll>> a(N, vector<ll>(M));
		vector<vector<int>> typ(N, vector<int>(M));
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
			cin >> a[i][j];
		}
		vector<vector<int>> cnt(N+1, vector<int>(M+1));
		ll diff = 0;
		for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
			char c; cin >> c;
			typ[i][j] = c == '1';
			if (typ[i][j] == 1) diff += a[i][j];
			else diff -= a[i][j];
			cnt[i+1][j+1] = cnt[i][j+1] + cnt[i+1][j] - cnt[i][j] + typ[i][j];
		}
		if (diff == 0) {
			cout << "YES" << '\n';
			return;
		}
		int d = -1;
		for (int i = K; i <= N; ++i) for (int j = K; j <= M; ++j) {
			int nocap = cnt[i][j] - cnt[i-K][j] - cnt[i][j-K] + cnt[i-K][j-K];
			int cap = K*K - nocap;
			int val = abs(cap - nocap);
			if (val == 0) continue;
			if (d == -1) d = val;
			else d = gcd(d, val);
		}
		if (d <= 0) cout << "NO" << '\n';
		else cout << (diff % d == 0 ? "YES" : "NO") << '\n';
	}();
}
