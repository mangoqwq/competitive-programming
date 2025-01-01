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
	const int N = 1e6;
	vector<int> prime = sieve(N);
	int ans = 0;
	for (int i = 1; i < N; ++i) {
		bool circular = [&]() -> bool {
			string s = to_string(i);
			for (int r = 0; r < (int)s.size(); ++r) {
				if (!prime[stoi(s)]) return 0;
				rotate(s.begin(), s.begin() + 1, s.end());
			}
			return 1;
		}();
		ans += circular;
	}
	cout << ans << '\n';
}
