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
		int N, X; cin >> N >> X;
		vector<vector<int>> stk(3, vector<int>(N));
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < N; ++j) {
				cin >> stk[i][j];
			}
			reverse(stk[i].begin(), stk[i].end());
		}

		int cur = 0;
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < 3; ++j) {
				if ((stk[j].back() | X) == X) {
					cur = cur | stk[j].back();
					stk[j].pop_back();
				}
			}
		}
		cout << (cur == X ? "Yes" : "No") << '\n';
	}();
}
