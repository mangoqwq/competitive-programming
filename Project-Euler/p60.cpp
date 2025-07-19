#include <bits/stdc++.h>
#include <numeric>

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

bool is_prime(ll N) {
	for (ll i = 2; i * i <= N; ++i) {
		if (N % i == 0) return 0;
	}
	return 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	vector<int> primes = sieve(1e4);
	vector<int> cur, best;
	int ans = 1e9;
	auto search = [&](auto self, vector<int>::iterator it, int cnt) {
		if (cnt == 5) {
			int sum = accumulate(cur.begin(), cur.end(), 0);
			if (sum < ans) {
				best = cur, ans = sum;
				debug(ans, best);
			}
			return;
		}
		if (it == primes.end()) return;
		bool valid = [&]() -> bool {
			for (int x : cur) {
				if (!is_prime(stoll(to_string(*it) + to_string(x)))) return 0;
				if (!is_prime(stoll(to_string(x) + to_string(*it)))) return 0;
			}
			return 1;
		}();
		if (valid) {
			cur.push_back(*it);
			self(self, it+1, cnt+1);
			cur.pop_back();
		}
		self(self, it+1, cnt);
	};
	search(search, primes.begin(), 0);
	cout << ans << '\n';
}
