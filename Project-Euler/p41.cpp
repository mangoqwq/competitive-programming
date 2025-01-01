#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

bool prime(int n) {
	for (int i = 2; i * i <= n; ++i) {
		if (n % i == 0) return 0;
	}
	return 1;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int ans = 0;
	for (int n = 1; n < 10; ++n) {
		string s(n, '0');
		iota(s.begin(), s.end(), '1');
		do {
			int x = stoi(s);
			if (prime(x)) ans = max(ans, x);
		} while (next_permutation(s.begin(), s.end()));
	}
	cout << ans << '\n';
}
