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
	int N, K; cin >> N >> K;
	int x, a, b, c; cin >> x >> a >> b >> c;
	vector<int> vec(N);
	vec[0] = x;
	for (int i = 1; i < N; ++i) {
		vec[i] = (1LL * vec[i - 1] * a + b) % c;
	}
	vector<ll> ans(N - K + 1);
	ans[0] = accumulate(vec.begin(), vec.begin() + K, 0LL, [&](ll i, ll j) { return i ^ j; });
	for (int i = 0; i < N - K; ++i) {
		ans[i + 1] = ans[i] ^ vec[i + K] ^ vec[i];
	}
	ll ret = accumulate(ans.begin(), ans.end(), 0LL, [&](ll i, ll j) { return i ^ j; });
	cout << ret << '\n';
}
