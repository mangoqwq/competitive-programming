#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

template <typename T>
struct Fenwick {
	std::vector<T> v;
	Fenwick(int N) { v.resize(N + 1); }
	void ins(int i, T val) {
		for (++i; i < (int)v.size(); i += i & -i) v[i] += val;
	}
	T qry(int i) {
		T ret(0);
		for (++i; i; i -= i & -i) ret += v[i];
		return ret;
	}
	T qry(int l, int r) { return qry(r - 1) - qry(l - 1); }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K; cin >> N >> K;
	vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
	}
	vector<int> comp = vec;
	ranges::sort(comp);
	auto uniq = ranges::unique(comp);
	comp.erase(uniq.begin(), uniq.end());
	for (int &x : vec) {
		x = ranges::lower_bound(comp, x) - comp.begin();
	}

	Fenwick<int> bit(N);
	ll inv = 0;
	for (int i = 0; i < K; ++i) {
		inv += bit.qry(vec[i] + 1, N);
		bit.ins(vec[i], 1);
	}
	vector<ll> ans(N - K + 1);
	ans[0] = inv;
	for (int i = 0; i < N - K; ++i) {
		inv += bit.qry(vec[i + K] + 1, N);
		bit.ins(vec[i + K], 1);
		debug(inv);
		inv -= bit.qry(0, vec[i]);
		bit.ins(vec[i], -1);
		ans[i + 1] = inv;
	}
	for (int i = 0; i <= N - K; ++i) {
		cout << ans[i] << (i == N - K ? '\n' : ' ');
	}
}
