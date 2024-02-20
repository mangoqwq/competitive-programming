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
		int N, Q; cin >> N >> Q;
		int L = __lg(N-1);
		int all = (1 << (L + 1)) - 1;

		int ans = 0;
		auto ins = [&](auto self, int x, vector<int> &v1, vector<int> &v2) {
			if (v1[x]) return;
			v1[x] = 1;
			if (v2[x]) ans = max(ans, x);
			for (int i = L; i >= 0; --i) {
				if (1 & (x >> i)) self(self, x - (1 << i), v1, v2);
			}
		};
		vector<int> a(all+1), b(all+1);

		for (int i = 0; i < Q; ++i) {
			int x; cin >> x;
			x = (ans + x) % N;
			ins(ins, x, a, b);
			ins(ins, all-x, b, a);
			cout << ans << (i == Q-1 ? '\n' : ' ');
		}
	}();
}
