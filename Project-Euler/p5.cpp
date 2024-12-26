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
	ll ans = 1;
	for (int i = 1; i <= 20; ++i) {
		ans = lcm(ans, i);
	}
	cout << ans << '\n';
}
