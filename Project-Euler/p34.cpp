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
	vector<int> fact(10);
	fact[0] = 1;
	for (int i = 1; i < 10; ++i) fact[i] = fact[i-1] * i;
	const int lim = 362880 * 100;
	ll ans = 0;
	for (int i = 10; i <= lim; ++i) {
		int sum = 0;
		for (char c : to_string(i)) sum += fact[c - '0'];
		if (sum == i)
			ans += i;
	}
	cout << ans << '\n';
}
