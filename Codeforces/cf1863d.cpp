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
		vector<vector<char>> c(N, vector<char>(M));
		vector<int> rc(N), cc(M);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cin >> c[i][j];
				if (c[i][j] != '.') rc[i]++, cc[j]++;
			}
		}
		
		for (int i = 0; i < N; ++i) {
			if (rc[i] % 2) {
				cout << -1 << '\n';
				return;
			}
		}
		for (int j = 0; j < M; ++j) {
			if (cc[j] % 2) {
				cout << -1 << '\n';
				return;
			}
		}

		for (int i = 0; i < N-1; ++i) {
			int k = -1;
			for (int j = 0; j < M; ++j) {
				if (c[i][j] == 'U' && c[i+1][j] == 'D') {
					if (k == -1) k = j;
					else {
						c[i][k] = 'B';
						c[i+1][k] = 'W';
						c[i][j] = 'W';
						c[i+1][j] = 'B';
						k = -1;
					}
				}
			}
		}

		for (int j = 0; j < M-1; ++j) {
			int k = -1;
			for (int i = 0; i < N; ++i) {
				if (c[i][j] == 'L' && c[i][j+1] == 'R') {
					if (k == -1) k = i;
					else {
						c[k][j] = 'B';
						c[k][j+1] = 'W';
						c[i][j] = 'W';
						c[i][j+1] = 'B';
						k = -1;
					}
				}
			}
		}

		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				cout << c[i][j];
			}
			cout << '\n';
		}
	}();
}
