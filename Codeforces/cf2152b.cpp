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
	int T; cin >> T;
	while (T--) [&]() {
		int N, RK, CK, RD, CD; cin >> N >> RK >> CK >> RD >> CD;
		if (RK >= RD) {
			RK = N - RK;
			RD = N - RD;
		}
		if (CK >= CD) {
			CK = N - CK;
			CD = N - CD;
		}
		debug(RK, CK, RD, CD);
		if (RK == RD) {
			cout << CD << '\n';
			return;
		}
		if (CK == CD) {
			cout << RD << '\n';
			return;
		}
		cout << max(RD, CD) << '\n';
	}();
}
