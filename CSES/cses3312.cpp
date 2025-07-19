#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
  array<array<int, 2>, 3> others = {{{1, 2}, {0, 2}, {0, 1}}};
  int N, M; cin >> N >> M;
  vector<vector<int>> a(N, vector<int>(M));
  for (int i = 0; i < N; ++i) {
    for (int j = 0; j < M; ++j) {
      char c; cin >> c;
      a[i][j] = c - 'A';
    }
  }
  auto get = [&](int i, int j, int opt) {
    return (i * M + j) * 2 + opt;
  };
  TwoSat sat(2 * N * M);
  for (int i = 0; i < N; ++i) for (int j = 0; j < M; ++j) {
    sat.either(get(i, j, 0), get(i, j, 1));
    sat.either(~get(i, j, 0), ~get(i, j, 1));
    for (int x = 0; x < 2; ++x) for (int y = 0; y < 2; ++y) {
      if (i) {
        if (others[a[i][j]][x] == others[a[i-1][j]][y]) sat.either(~get(i, j, x), ~get(i-1, j, y));
      }
      if (j) {
        if (others[a[i][j]][x] == others[a[i][j-1]][y]) sat.either(~get(i, j, x), ~get(i, j-1, y));
      }
    }
  }
  bool feasible = sat.solve();
  if (!feasible) {
    cout << "IMPOSSIBLE" << '\n';
  }
  else {
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        cout << char('A' + others[a[i][j]][sat.values[get(i, j, 1)]]);
      }
      cout << '\n';
    }
  }
}
