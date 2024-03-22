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
	int T; cin >> T;
	while (T--) [&]() {
		int N, Q; cin >> N >> Q;
		vector<int> a(N), pos(N+1);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
			pos[a[i]] = i;
		}

		struct Query { int l, r, id; };
		vector<vector<Query>> eve(N);
		for (int i = 0; i < Q; ++i) {
			int l, r; cin >> l >> r; l--;
			eve[l].push_back({l, r, i});
		}

		Fenwick<ll> bit(N+1);
		vector<ll> sav(N+1), ans(Q);
		for (int i = N-1; i >= 0; --i) {
			int x = a[i];
			sav[x] = 1;
			for (int y = x; y <= N; y += x) {
				bit.ins(pos[y], sav[y]);
				for (int z = y+y; z <= N; z += y) {
					if (pos[z] > pos[y]) sav[z] += sav[y];
				}
				sav[y] = 0;
			}
			for (auto [l, r, id] : eve[i]) {
				ans[id] = bit.qry(l, r);
			}
		}

		for (int i = 0; i < Q; ++i) {
			cout << ans[i] << (i == Q-1 ? '\n' : ' ');
		}
	}();
}
