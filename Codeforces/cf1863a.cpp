#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int N, A, Q; cin >> N >> A >> Q;
		int uniq = A, mx = A;
		while (Q--) {
			char c; cin >> c;
			if (c == '-') A--;
			else A++, uniq++;
			mx = max(mx, A);
		}
		if (mx == N) cout << "YES" << '\n';
		else if (uniq >= N) cout << "MAYBE" << '\n';
		else cout << "NO" << '\n';
	}();
}
