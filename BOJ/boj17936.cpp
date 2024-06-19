#include <bits/stdc++.h>

using namespace std;
using ll = long long;

// Resource: https://codeforces.com/blog/entry/103726
// Tested: https://dmoj.ca/problem/ds5
template <typename S, typename D, typename F>
struct TopTree {
	TopTree(int N) : T(2 * N), free_dummies(N) {
		iota(free_dummies.begin(), free_dummies.end(), N);
		for (int i = N; i < 2 * N; ++i) {
			T[i].dummy = 1;
		}
	}

 private:
	struct Node {
		int ch[4] = {-1, -1, -1, -1}, p = -1;
		S val{};
		D path = D::e();	// preferred path
		D vir = D::e();		// virtual children
		D sub = D::e();		// entire subtree
		F path_lazy = F::id();
		F vir_lazy = F::id();
		bool rev = 0, dummy = 0;
	};
	vector<Node> T;
	vector<int> free_dummies;

	void apply_path_lazy(int v, F f) {
		if (v == -1 || T[v].dummy) return;
		T[v].val = f.apply(T[v].val);
		T[v].path = f.apply(T[v].path);
		T[v].sub = D::op(T[v].path, T[v].vir);
		T[v].path_lazy = F::composition(f, T[v].path_lazy);
	}

	void apply_vir_lazy(int v, F f, bool o) {
		if (v == -1) return;
		T[v].vir = f.apply(T[v].vir);
		T[v].sub = D::op(T[v].path, T[v].vir);
		T[v].vir_lazy = F::composition(f, T[v].vir_lazy);
		if (o) apply_path_lazy(v, f);
	}

	void apply_rev_lazy(int v) {
		if (v == -1) return;
		swap(T[v].ch[0], T[v].ch[1]);
		T[v].path.reverse();
		T[v].rev ^= 1;
	}

	void push(int v) {
		if (v == -1) return;
		if (T[v].rev) {
			apply_rev_lazy(T[v].ch[0]);
			apply_rev_lazy(T[v].ch[1]);
			T[v].rev = 0;
		}
		if (!(T[v].path_lazy == F::id())) {
			apply_path_lazy(T[v].ch[0], T[v].path_lazy);
			apply_path_lazy(T[v].ch[1], T[v].path_lazy);
			T[v].path_lazy = F::id();
		}
		if (!(T[v].vir_lazy == F::id())) {
			apply_vir_lazy(T[v].ch[0], T[v].vir_lazy, 0);
			apply_vir_lazy(T[v].ch[1], T[v].vir_lazy, 0);
			apply_vir_lazy(T[v].ch[2], T[v].vir_lazy, 1);
			apply_vir_lazy(T[v].ch[3], T[v].vir_lazy, 1);
			T[v].vir_lazy = F::id();
		}
	}

	void pull(int v) {
		push(v);
		int lc = T[v].ch[0], rc = T[v].ch[1];
		int vlc = T[v].ch[2], vrc = T[v].ch[3];

		if (!T[v].dummy) {
			T[v].path = D::e();
			if (lc != -1) T[v].path = D::op(T[v].path, T[lc].path);
			T[v].path = D::op(T[v].path, D::make(T[v].val));
			if (rc != -1) T[v].path = D::op(T[v].path, T[rc].path);
		}
		T[v].vir = D::e();
		if (lc != -1) T[v].vir = D::op(T[v].vir, T[lc].vir);
		if (rc != -1) T[v].vir = D::op(T[v].vir, T[rc].vir);
		if (vlc != -1) T[v].vir = D::op(T[v].vir, T[vlc].sub);
		if (vrc != -1) T[v].vir = D::op(T[v].vir, T[vrc].sub);
		T[v].sub = D::op(T[v].path, T[v].vir);
	}

	int get_dir(int v, int o) {
		int p = T[v].p;
		if (p == -1) return -1;
		if (T[p].ch[o] == v) return o;
		if (T[p].ch[o + 1] == v) return o + 1;
		return -1;
	}

