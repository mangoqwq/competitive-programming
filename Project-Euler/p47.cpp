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
	auto distinct_factors = [&](int n) -> int {
		int ret = 0;
		for (int i = 2; i * i <= n; ++i) {
			if (n % i == 0) ret++;
			while (n % i == 0) n /= i;
		}
		return ret + (n != 1);
	};
	for (int i = 2;; ++i) {
		bool ok = [&]() -> bool {
			if (distinct_factors(i) != 4) return 0;
			if (distinct_factors(i+1) != 4) return 0;
			if (distinct_factors(i+2) != 4) return 0;
			if (distinct_factors(i+3) != 4) return 0;
			return 1;
		}();
		if (ok) {
			cout << i << '\n';
			break;
		}
	}
}
