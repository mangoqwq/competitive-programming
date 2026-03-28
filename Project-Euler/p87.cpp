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
std::vector<int> sieve(int N) {
	std::vector<int> prime(N+1, 1);
	std::vector<int> primes;
	prime[0] = prime[1] = 0;
	for (int i = 2; i <= N; ++i) {
		if (!prime[i]) continue;
		primes.push_back(i);
		for (long long j = 1LL * i * i; j <= N; j += i) {
			prime[j] = 0;
		}
	}
	return primes;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	const int L = 50e6;
	auto primes = sieve(L);
	set<ll> can;
	for (ll p2 : primes) {
		if (p2 * p2 > L) break;
		for (ll p3 : primes) {
			if (p2 * p2 + p3 * p3 * p3 > L) break;
			for (ll p4 : primes) {
				if (p2 * p2 + p3 * p3 * p3 + p4 * p4 * p4 * p4 > L) break;
				can.insert(p2 * p2 + p3 * p3 * p3 + p4 * p4 * p4 * p4);
			}
		}
	}
	cout << can.size() << '\n';
}