	void stick(int v, int p, int dir) {
		T[p].ch[dir] = v;
		if (v != -1) T[v].p = p;
		pull(p);
	}

	void rot(int v, int o) {
		int p = T[v].p, g = T[p].p;
		int dv = get_dir(v, o), dp = get_dir(p, o);
		if (dp == -1 && o == 0) dp = get_dir(p, 2);
		stick(T[v].ch[dv ^ 1], p, dv);
		stick(p, v, dv ^ 1);
		if (dp != -1) stick(v, g, dp);
		T[v].p = g;
	}

	void splay(int v, int o) {
		push(T[v].p), push(v);
		while (get_dir(v, o) != -1 && (o == 0 || T[T[v].p].dummy)) {
			int p = T[v].p, g = T[p].p;
			if (g != -1) push(T[g].p);
			push(g), push(p), push(v);
			int dv = get_dir(v, o), dp = get_dir(p, o);
			if (dp != -1 && (o == 0 || T[g].dummy)) rot(dv == dp ? p : v, o);
			rot(v, o);
		}
	}

	void add_vir(int v, int p) {
		if (v == -1) return;
		for (int i = 2; i < 4; ++i) {
			if (T[p].ch[i] == -1) {
				stick(v, p, i);
				return;
			}
		}
		int d = free_dummies.back();
		free_dummies.pop_back();
		stick(T[p].ch[2], d, 2);
		stick(v, d, 3);
		stick(d, p, 2);
	}

	void push_chain(int v) {
		if (v == -1 || !T[v].dummy) return;
		push_chain(T[v].p);
		push(v);
	}

	void rem_vir(int v) {
		if (v == -1) return;
		int p = T[v].p;
		push_chain(p);
		if (T[p].dummy) {
			int g = T[p].p;
			stick(T[p].ch[get_dir(v, 2) ^ 1], g, get_dir(p, 2));
			if (T[g].dummy) splay(g, 2);
			T[p] = Node();
			T[p].dummy = 1;
			free_dummies.push_back(p);
		} else {
			stick(-1, p, get_dir(v, 2));
		}
		T[v].p = -1;
	}

	int par(int v) {
		int p = T[v].p;
		if (p == -1 || !T[p].dummy) return p;
		splay(p, 2);
		return T[p].p;
	}

	int access(int v) {
		int t = v, last = -1;
		while (v != -1) {
			splay(v, 0);
			rem_vir(last);
			add_vir(T[v].ch[1], v);
			stick(last, v, 1);
			last = v;
			v = par(v);
		}
		splay(t, 0);
		return last;
	}

	void reroot(int v) {
		access(v);
		apply_rev_lazy(v);
	}

	void cut(int v) {
		access(v);
		int lc = T[v].ch[0];
		if (lc != -1) {
			T[lc].p = T[v].ch[0] = -1;
			pull(v);
		}
	}

 public:

	void link(int v, int p) {
		reroot(v);
		access(p);
		add_vir(v, p);
	}

	void cut(int v, int p) {
		reroot(p);
		cut(v);
	}

	void set(int v, S val) {
		access(v);
		T[v].val = val;
		pull(v);
	}

	int parent(int v, int rt) {
		reroot(rt);
		return par(v);
	}

	void apply_path(int u, int v, F f) {
		reroot(u), access(v);
		apply_path_lazy(v, f);
	}

	void apply_subtree(int v, int rt, F f) {
		reroot(rt), access(v);
		T[v].val = f.apply(T[v].val);
		int vlc = T[v].ch[2], vrc = T[v].ch[3];
		if (vlc != -1) apply_vir_lazy(vlc, f, 1);
		if (vrc != -1) apply_vir_lazy(vrc, f, 1);
		pull(v);
	}

	D query_path(int u, int v) {
		reroot(u), access(v);
		return T[v].path;
	}

