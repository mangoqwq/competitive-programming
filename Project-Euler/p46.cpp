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
	auto primes = sieve(1e6);
	vector<int> can(1e7);
	for (int p : primes) {
		for (int s = 0; s < 1e3; ++s) {
			can[2 * s * s + p] = 1;
		}
	}
	for (int i = 3; ; i += 2) {
		if (!can[i]) {
			cout << i << '\n';
			break;
		}
	}
}
