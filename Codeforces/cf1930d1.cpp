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
		int N; cin >> N;
		string s; cin >> s;
		ll ans = 0;
		for (int l = 0; l < N; ++l) {
			int need = 0, lst = -1000, nxt = -1;
			for (int i = l; i < N; ++i) {
				if (nxt == i) {
					need++; nxt = -1; lst = i;
				}
				if (s[i] == '1') {
					if (lst < i-1) nxt = i+1;
				}
				ans += need + (nxt != -1);
			}
		}
		cout << ans << '\n';
	}();
}
