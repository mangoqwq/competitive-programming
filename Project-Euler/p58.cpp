#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

bool prime(ll N) {
	for (ll i = 2; i * i <= N; ++i) {
		if (N % i == 0) return 0;
	}
	return 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int cnt = 0;
	for (ll sz = 3; ; sz += 2) {
		cnt += prime(sz*sz - 1*(sz-1));
		cnt += prime(sz*sz - 2*(sz-1));
		cnt += prime(sz*sz - 3*(sz-1));
		if (cnt * 10 < 2*sz-1) {
			cout << sz << '\n';
			break;
		}
	}
}
