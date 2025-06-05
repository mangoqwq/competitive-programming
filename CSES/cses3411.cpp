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
	using i128 = __int128_t;
	int N; cin >> N;
	vector<ll> x(N), y(N);
	for (int i = 0; i < N; ++i) {
		cin >> x[i] >> y[i];
	}
	auto calc = [&](vector<ll> &v) {
		ranges::sort(v);
		i128 ans = 0;
		for (int i = 0; i < N; ++i) {
			ans += (2 * i + 1 - N) * v[i];
		}
		return ans;
	};
	i128 ans = calc(x) + calc(y);
	if (ans == 0) {
		cout << 0 << '\n';
	}
	else {
		string ret;
		while (ans) ret.push_back(ans % 10 + '0'), ans /= 10;
		ranges::reverse(ret);
		cout << ret << '\n';
	}
}
