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
	int N; cin >> N; N++;

	auto solve = [&](auto self, int a, int b, vector<int> &ref) -> ll {
		if (a < b) swap(a, b);
		debug(a, b);
		if (a == b) {
			return 1e9;
		}
		if (b == 0) {
			ref.push_back(a);
			return a;
		}
		int times = a / (b+1);
		a = a % (b+1);
		auto cur = self(self, a, b, ref);
		ref.push_back(times);
		return cur + times;
	};
	
	ll ans = 1e9;
	vector<int> best;
	for (int a = 0; a < N; ++a) {
		int b = N - a - 1;
		vector<int> vec;
		auto cur = solve(solve, a, b, vec);
		if (cur < ans) swap(vec, best), ans = cur;
	}
	for (int i = 0; i < (int)best.size(); ++i) {
		for (int j = 0; j < best[i]; ++j) {
			cout << (i%2);
		}
	}
	cout << '\n';
}
