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
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}
		vector<int> pre(N+1), suf(N+1);
		for (int i = 2; i <= N; ++i) {
			if (a[i-1] >= a[i-2]) pre[i] = pre[i-1] + 1;
			else pre[i] = pre[i-1];
		}
		for (int i = N-2; i >= 0; --i) {
			if (a[i] >= a[i+1]) suf[i] = suf[i+1] + 1;
			else suf[i] = suf[i+1];
		}
		debug(pre);
		debug(suf);
		int ans = min(1+pre[N], suf[0]);
		for (int i = 1; i < N; ++i) {
			ans = min(ans, 1 + pre[i] + suf[i]);
		}
		cout << ans << '\n';
	}();
}
