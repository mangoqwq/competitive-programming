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
	const int MN = 1e7;
	vector<pair<int, int>> sum2(MN + 1, {-1, -1});
	for (int i = 0; i * i <= MN; ++i) {
		for (int j = 0; j * j + i * i <= MN; ++j) {
			sum2[i * i + j * j] = {i, j};
		}
	}

	int T; cin >> T;
	while (T--) [&]() {
		int N; cin >> N;
		for (int i = 0; i <= N; ++i) {
			if (sum2[i].first != -1 && sum2[N - i].first != -1) {
				auto [a, b] = sum2[i];
				auto [c, d] = sum2[N - i];
				cout << a << " " << b << " " << c << " " << d << '\n';
				return;
			}
		}
	}();
}
