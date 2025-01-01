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
	int N = 100;
	vector<int> base(N + 1), mult(N + 1, 1);
	iota(base.begin(), base.end(), 0);

	map<int, set<int>> mp;
	for (int a = 2; a <= N; ++a) {
		for (int b = 2; b <= N; ++b) {
			mp[base[a]].insert(mult[a] * b);
		}
		if (base[a] == a) {
			for (int k = a * a; k <= N; k *= a) {
				base[k] = a;
				mult[k] = mult[k / a] + 1;
			}
		}
	}
	int ans = 0;
	for (auto [a, b] : mp) ans += b.size();
	cout << ans << '\n';
}
