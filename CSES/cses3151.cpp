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
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<int> ord(N);
	iota(ord.begin(), ord.end(), 0);
	ranges::sort(ord, [&](int i, int j) {
		return tie(a[i], i) > tie(a[j], j);
	});
	int ans = 0;
	Fenwick<int> bit(N);
	for (int i : ord) {
		ans = max(ans, bit.qry(0, i));
		bit.ins(i, 1);
	}
	cout << ans << '\n';
}
