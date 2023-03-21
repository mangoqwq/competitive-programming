#include <bits/stdc++.h>

using namespace std;
using ll = long long;

template <typename T, typename F>
struct SegmentTree {
	int N;
	int size;
	vector<T> seg;
	const F f;
	const T I;

	SegmentTree(F _f, const T &I_) : N(0), size(0), f(_f), I(I_) {}

	SegmentTree(int _N, F _f, const T &I_) : f(_f), I(I_) { init(_N); }

	SegmentTree(const vector<T> &v, F _f, T I_) : f(_f), I(I_) {
		init(v.size());
		for (int i = 0; i < (int)v.size(); i++) {
			seg[i + size] = v[i];
		}
		build();
	}

	void init(int _N) {
		N = _N;
		size = 1;
		while (size < N) size <<= 1;
		seg.assign(2 * size, I);
	}

	void set(int k, T x) { seg[k + size] = x; }

	void build() {
		for (int k = size - 1; k > 0; k--) {
			seg[k] = f(seg[2 * k], seg[2 * k + 1]);
		}
	}

	void update(int k, T x) {
		k += size;
		seg[k] = x;
		while (k >>= 1) {
			seg[k] = f(seg[2 * k], seg[2 * k + 1]);
		}
	}

	void add(int k, T x) {
		k += size;
		seg[k] += x;
		while (k >>= 1) {
			seg[k] = f(seg[2 * k], seg[2 * k + 1]);
		}
	}

	// query to [a, b)
	T query(int a, int b) {
		T L = I, R = I;
		for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
			if (a & 1) L = f(L, seg[a++]);
			if (b & 1) R = f(seg[--b], R);
		}
		return f(L, R);
	}

	T &operator[](const int &k) { return seg[k + size]; }

	// check(a[l] * ...  * a[r-1]) が true となる最大の r
	// (右端まですべて true なら N を返す)
	template <class C>
	int max_right(int l, C check) {
		assert(0 <= l && l <= N);
		assert(check(I) == true);
		if (l == N) return N;
		l += size;
		T sm = I;
		do {
			while (l % 2 == 0) l >>= 1;
			if (!check(f(sm, seg[l]))) {
				while (l < size) {
					l = (2 * l);
					if (check(f(sm, seg[l]))) {
						sm = f(sm, seg[l]);
						l++;
					}
				}
				return l - size;
			}
			sm = f(sm, seg[l]);
			l++;
		} while ((l & -l) != l);
		return N;
	}

	// check(a[l] * ... * a[r-1]) が true となる最小の l
	// (左端まで true なら 0 を返す)
	template <typename C>
	int min_left(int r, C check) {
		assert(0 <= r && r <= N);
		assert(check(I) == true);
		if (r == 0) return 0;
		r += size;
		T sm = I;
		do {
			r--;
			while (r > 1 && (r % 2)) r >>= 1;
			if (!check(f(seg[r], sm))) {
				while (r < size) {
					r = (2 * r + 1);
					if (check(f(seg[r], sm))) {
						sm = f(seg[r], sm);
						r--;
					}
				}
				return r + 1 - size;
			}
			sm = f(seg[r], sm);
		} while ((r & -r) != r);
		return 0;
	}
};

// S ... index_type
// T ... value_type
// F ... function_type
template <typename S, typename T, typename F>
struct RangeTree {
	using Seg = SegmentTree<T, F>;
	using P = pair<S, S>;

	S N, M;
	const F f;
	T ti;
	vector<SegmentTree<T, F>> seg;
	vector<vector<S>> ys;
	vector<P> ps;

	RangeTree(const F& f_, const T& ti_) : f(f_), ti(ti_) {}

	void add_point(S x, S y) { ps.push_back(make_pair(x, y)); }

	void build() {
		sort(begin(ps), end(ps));
		ps.erase(unique(begin(ps), end(ps)), end(ps));
		N = ps.size();
		for (int i = 0; i < 2 * N; ++i) seg.push_back(Seg{f, ti});
		ys.resize(2 * N);
		for (int i = 0; i < N; ++i) {
			ys[i + N].push_back(ps[i].second);
			seg[i + N].init(1);
		}
		for (int i = N - 1; i > 0; --i) {
			ys[i].resize(ys[i << 1].size() + ys[(i << 1) | 1].size());
			merge(begin(ys[(i << 1) | 0]), end(ys[(i << 1) | 0]),
						begin(ys[(i << 1) | 1]), end(ys[(i << 1) | 1]), begin(ys[i]));
			ys[i].erase(unique(begin(ys[i]), end(ys[i])), end(ys[i]));
			seg[i].init(ys[i].size());
		}
	}

	int id(S x) const {
		return lower_bound(
							 begin(ps), end(ps), make_pair(x, S()),
							 [](const P& a, const P& b) { return a.first < b.first; }) -
					 begin(ps);
	}

	int id(int i, S y) const {
		return lower_bound(begin(ys[i]), end(ys[i]), y) - begin(ys[i]);
	}

	void add(S x, S y, T a) {
		int i = lower_bound(begin(ps), end(ps), make_pair(x, y)) - begin(ps);
		assert(ps[i] == make_pair(x, y));
		for (i += N; i; i >>= 1) seg[i].add(id(i, y), a);
	}

