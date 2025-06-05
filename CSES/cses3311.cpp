#include <bits/stdc++.h>

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	int N, M; std::cin >> N >> M;
	std::vector<std::vector<int>> ans(N, std::vector<int>(M));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			std::set<int> can = {0, 1, 2, 3};
			if (i) can.erase(ans[i - 1][j]);
			if (j) can.erase(ans[i][j - 1]);
			char c; std::cin >> c;
			can.erase(c - 'A');
			ans[i][j] = *can.begin();
			std::cout << char(ans[i][j] + 'A');
		}
		std::cout << '\n';
	}
}
