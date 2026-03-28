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
		int N; cin >> N;
		set<int> s;
		for (int i = 0; i < N; ++i) {
			int x; cin >> x;
			s.insert(x);
		}
		int ans = 2 * s.size() - 1;
		cout << ans << '\n';
	}();
}

