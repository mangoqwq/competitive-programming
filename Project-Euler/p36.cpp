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
	int N = 1e6;
	auto pal = [&](string s) {
		return ranges::equal(s, ranges::views::reverse(s));
	};
	auto base2 = [&](int x) -> string {
		string ret = "";
		while (x) ret += (x & 1 ? '1' : '0'), x /= 2;
		ranges::reverse(ret);
		return ret;
	};
	int ans = 0;
	for (int i = 1; i < N; ++i) {
		bool good = pal(to_string(i)) && pal(base2(i));
		if (good) ans += i;
	}
	cout << ans << '\n';
}
