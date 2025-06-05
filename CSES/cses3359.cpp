#include <bits/stdc++.h>

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	int N; std::cin >> N;
	std::vector<std::string> g(N);
	for (auto &s : g) std::cin >> s;
	std::vector<std::vector<int>> dp(N + 1, std::vector<int>(N + 1, N - 1));
	std::vector<std::vector<std::pair<int, int>>> diags(2 * N - 1);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			diags[i + j].emplace_back(i, j);
		}
	}
	for (int sum = 2 * N - 2; sum >= 0; --sum) {
		struct Item {
			int i, j, prio;
		};
		std::vector<Item> items;
		for (auto [i, j] : diags[sum]) {
			int prio = (g[i][j] - 'A') * N + std::min(dp[i + 1][j], dp[i][j + 1]);
			items.emplace_back(i, j, prio);
		}
		std::ranges::sort(items, {}, [&](Item a) { return a.prio; }); 
		int T = 0;
		for (auto [i, j, _] : items) {
			dp[i][j] = T++;
		}
	}
	int n = 0, m = 0;
	for (int i = 0; i <= 2 * N - 2; ++i) {
		std::cout << g[n][m];
		if (dp[n + 1][m] < dp[n][m + 1]) n++;
		else m++;
	}
	std::cout << '\n';
}
