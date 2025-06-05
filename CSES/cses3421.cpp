#include <bits/stdc++.h>

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	const int mod = 1e9 + 7;
	int N; std::cin >> N;
	std::map<int, int> cnt;
	for (int i = 0; i < N; ++i) {
		int x; std::cin >> x;
		cnt[x]++;
	}
	int ans = 1;
	for (auto [x, freq] : cnt) {
		ans = (1LL * ans * (freq + 1)) % mod;
	}
	ans = (ans - 1 + mod) % mod;
	std::cout << ans << '\n';
}
