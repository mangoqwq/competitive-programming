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
	for (int i = 100; i < 1000; ++i) {
		for (int j = 100; j < 1000; ++j) {
			string s = to_string(i * j);
			string t = s; ranges::reverse(t);
			if (s == t) ans = max(ans, i * j);
		}
	}
	cout << ans << '\n';
}
