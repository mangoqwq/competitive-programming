#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct DisjointSet {
	vector<int> p, sz;
	vector<set<int>> active;
	DisjointSet(int N) {
		p.resize(N);
		iota(p.begin(), p.end(), 0);
		sz.resize(N, 1);
		active.resize(N);
		for (int i = 0; i < N; ++i) {
			active[i] = {i};
		}
	}
	int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }
	bool unite(int a, int b) {
		a = root(a), b = root(b);
		if (a == b) return 0;
		if (sz[b] > sz[a]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		for (int x : active[b]) active[a].insert(x);
		return 1;
	}
};

/**
 * Author: Emil Lenngren, Simon Lindholm
 * Date: 2011-11-29
 * License: CC0
 * Source: folklore
 * Description: Calculates a valid assignment to boolean variables a, b, c,... to a 2-SAT problem, so that an expression of the type $(a\|\|b)\&\&(!a\|\|c)\&\&(d\|\|!b)\&\&...$ becomes true, or reports that it is unsatisfiable.
 * Negated variables are represented by bit-inversions (\texttt{\tilde{}x}).
 * Usage:
 *  TwoSat ts(number of boolean variables);
 *  ts.either(0, \tilde3); // Var 0 is true or var 3 is false
 *  ts.setValue(2); // Var 2 is true
 *  ts.atMostOne({0,\tilde1,2}); // <= 1 of vars 0, \tilde1 and 2 are true
 *  ts.solve(); // Returns true iff it is solvable
 *  ts.values[0..N-1] holds the assigned values to the vars
 * Time: O(N+E), where N is the number of boolean variables, and E is the number of clauses.
 * Status: stress-tested
 */
struct TwoSat {
	int N;
	vector<vi> gr;
	vi values; // 0 = false, 1 = true

	TwoSat(int n = 0) : N(n), gr(2*n) {}

	int addVar() { // (optional)
		gr.emplace_back();
		gr.emplace_back();
		return N++;
	}

	void either(int f, int j) {
		f = max(2*f, -1-2*f);
		j = max(2*j, -1-2*j);
		gr[f].push_back(j^1);
		gr[j].push_back(f^1);
	}
	void setValue(int x) { either(x, x); }

	void atMostOne(const vi& li) { // (optional)
		if (sz(li) <= 1) return;
		int cur = ~li[0];
		rep(i,2,sz(li)) {
			int next = addVar();
			either(cur, ~li[i]);
			either(cur, next);
			either(~li[i], next);
			cur = ~next;
		}
		either(cur, ~li[1]);
	}

	vi val, comp, z; int time = 0;
	int dfs(int i) {
		int low = val[i] = ++time, x; z.push_back(i);
		for(int e : gr[i]) if (!comp[e])
			low = min(low, val[e] ?: dfs(e));
		if (low == val[i]) do {
			x = z.back(); z.pop_back();
			comp[x] = low;
			if (values[x>>1] == -1)
				values[x>>1] = x&1;
		} while (x != i);
		return val[i] = low;
	}

	bool solve() {
		values.assign(N, -1);
		val.assign(2*N, 0); comp = val;
		rep(i,0,2*N) if (!comp[i]) dfs(i);
		rep(i,0,N) if (comp[2*i] == comp[2*i+1]) return 0;
		return 1;
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
		a[i]--;
	}

	auto bad = [&]() -> void {
		cout << "IMPOSSIBLE" << '\n';
		exit(0);
	};

	TwoSat ts(N);
	auto force_same = [&](int i, int j) {
		debug("SAME", i+1, j+1);
		ts.either(i, ~j);
		ts.either(~i, j);
	};
	auto force_diff = [&](int i, int j) {
		debug("DIFF", i+1, j+1);
		ts.either(i, j);
		ts.either(~i ,~j);
	};

	vector<int> in(N);
	set<int> s;
	int need = 0;
	DisjointSet dsu(N);
	for (int i = 0; i < N; ++i) {
		in[a[i]] = 1;
		vector<int> smaller;
		while (!s.empty() && *s.begin() < a[i]) {
			smaller.push_back(*s.begin());
			s.erase(s.begin());
		}
		if (!smaller.empty()) {
			force_diff(a[i], smaller[0]);
			for (int j = 1; j < smaller.size(); ++j) {
				force_same(smaller[j], smaller[0]);
				dsu.unite(smaller[0], smaller[j]);
			}
			s.insert(smaller[0]);
		}

		s.insert(a[i]);
		while (need < N && in[need]) {
			s.erase(*dsu.active[dsu.root(need)].begin());
			dsu.active[dsu.root(need)].erase(need);
			if (!dsu.active[dsu.root(need)].empty())
				s.insert(*dsu.active[dsu.root(need)].begin());
			need++;
		}
	}

	bool result = ts.solve();
	debug(result);
	if (!result) bad();
	vector<int> ans = ts.values;
	debug(ans);

	// verify
	vector<vector<int>> stks(2, vector<int>(1, N));
	need = 0;
	for (int i = 0; i < N; ++i) {
		stks[ans[a[i]]].push_back(a[i]);
		while (need < N && min(stks[0].back(), stks[1].back()) == need) {
			if (stks[0].back() == need) stks[0].pop_back();
			if (stks[1].back() == need) stks[1].pop_back();
			need++;
		}
	}
	debug(need);
	if (need != N) bad();
	for (int i = 0; i < N; ++i) {
		cout << ans[a[i]]+1 << (i == N-1 ? '\n' : ' ');
	}
}
