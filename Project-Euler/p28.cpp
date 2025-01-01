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
	int ans = 1;
	int N = 1001;
	for (int i = 3; i <= N; i += 2) {
		ans += 4 * i * i - 6 * (i - 1);
	}
	cout << ans << '\n';
}
