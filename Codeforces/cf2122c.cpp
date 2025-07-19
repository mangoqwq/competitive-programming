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
		int N; cin >> N;
		vector<ll> x(N), y(N);
		for (int i = 0; i < N; ++i) {
			cin >> x[i] >> y[i];
		}

		vector<int> ord_x(N), ord_y(N);
		iota(ord_x.begin(), ord_x.end(), 0);
		iota(ord_y.begin(), ord_y.end(), 0);
		ranges::sort(ord_x, [&](int i, int j) { return x[i] < x[j]; });
		ranges::sort(ord_y, [&](int i, int j) { return y[i] < y[j]; });
		vector<int> pos_x(N), pos_y(N);
		for (int i = 0; i < N; ++i) {
			pos_x[ord_x[i]] = i;
			pos_y[ord_y[i]] = i;
		}

		vector<vector<vector<int>>> quad(2, vector<vector<int>>(2));
		for (int i = 0; i < N; ++i) {
			quad[pos_x[i] < N / 2][pos_y[i] < N / 2].push_back(i);
		}

		for (int i = 0; i < (int)quad[0][0].size(); ++i) {
			cout << quad[0][0][i] + 1 << " " << quad[1][1][i] + 1 << '\n';
		}
		for (int i = 0; i < (int)quad[1][0].size(); ++i) {
			cout << quad[1][0][i] + 1 << " " << quad[0][1][i] + 1 << '\n';
		}
	}();
}
