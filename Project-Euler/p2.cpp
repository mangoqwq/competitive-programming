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
	int ans = 0;
	int a = 1, b = 2;
	while (b <= 4e6) {
		if (b % 2 == 0) ans += b;
		tie(a, b) = make_tuple(b, a + b);
	}
	cout << ans << '\n';
}
