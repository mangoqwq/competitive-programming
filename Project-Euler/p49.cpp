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
	vector<int> prime = sieve(1e4);
	for (int b = 1e3; b < 1e4; ++b) {
		for (int d = 1; b + 2*d < 1e4; ++d) {
			int v1 = b;
			int v2 = b + d;
			int v3 = b + 2 * d;
			if (!prime[v1] || !prime[v2] || !prime[v3]) continue;
			string s1 = to_string(v1);
			string s2 = to_string(v2);
			string s3 = to_string(v3);
			multiset<char> ms1(s1.begin(), s1.end());
			multiset<char> ms2(s2.begin(), s2.end());
			multiset<char> ms3(s3.begin(), s3.end());
			if (ms1 != ms2 || ms2 != ms3) continue;
			cout << s1 << s2 << s3 << '\n';
		}
	}
}
