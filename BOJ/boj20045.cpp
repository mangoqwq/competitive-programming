#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

struct SparseTable {
	const int L = 18;
	vector<ll> v;
	vector<vector<int>> st;
	SparseTable(vector<ll> _v) : v{_v} {
		int N = v.size();
		st = vector<vector<int>>(N, vector<int>(L+1));
		for (int i = 0; i < N; ++i) st[i][0] = i;
		for (int l = 1; l <= L; ++l) {
			for (int i = 0; i + (1 << l) <= N; ++i) {
				int ci = st[i][l-1], cj = st[i + (1 << (l-1))][l-1];
				st[i][l] = (v[ci] <= v[cj] ? ci : cj);
			}
		}
	}
	int qry(int l, int r) {
		int b = (__lg(r - l));
		int ci = st[l][b], cj = st[r - (1 << b)][b];
		return v[ci] <= v[cj] ? ci : cj;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K; cin >> N >> K;
	vector<ll> a(N), psa(N+1);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		psa[i+1] = psa[i] + a[i];
	}
	SparseTable st(psa);

	struct Item {
		ll val;
		int r, l, lo, hi;
		bool operator<(const Item &other) const { return val < other.val; }
	};
	priority_queue<Item> pq;
	auto ins = [&](int r, int lo, int hi) {
		if (lo == hi) return;
		int l = st.qry(lo, hi);
		pq.push({psa[r] - psa[l], r, l, lo, hi});
	};
	for (int i = 1; i <= N; ++i) {
		ins(i, 0, i);
	}
	for (int k = 0; k < K; ++k) {
		auto [val, r, l, lo, hi] = pq.top(); pq.pop();
		cout << val << (k == K-1 ? '\n' : ' ');
		ins(r, lo, l); ins(r, l+1, hi);
	}
}
