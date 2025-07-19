#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

pair<vector<int>, vector<int>> sieve(int N) {
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
	return {primes, prime};
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	auto [primes, prime] = sieve(1e6);
	pair<int, int> ans = {1, 2};
	for (int i = 0; i < (int)primes.size(); ++i) {
		ll sum = 0;
		for (int j = i; j < (int)primes.size() && sum < 1e6; ++j) {
			sum += primes[j];
			if (sum < 1e6 && prime[sum]) {
				ans = max(ans, {j - i + 1, sum});
			}
		}
	}
	debug(ans);
	cout << ans.second << '\n';
}
