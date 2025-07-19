#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

using i128 = __int128_t;
string to_string(i128 n) {
	string ret = "";
	while (n) ret += n % 10 + '0', n /= 10;
	ranges::reverse(ret);
	return ret;
}
i128 stoi128(string s) {
	i128 ret = 0;
	ranges::reverse(s);
	for (char c : s) ret = ret * 10 + c - '0';
	return ret;
}
string rev(string s) {
	ranges::reverse(s);
	return s;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N = 1e4;
	int ans = 0;
	for (int n = 1; n < N; ++n) {
		bool good = 1;
		string val = to_string(n);
		for (int it = 0; it < 50; ++it) {
			val = to_string(stoi128(val) + stoi128(rev(val)));
			good &= val != rev(val);
		}
		if (good) ans++;
	}
	cout << ans << '\n';
}
