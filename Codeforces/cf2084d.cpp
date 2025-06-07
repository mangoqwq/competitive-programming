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
		int N, M, K; cin >> N >> K >> M; // swapped K and M..
		int ans = 0, arg = 0;
		for (int p = M; p <= N; ++p) {
			int small = N / p + (N % p >= M);
			int big = N / p;
			int cur = 0;
			if (small == K && N % p < M) {
				cur = N % p;
			}
			else if (small > K && big == K) {
				cur = M;
			}
			else if (small > K && big > K) {
				cur = p;
			}
			if (cur > ans) {
				ans = cur;
				arg = p;
			}
		}
		debug(ans);
		for (int i = 0; i < N; ++i) {
			cout << i % arg << (i == N-1 ? '\n' : ' ');
		}
	}();
}
