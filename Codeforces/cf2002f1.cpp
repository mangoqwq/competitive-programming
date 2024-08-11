#include <bits/stdc++.h>
#pragma GCC optimize ("O3")

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

// Returns all the primes <= N
// Runtime: O(NloglogN)
vector<int> sieve(int N) {
	vector<int> prime(N+1, 1);
	vector<int> primes;
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= N; ++i) {
		if (!prime[i]) continue;
		primes.push_back(i);
		for (ll j = 1LL * i * i; j <= N; j += i) {
			prime[j] = 0;
		}
	}
	return primes;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	auto primes = sieve(2e7 + 1e4);
	const int ggap = 185;
	int T; cin >> T;
	while (T--) [&]() {
		int N, M; ll L, F; cin >> N >> M >> L >> F;
		if (L > F) swap(L, F); // assume L <= F
		int P = *(--upper_bound(primes.begin(), primes.end(), N));
		// int nxtP = *(upper_bound(primes.begin(), primes.end(), N));
		ll ans = F * P + L * (P-1);

		int gap = N - P + 5;
		int sx = P, sy = max(P-ggap, 1);
		vector<vector<int>> can(gap + 5, vector<int>(gap + ggap + 5));
		can[0][0] = 1;
		for (int i = 0; sx + i <= N; ++i) {
			for (int j = 0; sy + j <= M; ++j) {
				if (!can[i][j]) continue;
				if (gcd(sx + i + 1, sy + j) <= 1) can[i+1][j] = 1;
				if (gcd(sx + i, sy + j + 1) <= 1) can[i][j+1] = 1;
				// debug(i, j);
				ans = max(ans, F * max(sx + i, sy + j) + L * min(sx + i, sy + j));
			}
		}
		cout << ans << '\n';
	}();
}
