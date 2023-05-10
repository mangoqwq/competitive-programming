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
		int N, M; cin >> N >> M;
		vector<int> fix = {0, M+1};
		int l = 0, r = 0;
		for (int i = 0; i < N; ++i) {
			int a; cin >> a;
			if (a == -1) l++;
			else if (a == -2) r++;
			else fix.push_back(a);
		}
		sort(fix.begin(), fix.end());
		fix.resize(unique(fix.begin(), fix.end()) - fix.begin());
		int ans = fix.size() - 2;
		int seen = 0, left = fix.size() - 2;
		for (int c : fix) {
			int real = c != 0 && c != M+1;
			if (real) {
				left--;
			}
			int maxl = max(0, c-1);
			int maxr = max(0, M-c);
			int accl = seen + l;
			int accr = left + r;
			ans = max(ans, min(accl, maxl) + min(accr, maxr) + real);
			if (real) {
				seen++;
			}
		}
		cout << ans << '\n';
	}();
}
