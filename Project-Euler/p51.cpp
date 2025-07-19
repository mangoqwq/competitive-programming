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
	for (int i = 1; i < N; ++i) {
		if (!prime[i]) continue;
		int len = to_string(i).length();
		for (int msk = 1; msk < (1 << len); ++msk) {
			vector<int> family;
			for (char d = '0'; d <= '9'; ++d) {
				if (d == '0' && (msk & 1)) continue;
				string num = to_string(i);
				for (int b = 0; b < len; ++b) {
					if (1 & (msk >> b)) num[b] = d;
				}
				if (prime[stoi(num)]) family.push_back(stoi(num));
			}
			if ((int)family.size() >= 8 && i == family[0]) {
				cout << i << '\n';
				debug(family);
			}
		}
	}
}

