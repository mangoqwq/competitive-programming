#include <bits/stdc++.h>

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
	int want = 5000;

	auto primes = sieve(1000);
	int K = primes.size();
	// dp[i][k] = # of ways to write i from the first k primes
	vector<vector<int>> dp(1, vector<int>(K, 1));
	for (int i = 1; ; ++i) {
		dp.emplace_back(K, 0);
		for (int k = 0; k < K; ++k) {
			for (int j = 0; j <= k && primes[j] <= i; ++j) {
				dp[i][k] += dp[i - primes[j]][j];
			}
			if (dp[i][k] > want) {
				cout << i << '\n';
				exit(0);
			}
		}
	}
}
