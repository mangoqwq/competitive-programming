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
	int N = 1e7;
	vector<int> prime(sieve(N));
	auto right_truncatable = [&](string n) {
		while (!n.empty()) {
			if (!prime[stoi(n)]) return 0;
			n.pop_back();
		}
		return 1;
	};
	auto left_truncatable = [&](string n) {
		while (!n.empty()) {
			if (!prime[stoi(n)]) return 0;
			n.erase(n.begin());
		}
		return 1;
	};
	int ans = 0;
	for (int i = 10; i <= N; ++i) {
		if (!prime[i]) continue;
		if (left_truncatable(to_string(i)) && right_truncatable(to_string(i))) {
			debug(i);
			ans += i;
		}
	}
	cout << ans << '\n';
}
