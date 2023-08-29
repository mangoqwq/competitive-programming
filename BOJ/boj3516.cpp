#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

template <typename T>
struct Fenwick {
	vector<T> v;
	Fenwick(int N) { v.resize(N + 1); }
	void ins(int i, T val) {
		for (++i; i < v.size(); i += i & -i) v[i] += val;
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
	vector<pair<int, int>> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());

	vector<int> comp;
	for (int i = 0; i < N; ++i) {
		comp.push_back(a[i].second);
	}
	sort(comp.begin(), comp.end());
	
	ll ans = 0;
	Fenwick<int> bit(N);
	for (auto [_, y] : a) {
		y = lower_bound(comp.begin(), comp.end(), y) - comp.begin();
		ans += bit.qry(y+1, N);
		bit.ins(y, 1);
	}
	cout << ans << '\n';
}
