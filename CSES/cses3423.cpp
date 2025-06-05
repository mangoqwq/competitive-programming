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
	auto primes = sieve(2e5);
	int N; cin >> N;
	vector<int> b(N + 1);
	auto solve = [&b, &primes](auto self, int n) -> void {
		if (n == 0) return;
		int np = *ranges::upper_bound(primes, n);
		int k = np - n;
		for (int i = k; i <= n; ++i) {
			b[i] = np - i;
		}
		self(self, k - 1);
	};
	solve(solve, N);

	for (int i = 1; i <= N; ++i) {
		cout << i << (i == N ? '\n' : ' ');
	}
	for (int i = 1; i <= N; ++i) {
		cout << b[i] << (i == N ? '\n' : ' ');
	}
}
