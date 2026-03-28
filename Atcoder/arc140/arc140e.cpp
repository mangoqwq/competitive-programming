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
	int p = 23;
	vector<vector<int>> table(p * p, vector<int>(p * p));
	auto color = [&](int i, int j) {
		for (int k = 0; k < p; ++k) {
			table[i][j] = k;
			j++;
			if (j % p == 0) j -= p;
		}
	};
	for (int b = 0; b < p; ++b) {
		for (int r = 0; r < p; ++r) {
			for (int c = 0; c < (p - 1); ++c) {
				color(b * p + r, c * p + (r + c * b) % p);
			}
			color(b * p + r, (p - 1) * p + b);
		}
	}
	int N, M; cin >> N >> M;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			cout << table[i][j] + 1 << (j == M - 1 ? '\n' : ' ');
		}
	}
}
