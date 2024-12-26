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
	for (int i = 0; i < 1000; ++i) {
		if (i % 3 == 0 || i % 5 == 0) ans += i;
	}
	cout << ans << '\n';
}
