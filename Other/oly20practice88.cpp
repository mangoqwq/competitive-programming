#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

ll dp[201][201][64][2];
bool vis[201][201][64][2];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; ll M; cin >> N >> M;
	vector<ll> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<ll> psa(N+1);
	for (int i = 1; i <= N; ++i) {
		psa[i] = psa[i-1] + a[i-1];
	}
	auto qry = [&](int l, int r) -> ll {
		return psa[r] - psa[l];
	};

	const ll inf = 4e18;
	auto get = [&](int l, int r, int b, int lim) -> ll {
		if (l == r) return 0;
		if (b == -1) return (l+1 == r ? 0 : -inf);
		return dp[l][r][b][lim];
	};

	for (int sz = 1; sz <= N; ++sz) {
		for (int l = 0; l + sz <= N; ++l) {
			int r = l + sz;
			for (int b = 0; b <= 63; ++b) {
				dp[l][r][b][0] = dp[l][r][b][1] = -inf;
				if (!(1 & (M >> b))) {
					dp[l][r][b][1] = get(l, r, b-1, 1);
				}
				for (int i = l; i <= r; ++i) {
					for (int lim = 0; lim <= 1; ++lim) {
						if (lim && !(1 & (M >> b))) continue;
						ll &cur = dp[l][r][b][lim];
						cur = max(cur, get(l, i, b-1, 0) + get(i, r, b-1, lim) + qry(i, r));
					}
				}
			}
		}
	}

	cout << dp[0][N][63][1] << '\n';
}
