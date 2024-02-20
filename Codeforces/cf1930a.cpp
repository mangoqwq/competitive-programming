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
		N *= 2;
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}		
		sort(a.begin(), a.end());
		int ans = 0;
		for (int i = 0; i < N; i += 2) {
			ans += a[i];
		}
		cout << ans << '\n';
	}();
}
