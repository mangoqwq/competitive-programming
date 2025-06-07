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
	int N, M; cin >> N >> M;
	vector<vector<ll>> a(N, vector<ll>(M+1));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cin >> a[i][j+1];
			a[i][j+1] += a[i][j];
		}
	}
	int ans = 0;
	for (int j1 = 0; j1 < M; ++j1) {
		for (int j2 = j1+2; j2 <= M; j2 += 2) {
			int jm = (j1 + j2) >> 1;
			map<ll, int> seen;
			seen[0] = 0;
			vector<ll> val(N+1);
			for (int i = 0; i < N; ++i) {
				val[i+1] = val[i] + (a[i][j2] - a[i][jm]) - (a[i][jm] - a[i][j1]);
				if (seen.count(val[i+1])) {
					// debug(j1, j2, seen[val[i+1]], i);
					ans = max(ans, (j2 - j1) * (i+1 - seen[val[i+1]]));
				}
				if (!seen.count(val[i+1])) seen[val[i+1]] = i+1;
			}
			debug(j1, j2, val);
		}
	}
	cout << ans << '\n';
}
