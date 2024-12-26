#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	ll N = 600851475143;
	vector<ll> divisors;
	for (ll i = 2; i * i <= N; ++i) {
		while (N % i == 0) {
			divisors.push_back(i);
			N /= i;
		}
	}
	if (N > 1) divisors.push_back(N);
	cout << divisors.back() << '\n';
}
