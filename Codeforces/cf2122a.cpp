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
		int N, M; cin >> N >> M;
		if (N == 1 || M == 1 || max(N, M) <= 2) {
			cout << "NO" << '\n';
		}
		else cout << "YES" << '\n';
	}();
}
