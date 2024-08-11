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
		vector<int> h(N);
		for (int i = 0; i < N; ++i) {
			cin >> h[i];
		}
		int ans = 0;
		for (int i = N-1; i >= 0; --i) {
			ans = max(ans+1, h[i]);
		}
		cout << ans << '\n';
	}();
}
