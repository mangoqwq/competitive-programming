#include <bits/stdc++.h>

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
	std::cin.tie(0)->sync_with_stdio(0);
	int N, Q; std::cin >> N >> Q;
	std::vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		std::cin >> a[i];
	}
	auto s = std::set<int>(a.begin(), a.end());
	std::vector<int> uniq(s.begin(), s.end());
	for (int &x : a) {
		x = std::ranges::lower_bound(uniq, x) - uniq.begin();
	}

	struct Event { int i, mul, va, vb; };
	std::vector<std::vector<Event>> poi(N + 1);
	for (int i = 0; i < Q; ++i) {
		int l, r, va, vb;
		std::cin >> l >> r >> va >> vb; l--;
		va = std::ranges::lower_bound(uniq, va) - uniq.begin();
		vb = std::ranges::lower_bound(uniq, vb + 1) - uniq.begin();
		poi[l].emplace_back(i, -1, va, vb);
		poi[r].emplace_back(i, 1, va, vb);
	}

	std::vector<int> ans(Q);
	Fenwick<int> bit(N);
	for (int i = 0; i <= N; ++i) {
		for (auto [idx, mul, va, vb] : poi[i]) {
			ans[idx] += mul * bit.qry(va, vb);
		}
		if (i != N) bit.ins(a[i], 1);
	}
	for (int i = 0; i < Q; ++i) {
		std::cout << ans[i] << '\n';
	}
}
