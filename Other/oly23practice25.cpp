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
	int N, M; cin >> N >> M;
	vector<vector<int>> got(N, vector<int>(M));
	int ans = 0;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			char c; cin >> c;
			if (c == '#') {
				if (!got[i][j]) ans++;
				if (i != N-1) got[i+1][j] = 1;
				if (j != M-1) got[i][j+1] = 1;
			}
		}
	}
	cout << ans << '\n';
}
