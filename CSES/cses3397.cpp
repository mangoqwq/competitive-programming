#include <bits/stdc++.h>

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	std::vector<long long> fact(21);
	fact[0] = 1;
	for (int i = 1; i <= 20; ++i) {
		fact[i] = fact[i - 1] * i;
	}
	int T; std::cin >> T;
	while (T--) [&]() {
		int op; std::cin >> op;
		if (op == 1) {
			int N; long long K; std::cin >> N >> K;
			K--;
			std::vector<int> vals(N);
			std::iota(vals.begin(), vals.end(), 1);
			for (int i = 0; i < N; ++i) {
				int idx = K / fact[N - i - 1];
				auto it = vals.begin() + idx;
				std::cout << *it << (i == N - 1 ? '\n' : ' ');
				vals.erase(it);
				K %= fact[N - i - 1];
			}
		}
		else {
			int N; std::cin >> N;
			long long K = 0;
			std::vector<int> vals(N);
			std::iota(vals.begin(), vals.end(), 1);
			for (int i = 0; i < N; ++i) {
				int x; std::cin >> x;
				auto it = std::ranges::lower_bound(vals, x);
				int ord = it - vals.begin();
				vals.erase(it);
				K += fact[N - i - 1] * ord;
			}
			std::cout << K + 1 << '\n';
		}
	}();
}
