#include <bits/stdc++.h>

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	int N, Q; std::cin >> N >> Q;
	std::vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> a[i];
	}

	std::vector<int> ord(N);
	std::iota(ord.begin(), ord.end(), 0);
	std::ranges::sort(ord, [&](int i, int j) {
		return std::tie(a[i], j) > std::tie(a[j], i);
	});
	std::set<int> in = {N};

	const int L = 17;
	std::vector<std::vector<int>> st(N + 1, std::vector<int>(L, N));
	for (int idx : ord) {
		auto it = in.lower_bound(idx);
		st[idx][0] = *it;
		in.insert(it, idx);
	}
	for (int b = 1; b < L; ++b) {
		for (int i = 0; i + (1 << b) <= N; ++i) {
			st[i][b] = st[st[i][b - 1]][b - 1];
		}
	}

	while (Q--) {
		int l, r; std::cin >> l >> r; l--;
		int ans = 0;
		for (int b = L - 1; b >= 0; --b) {
			if (st[l][b] < r) {
				l = st[l][b];
				ans += 1 << b;
			}
		}
		std::cout << ans + 1 << '\n';
	}
}
