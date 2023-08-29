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
		if (N == 1 || M == 1) {
			cout << -1 << '\n';
			return;
		}
		vector<vector<int>> a(N, vector<int>(M));
		int T = N*M;
		auto touch = [&](int i, int j) {
			a[i][j] = T--;
		};
		if (N % 2 == 1 && M % 2 == 1) {
			for (int i = 0; i < N; ++i) touch(i, 0);
			for (int j = 1; j < M; ++j) touch(N-1, j);
			for (int j = M-1; j > 2; --j) {
				if (((M-1) - j) % 2 == 0) {
					for (int i = N-2; i >= 0; --i) touch(i, j);
				}
				else for (int i = 0; i <= N-2; ++i) touch(i, j);
			}
			for (int i = N-2; i >= 0; --i) {
				if (((N-2) - i) % 2 == 0) {
					touch(i, 2);
					touch(i, 1);
				}
				else {
					touch(i, 1);
					touch(i, 2);
				}
			}
		}
		else {
			if (M % 2 == 0) {
				for (int i = 0; i < N; ++i) touch(i, 0);
				for (int j = 1; j < M; ++j) touch(N-1, j);
				for (int j = M-1; j > 0; --j) {
					if (((M-1) - j) % 2 == 0) {
						for (int i = N-2; i >= 0; --i) touch(i, j);
					}
					else for (int i = 0; i <= N-2; ++i) touch(i, j);
				}
			}
			else {
				for (int j = 0; j < M; ++j) touch(0, j);
				for (int i = 1; i < N; ++i) touch(i, M-1);
				for (int i = N-1; i > 0; --i) {
					if (((N-1) - i) % 2 == 0) {
						for (int j = M-2; j >= 0; --j) touch(i, j);
					}
					else for (int j = 0; j <= M-2; ++j) touch(i, j);
				}
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cout << a[i][j] << (j == M-1 ? '\n' : ' ');
			}
		}
	}();
}
