#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K; cin >> N >> K;
	auto solve = [&](auto self, int x) -> int {
		if (x <= K || (x - K) % 2 == 1) return 1;
		int small = (x-K) / 2;
		return self(self, small) + self(self, small + K);
	};
	cout << solve(solve, N) << '\n';
}