	D query_subtree(int v, int rt) {
		reroot(rt), access(v);
		D ret = D::make(T[v].val);
		int vlc = T[v].ch[2], vrc = T[v].ch[3];
		if (vlc != -1) ret = D::op(ret, T[vlc].sub);
		if (vrc != -1) ret = D::op(ret, T[vrc].sub);
		return ret;
	}

	int lca(int u, int v, int rt) {
		if (u == v) return u;
		reroot(rt);
		access(u);
		int x = access(v);
		return T[u].p == -1 ? -1 : x;
	}

	bool connected(int u, int v) { return lca(u, v, u) != -1; }
};

using S = struct {
	int val, sz;
};
struct D {
	int mn, mx, sum, sz;

	static D op(D a, D b) {
		return {min(a.mn, b.mn), max(a.mx, b.mx), a.sum + b.sum, a.sz + b.sz};
	}

	static D e() { return {INT_MAX, INT_MIN, 0, 0}; }

	static D make(S s) { return {s.val, s.val, s.val, s.sz}; }

	// only necessary for non-commutative operations
	void reverse() {}
};
struct F {
	bool setflag;
	int set, inc;

	D apply(D d) {
		if (d.sz == 0) return d;
		D ret = d;
		if (setflag) {
			ret.mn = ret.mx = set;
			ret.sum = ret.sz * set;
		}
		ret.mn += inc, ret.mx += inc;
		ret.sum += inc * ret.sz;
		return ret;
	}

	S apply(S x) {
		D p = apply(D::make(x));
		return {p.sum, p.sz};
	}

	bool operator==(F other) {
		return setflag == other.setflag && set == other.set && inc == other.inc;
	}

	static F composition(F f, F g) {
		if (f.setflag) return f;
		g.inc += f.inc;
		return g;
	}

	static F id() { return {0, 0, 0}; }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M;
	cin >> N >> M;
	TopTree<S, D, F> tree(N + 1);
	for (int i = 1; i < N; ++i) {
		int a, b;
		cin >> a >> b;
		tree.link(a, b);
	}
	for (int i = 1; i <= N; ++i) {
		int a;
		cin >> a;
		tree.set(i, {a, 1});
	}
	int rt;
	cin >> rt;
	while (M--) {
		int op;
		cin >> op;
		if (op == 0) {	// set subtree
			int v, val;
			cin >> v >> val;
			tree.apply_subtree(v, rt, {1, val, 0});
		}
		if (op == 1) {	// change root
			cin >> rt;
		}
		if (op == 2) {	// set path
			int u, v, val;
			cin >> u >> v >> val;
			tree.apply_path(u, v, {1, val, 0});
		}
		if (op == 3) {	// subtree min
			int v;
			cin >> v;
			cout << tree.query_subtree(v, rt).mn << '\n';
		}
		if (op == 4) {	// subtree max
			int v;
			cin >> v;
			cout << tree.query_subtree(v, rt).mx << '\n';
		}
		if (op == 5) {	// increment subtree
			int v, val;
			cin >> v >> val;
			tree.apply_subtree(v, rt, {0, 0, val});
		}
		if (op == 6) {	// increment path
			int u, v, val;
			cin >> u >> v >> val;
			tree.apply_path(u, v, {0, 0, val});
		}
		if (op == 7) {	// path min
			int u, v;
			cin >> u >> v;
			cout << tree.query_path(u, v).mn << '\n';
		}
		if (op == 8) {	// path max
			int u, v;
			cin >> u >> v;
			cout << tree.query_path(u, v).mx << '\n';
		}
		if (op == 9) {	// change parent
			int v, p;
			cin >> v >> p;
			if (tree.lca(v, p, rt) != v) {
				tree.cut(v, rt);
				tree.link(v, p);
			}
		}
		if (op == 10) {	 // path sum
			int u, v;
			cin >> u >> v;
			cout << tree.query_path(u, v).sum << '\n';
		}
		if (op == 11) {	 // subtree sum
			int v;
			cin >> v;
			cout << tree.query_subtree(v, rt).sum << '\n';
		}
	}
}
