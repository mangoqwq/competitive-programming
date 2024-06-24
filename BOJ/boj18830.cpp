#include <bits/stdc++.h>
#pragma GCC optimize ("O3")
#pragma GCC target ("avx2")

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

ll vec[1000000];
ll psa[1000000];

vector<vector<int>> enumerate(const vector<int> &dims) {
	vector<vector<int>> ret;
	vector<int> cur(dims.size());
	auto dfs = [&](auto self, int i) -> void {
		if (i == (int)dims.size()) {
			ret.push_back(cur);
			return;
		}
		for (int c = 0; c < dims[i]; ++c) {
			cur[i] = c;
			self(self, i+1);
		}
	};
	dfs(dfs, 0);
	return ret;
}

vector<pair<int, int>> enumerate_hypercube(const vector<int> &l, const vector<int> &r, const vector<int> &dims) {
	vector<pair<int, int>> ret;
	auto dfs = [&](auto self, int i, int bits, int cur) -> void {
		if (i == (int)l.size()) {
			ret.push_back({bits, cur});
			return;
		}
		if (l[i] >= 0) self(self, i+1, bits+1, cur * dims[i] + l[i]);
		self(self, i+1, bits, cur * dims[i] + r[i]);
	};
	dfs(dfs, 0, 0, 0);
	return ret;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int D = 11;
	vector<int> dims(D);
	for (int i = 0; i < D; ++i) {
		cin >> dims[i];
	}
	int N = reduce(dims.begin(), dims.end(), 1, multiplies<ll>());
	for (int i = 0; i < N; ++i) cin >> vec[i];

	vector<int> td(D);
	transform(dims.begin(), dims.end(), td.begin(), [&](int x) { return x+1; });
	auto sgn = [&](int x) { return x % 2 == 0 ? 1 : -1; };

	int ti = 0;
	for (auto i : enumerate(dims)) {
		vector<int> j(D);
		transform(i.begin(), i.end(), j.begin(), [&](int x) { return x-1; });
		ll val = vec[ti];
		for (auto [bits, v] : enumerate_hypercube(j, i, dims)) {
			val += -sgn(bits) * psa[v];
		}
		psa[ti] = val;
		ti++;
	}

	int Q; cin >> Q;
	for (int q = 0; q < Q; ++q) {
		vector<int> l(D), r(D);
		for (int i = 0; i < D; ++i) cin >> l[i], l[i] -= 2;
		for (int i = 0; i < D; ++i) cin >> r[i], r[i]--;
		ll ans = 0;
		for (auto [bits, v] : enumerate_hypercube(l, r, dims)) {
			ans += sgn(bits) * psa[v];
		}
		cout << ans << '\n';
	}
}
