#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int K; cin >> K;
	int N = (1 << (2 * K));
	string s; cin >> s; s = s + s;
	vector<vector<int>> psa(2*N+1, vector<int>(3));
	for (int i = 0; i < 2*N; ++i) {
		psa[i+1] = psa[i];
		if (s[i] == 'J') psa[i+1][0]++;
		if (s[i] == 'O') psa[i+1][1]++;
		if (s[i] == 'I') psa[i+1][2]++;
	}

	auto calc = [&](auto self, int k, int l) -> int {
		if (k == 0) return 0;
		int n = (1 << (2 * k)) / 4;
		int ret = 0;
		ret += n - (psa[l+1*n][0] - psa[l+0*n][0]);
		ret += n - (psa[l+2*n][1] - psa[l+1*n][1]);
		ret += n - (psa[l+3*n][2] - psa[l+2*n][2]);
		ret += self(self, k-1, l+3*n);
		return ret;
	};

	int ans = N;
	for (int i = 0; i < N; ++i) {
		ans = min(ans, calc(calc, K, i));
	}
	cout << ans << '\n';
}
