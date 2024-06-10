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
			psa[i] = psa[i-1] + a[i-1];
		}
		ll ans = psa[N];
		for (int i = 0; i < N; ++i) {
			ans = max(ans, abs(psa[i+1]) + psa[N] - psa[i+1]);
		}
		cout << ans << '\n';
	}();
}
