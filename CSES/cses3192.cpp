#include <algorithm>
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
	vector<int> basis(30);
	for (int i = 0; i < N; ++i) {
		int x; cin >> x;
		for (int b = 29; b >= 0; --b) {
			if (1 & (x >> b)) x ^= basis[b];
		}
		if (x && !basis[__lg(x)]) basis[__lg(x)] = x;
	}
	int dim = ranges::count_if(basis, [&](int x) { return x != 0; });
	int mult = 1 << min(N - dim, 30);
	vector<int> base;
	for (int x : basis) {
		if (x) base.push_back(x);
	}
	vector<int> xors = {0};
	for (int x : base) {
		if ((ll)xors.size() * mult > K) break;
		int n = xors.size();
		for (int i = 0; i < n; ++i) {
			xors.push_back(xors[i] ^ x);
		}
	}
	ranges::sort(xors);
	vector<int> ans;
	for (int x : xors) {
		for (int i = 0; i < mult; ++i) {
			if ((int)ans.size() == K) break;
			ans.push_back(x);
		}
		if ((int)ans.size() == K) break;
	}
	for (int i = 0; i < K; ++i) {
		cout << ans[i] << (i == K - 1 ? '\n' : ' ');
	}
}
