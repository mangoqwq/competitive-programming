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
		int N, K; cin >> N >> K;
		if (N == K) {
			for (int i = 1; i <= N; ++i) {
				cout << 1 << (i == N ? '\n' : ' ');
			}
		}
		else if (K == 1) {
			for (int i = 1; i <= N; ++i) {
				cout << i << (i == N ? '\n' : ' ');
			}
		}
		else {
			cout << -1 << '\n';
		}
	}();
}
