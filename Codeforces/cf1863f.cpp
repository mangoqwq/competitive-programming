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
		vector<ll> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}

		vector<ll> psa(N+1);
		for (int i = 1; i <= N; ++i) {
			psa[i] = psa[i-1] ^ a[i-1];
		}
		auto get = [&](int l, int r) { return psa[r]^psa[l]; };

		vector<ll> leq(N+1), req(N+1), lm(N+1), rm(N+1);
		auto ins = [&](int l, int r) {
			if (get(l, r) == 0) leq[l] = req[r] = 1;
			lm[l] |= (1LL << __lg(get(l, r)));
			rm[r] |= (1LL << __lg(get(l, r)));
		};
		auto ok = [&](int l, int r) -> bool {
			return leq[l] || req[r] || (lm[l] & get(l, r)) || (rm[r] & get(l, r));
		};
		ins(0, N);
		for (int sz = N-1; sz >= 2; --sz) {
			for (int l = 0; l + sz <= N; ++l) {
				int r = l+sz;
				if (ok(l, r)) ins(l, r);
			}
		}

		for (int i = 0; i < N; ++i) {
			cout << ok(i, i+1);
		}
		cout << '\n';
	}();
}
