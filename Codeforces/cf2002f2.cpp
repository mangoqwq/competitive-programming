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

int fgcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;

    int az = __builtin_ctz(a);
    int bz = __builtin_ctz(b);
    int shift = std::min(az, bz);
    b >>= bz;
    
    while (a != 0) {
        a >>= az;
        int diff = b - a;
        az = __builtin_ctz(diff);
        b = std::min(a, b);
        a = std::abs(diff);
    }
    
    return b << shift;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	auto primes = sieve(2e7 + 1e4);
	const int ggap = 190;
	int T; cin >> T;
	while (T--) [&]() {
		int N, M; ll L, F; cin >> N >> M >> L >> F;
		if (N < M) swap(L, F), swap(N, M);
		ll ans = 0;
		{
			int P = *(--upper_bound(primes.begin(), primes.end(), N));
			ans = max(ans, L * P + F * min(M, P-1));
			int gap = N - P + 5;
			int sx = P, sy = max(M-ggap, 1);
			vector<vector<int>> can(gap + 5, vector<int>(gap + ggap + 5));
			can[0][0] = 1;
			for (int i = 0; sx + i <= N; ++i) {
				for (int j = 0; sy + j <= M; ++j) {
					if (!can[i][j]) continue;
					if (fgcd(sx + i + 1, sy + j) <= 1) can[i+1][j] = 1;
					if (fgcd(sx + i, sy + j + 1) <= 1) can[i][j+1] = 1;
					// debug(sx + i, sy + j);
					ans = max(ans, L * (sx + i) + F * (sy + j));
				}
			}
		}
		{
			int P = *(--upper_bound(primes.begin(), primes.end(), M));
			ans = max(ans, L * P + F * min(N, P-1));
			int gap = M - P + 5;
			int sx = max(N-ggap, 1), sy = P;
			vector<vector<int>> can(gap + ggap + 5, vector<int>(gap + 5));
			can[0][0] = 1;
			for (int i = 0; sx + i <= N; ++i) {
				for (int j = 0; sy + j <= M; ++j) {
					if (!can[i][j]) continue;
					if (fgcd(sx + i + 1, sy + j) <= 1) can[i+1][j] = 1;
					if (fgcd(sx + i, sy + j + 1) <= 1) can[i][j+1] = 1;
					// debug(sx + i, sy + j);
					ans = max(ans, L * (sx + i) + F * (sy + j));
				}
			}
		}
		cout << ans << '\n';
	}();
}
