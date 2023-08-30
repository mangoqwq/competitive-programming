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
		vector<int> pos(N);
		for (int i = 0; i < N; ++i) {
			int x; cin >> x;
			x--;
			pos[x] = i;
		}
		int ans = 0;
		for (int i = 1; i < N; ++i) {
			if (pos[i] < pos[i-1]) ans++;
		}
		cout << ans << '\n';
	}();
}
