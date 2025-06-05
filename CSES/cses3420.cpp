#include <bits/stdc++.h>

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	std::cin.tie(0)->sync_with_stdio(0);
	int N; std::cin >> N;
	std::vector<int> a(N);
	std::map<int, int> seen;
	long long ans = 0;
	int cant = -1;
	for (int i = 0; i < N; ++i) {
		std::cin >> a[i];
		if (seen.contains(a[i])) {
			cant = std::max(cant, seen[a[i]]);
		}
		seen[a[i]] = i;
		ans += i - cant;
	}
	std::cout << ans << '\n';
}
