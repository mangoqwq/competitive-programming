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
	set<ll> tri, pent, hexa;
	int N = 1e6;
	for (ll i = 1; i < N; ++i) {
		tri.insert(i * (i + 1) / 2);
		pent.insert(i * (3 * i - 1) / 2);
		hexa.insert(i * (2 * i - 1));
	}
	for (ll n : tri) {
		if (pent.contains(n) && hexa.contains(n) && n > 40755) {
			cout << n << '\n';
			break;
		}
	}
}
