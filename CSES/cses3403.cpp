#include <bits/stdc++.h>

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

struct Object {
	int x;
	std::vector<int> v;
};

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	int N, M; std::cin >> N >> M;
	std::vector<int> a(N), b(M);
	for (int &x : a) std::cin >> x;
	for (int &x : b) std::cin >> x;

	std::vector<std::vector<int>> dp(N + 1, std::vector<int>(M + 1));
	for (int i = 1; i <= N; ++i) {
		for (int j = 1; j <= M; ++j) {
			dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
			if (a[i - 1] == b[j - 1])
				dp[i][j] = std::max(dp[i][j], dp[i - 1][j - 1] + 1);
		}
	}

	int i = N, j = M;
	std::vector<int> ans;
	while (i && j) {
		if (dp[i][j] == dp[i - 1][j - 1] + 1 && a[i - 1] == b[j - 1]) {
			ans.push_back(a[i - 1]);
			i--, j--;
		}
		else if (dp[i][j] == dp[i - 1][j]) i--;
		else j--;
	}
	std::ranges::reverse(ans);
	std::cout << ans.size() << '\n';
	for (int idx = 0; idx < (int)ans.size(); ++idx) {
		std::cout << ans[idx] << (idx == (int)ans.size() - 1 ? '\n' : ' ');
	}
}