	T sum(S xl, S yl, S xr, S yr) {
		T L = ti, R = ti;
		int a = id(xl), b = id(xr);
		for (a += N, b += N; a < b; a >>= 1, b >>= 1) {
			if (a & 1) L = f(L, seg[a].query(id(a, yl), id(a, yr))), ++a;
			if (b & 1) --b, R = f(seg[b].query(id(b, yl), id(b, yr)), R);
		}
		return f(L, R);
	}
};

// Builds the centroid tree of a tree (0-indexed)
// Returns {adjacency list, root (first centroid)}
// Runtime: O(NlogN)
// Tested:
// https://cses.fi/problemset/task/2079/
// https://cses.fi/problemset/task/2080/
pair<vector<vector<int>>, int> CentroidTree(vector<vector<int>> adj){
	int N = adj.size();
	vector<int> sz(N), vis(N);

	auto dfs = [&](auto self, int v, int p) -> int {
		sz[v] = 1;
		for (int to : adj[v]){
			if (to == p || vis[to]) continue;
			sz[v] += self(self, to, v);
		}
		return sz[v];
	};

	auto locate = [&](auto self, int v, int p, int src) -> int {
		for (int to : adj[v]){
			if (to == p || vis[to]) continue;
			if (2 * sz[to] > sz[src]) return self(self, to, v, src);
		}
		return v;
	};

	vector<vector<int>> ret(N);
	auto go = [&](auto self, int v) -> int {
		dfs(dfs, v, v);
		v = locate(locate, v, v, v);
		vis[v] = 1;
		for (int to : adj[v]){
			if (vis[to]) continue;
			ret[v].push_back(self(self, to));
		}
		return v;
	};
	int rt = go(go, 0);
	return {ret, rt};
}

int main(){
	// cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	struct Edge{ int to; ll w; int id; };
	vector<vector<Edge>> adj(N);
	vector<vector<int>> cadj(N);
	for (int i = 0; i < N-1; ++i){
		int a, b, c; cin >> a >> b >> c;
		a--, b--;
		adj[a].push_back({b, c, i});
		adj[b].push_back({a, c, i});
		cadj[a].push_back(b);
		cadj[b].push_back(a);
	}

	int Q; cin >> Q;
	struct NQuery{ int t; ll d; };
	vector<vector<NQuery>> watches(N);
	vector<vector<int>> asks(N-1);
	vector<int> ans(Q, -1);
	for (int i = 0; i < Q; ++i){
		char c; cin >> c;
		if (c == '+'){
			ll v, r; cin >> v >> r;
			v--;
			watches[v].push_back({i, r});
		}
		else{
			int e; cin >> e;
			e--;
			asks[e].push_back(i);
			ans[i] = 0;
		}
	}


	auto addition = [](ll a, ll b) { return a + b; };
	
	auto [tree, rt] = CentroidTree(cadj);
	vector<int> marked(N);
	const ll inf = 1e18;
	auto solve = [&](auto self, int v) -> void {

		// cerr << "~~~~~~~ " << v << " ~~~~~~~~~" << '\n';
		
		struct Event{ int t; ll d; };
		vector<vector<Event>> eves;
		RangeTree<ll, ll, decltype(addition)> rtree(addition, 0);

		int idx = 0;
		auto dfs = [&](auto self, int v, int p, ll d) -> void {
			for (auto [t, qd] : watches[v]){
				if (qd < d) continue;
				// cerr << t << " " << qd-d << '\n';
				eves[idx].push_back({t, qd - d});
				rtree.add_point(t, qd-d);
			}
			for (auto [to, w, id] : adj[v]){
				if (to == p) continue;
				for (int t : asks[id]){
					rtree.add_point(0, d+w);
				}
				if (marked[to]) continue;
				self(self, to, v, d+w);
			}
		};

		
		for (auto [to, w, id] : adj[v]){
			for (int t : asks[id]){
				rtree.add_point(0, w);
			}
			eves.push_back(vector<Event>());
			if (!marked[to]){
				dfs(dfs, to, v, w);
			}
			idx++;
		}

		for (auto [t, qd] : watches[v]){
			rtree.add_point(t, qd);
		}

		rtree.build();

		for (auto [t, qd] : watches[v]){
			rtree.add(t, qd, 1);
		}

		for (int i = 0; i < idx; ++i){
			for (auto [t, d] : eves[i]){
				rtree.add(t, d, 1);
			}
		}

		auto collect = [&](auto self, int v, int p, ll d) -> void {
			for (auto [to, w, id] : adj[v]){
				if (to == p) continue;
				for (int t : asks[id]){
					ans[t] += rtree.sum(0, d+w, t, d+w + inf);
				}
				if (marked[to]) continue;
				self(self, to, v, d+w);
			}
		};

		idx = 0;
		for (auto [to, w, id] : adj[v]){
			for (auto [t, d] : eves[idx]){
				rtree.add(t, d, -1);
			}
			for (int t : asks[id]){
				ans[t] += rtree.sum(0, w, t, w+inf);
			}

			if (!marked[to]){
				collect(collect, to, v, w);
			}

			for (auto [t, d] : eves[idx]){
				rtree.add(t, d, 1);
			}
			idx++;
		}

		for (int to : tree[v]){
			marked[v] = 1;
			self(self, to);
		}
	};
	solve(solve, rt);
	for (int i = 0; i < Q; ++i){
		if (ans[i] != -1){
			cout << ans[i] << '\n';
		}
	}
}
