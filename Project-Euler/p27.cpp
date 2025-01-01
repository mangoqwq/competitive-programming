#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

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
	return prime;
}


int main() {
	cin.tie(0)->sync_with_stdio(0);
	auto prime = sieve(2e6);
	auto is_prime = [&](int x) {
		return x >= 0 && prime[x];
	};
	tuple<int, int, int> ans;
	for (int a = -999; a < 999; ++a) {
		for (int b = -1000; b <= 1000; ++b) {
			int i = 0;
			while (is_prime(i * i + a * i + b)) i++;
			ans = max(ans, {i, a, b});
		}
	}
	debug(ans);
	cout << get<1>(ans) * get<2>(ans) << '\n';
}
