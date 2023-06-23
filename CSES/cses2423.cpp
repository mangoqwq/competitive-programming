#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

/*
lots of casework
first if neither n or m are divisible by 3, then its impossible

WLOG assume 3 | m
if n is even, we done since we can tile with 2x3 rectangles
so say n is odd. we do casework on m

m = 3:
not hard to see impossible

m = 6k:
yes iff n != 1
do a 3 by 6k tiling with 3x2s
then it becomes even n case

m = 6k+3:
yes iff n != 1 and n != 3 (so n >= 5)
theres this magical 5x9 tiling
||---||||
||---||||
||@$$||||
$@@.$@---
$$..@@---
fill in the rest with 2x3 and 3x2
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int N, M; cin >> N >> M;

		bool trans = 0;
		if (N % 3 == 0) {
			swap(N, M);
			trans = 1;
		}

		int T = 0;
		vector<vector<int>> ans(N, vector<int>(M));
		auto go2x3 = [&](int i, int j) {
			ans[i][j] = T;
			ans[i+1][j] = T;
			ans[i][j+1] = T;
			T++;
			ans[i+1][j+1] = T;
			ans[i][j+2] = T;
			ans[i+1][j+2] = T;
			T++;
		};

		auto go3x2 = [&](int i, int j) {
			ans[i][j] = T;
			ans[i+1][j] = T;
			ans[i][j+1] = T;
			T++;
			ans[i+1][j+1] = T;
			ans[i+2][j] = T;
			ans[i+2][j+1] = T;
			T++;
		};

/*
 012345678
0||---||||
1||---||||
2||@##||||
3$@@.#?---
4$$..??---
*/
		auto go5x9 = [&](int i, int j) {
			go3x2(i, j);
			go2x3(i, j+2);
			go3x2(i, j+5);
			go3x2(i, j+7);
			go2x3(i+3, i+6);

			// $
			ans[i+3][j] = T;
			ans[i+4][j] = T;
			ans[i+4][j+1] = T;
			T++;
			// @
			ans[i+2][j+2] = T;
			ans[i+3][j+2] = T;
			ans[i+3][j+1] = T;
			T++;
			// #
			ans[i+2][j+3] = T;
			ans[i+2][j+4] = T;
			ans[i+3][j+4] = T;
			T++;
			// .
			ans[i+3][j+3] = T;
			ans[i+4][j+3] = T;
			ans[i+4][j+2] = T;
			T++;
			// ?
			ans[i+4][j+4] = T;
			ans[i+4][j+5] = T;
			ans[i+3][j+5] = T;
			T++;
		};

		if (M % 3) {
			cout << "NO" << '\n';
			return;
		}
		else if (N % 2 == 0) {
			for (int i = 0; i < N; i += 2) {
				for (int j = 0; j < M; j += 3) {
					go2x3(i, j);
				}
			}
		}
		else if (M == 3) {
			cout << "NO" << '\n';
			return;
		}
		else if (M % 6 == 0) {
			if (N == 1) {
				cout << "NO" << '\n';
				return;
			}
			for (int j = 0; j < M; j += 2) {
				go3x2(0, j);
			}
			for (int i = 3; i < N; i += 2) {
				for (int j = 0; j < M; j += 3) {
					go2x3(i, j);
				}
			}
		}
		else { // M % 6 == 3
			if (N < 5) {
				cout << "NO" << '\n';
				return;
			}
			go5x9(0, 0);

			for (int j = 9; j < M; j += 2) {
				go3x2(0, j);
			}
			for (int i = 3; i < N; i += 2) {
				for (int j = 9; j < M; j += 3) {
					go2x3(i, j);
				}
			}
			for (int i = 5; i < N; i += 2) {
				for (int j = 0; j < 9; j += 3) {
					go2x3(i, j);
				}
			}
		}

		// time to color!
		auto mex = [&](set<char> s) -> char {
			for (char i = 'A'; ; ++i) {
				if (!s.count(i)) return i;
			}
		};
		const int dx[] = {-1, 0, 1, 0};
		const int dy[] = {0, 1, 0, -1};

		vector<vector<char>> tiling(N, vector<char>(M));
		using pii = pair<int, int>;
		vector<vector<pii>> loc(T);
		auto recolour = [&](int c) {
			set<char> s;
			for (auto [i, j] : loc[c]) {
				for (int d = 0; d < 4; ++d) {
					int nx = i + dx[d], ny = j + dy[d];
					if (nx >= 0 && nx < N && ny >= 0 && ny < M) {
						s.insert(tiling[nx][ny]);
					}
				}
			}
			char color = mex(s);
			for (auto [i, j] : loc[c]) {
				if (ans[i][j] == c) {
					tiling[i][j] = color;
				}
			}
		};
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < M; ++j) {
				loc[ans[i][j]].push_back({i, j});
			}
		}
		for (int i = 0; i < T; ++i) {
			recolour(i);
		}

		cout << "YES" << '\n';
		if (!trans) {
			for (int i = 0; i < N; ++i) {
				for (int j = 0; j < M; ++j) {
					cout << tiling[i][j];
				}
				cout << '\n';
			}
		}
		else {
			for (int j = 0; j < M; ++j) {
				for (int i = 0; i < N; ++i) {
					cout << tiling[i][j];
				}
				cout << '\n';
			}
		}
	}();
}
