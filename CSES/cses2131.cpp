#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

// Source: atcoder library
// https://atcoder.github.io/ac-library/production/document_en/mincostflow.html
namespace atcoder {

namespace internal {

template <class T>
struct simple_queue {
	std::vector<T> payload;
	int pos = 0;
	void reserve(int n) { payload.reserve(n); }
	int size() const { return int(payload.size()) - pos; }
	bool empty() const { return pos == int(payload.size()); }
	void push(const T& t) { payload.push_back(t); }
	T& front() { return payload[pos]; }
	void clear() {
		payload.clear();
		pos = 0;
	}
	void pop() { pos++; }
};

template <class E>
struct csr {
	std::vector<int> start;
	std::vector<E> elist;
	explicit csr(int n, const std::vector<std::pair<int, E>>& edges)
			: start(n + 1), elist(edges.size()) {
		for (auto e : edges) {
			start[e.first + 1]++;
		}
		for (int i = 1; i <= n; i++) {
			start[i] += start[i - 1];
		}
		auto counter = start;
		for (auto e : edges) {
			elist[counter[e.first]++] = e.second;
		}
	}
};

}	 // namespace internal

template <class Cap, class Cost>
struct mcf_graph {
 public:
	mcf_graph() {}
	explicit mcf_graph(int n) : _n(n) {}

	int add_edge(int from, int to, Cap cap, Cost cost) {
		assert(0 <= from && from < _n);
		assert(0 <= to && to < _n);
		assert(0 <= cap);
		assert(0 <= cost);
		int m = int(_edges.size());
		_edges.push_back({from, to, cap, 0, cost});
		return m;
	}

	struct edge {
		int from, to;
		Cap cap, flow;
		Cost cost;
	};

	edge get_edge(int i) {
		int m = int(_edges.size());
		assert(0 <= i && i < m);
		return _edges[i];
	}
	std::vector<edge> edges() { return _edges; }

	std::pair<Cap, Cost> flow(int s, int t) {
		return flow(s, t, std::numeric_limits<Cap>::max());
	}
	std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
		return slope(s, t, flow_limit).back();
	}
	std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
		return slope(s, t, std::numeric_limits<Cap>::max());
	}
	std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
		assert(0 <= s && s < _n);
		assert(0 <= t && t < _n);
		assert(s != t);

		int m = int(_edges.size());
		std::vector<int> edge_idx(m);

		auto g = [&]() {
			std::vector<int> degree(_n), redge_idx(m);
			std::vector<std::pair<int, _edge>> elist;
			elist.reserve(2 * m);
			for (int i = 0; i < m; i++) {
				auto e = _edges[i];
				edge_idx[i] = degree[e.from]++;
				redge_idx[i] = degree[e.to]++;
				elist.push_back({e.from, {e.to, -1, e.cap - e.flow, e.cost}});
				elist.push_back({e.to, {e.from, -1, e.flow, -e.cost}});
			}
			auto _g = internal::csr<_edge>(_n, elist);
			for (int i = 0; i < m; i++) {
				auto e = _edges[i];
				edge_idx[i] += _g.start[e.from];
				redge_idx[i] += _g.start[e.to];
				_g.elist[edge_idx[i]].rev = redge_idx[i];
				_g.elist[redge_idx[i]].rev = edge_idx[i];
			}
			return _g;
		}();

		auto result = slope(g, s, t, flow_limit);

		for (int i = 0; i < m; i++) {
			auto e = g.elist[edge_idx[i]];
			_edges[i].flow = _edges[i].cap - e.cap;
		}

		return result;
	}

 private:
	int _n;
	std::vector<edge> _edges;

	// inside edge
	struct _edge {
		int to, rev;
		Cap cap;
		Cost cost;
	};

	std::vector<std::pair<Cap, Cost>> slope(internal::csr<_edge>& g, int s, int t,
																					Cap flow_limit) {
		// variants (C = maxcost):
		// -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
		// reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge

		// dual_dist[i] = (dual[i], dist[i])
		std::vector<std::pair<Cost, Cost>> dual_dist(_n);
		std::vector<int> prev_e(_n);
		std::vector<bool> vis(_n);
		struct Q {
			Cost key;
			int to;
			bool operator<(Q r) const { return key > r.key; }
		};
		std::vector<int> que_min;
		std::vector<Q> que;
		auto dual_ref = [&]() {
			for (int i = 0; i < _n; i++) {
				dual_dist[i].second = std::numeric_limits<Cost>::max();
			}
			std::fill(vis.begin(), vis.end(), false);
			que_min.clear();
			que.clear();

			// que[0..heap_r) was heapified
			size_t heap_r = 0;

			dual_dist[s].second = 0;
			que_min.push_back(s);
			while (!que_min.empty() || !que.empty()) {
				int v;
				if (!que_min.empty()) {
					v = que_min.back();
					que_min.pop_back();
				} else {
					while (heap_r < que.size()) {
						heap_r++;
						std::push_heap(que.begin(), que.begin() + heap_r);
					}
					v = que.front().to;
					std::pop_heap(que.begin(), que.end());
					que.pop_back();
					heap_r--;
				}
				if (vis[v]) continue;
				vis[v] = true;
				if (v == t) break;
				// dist[v] = shortest(s, v) + dual[s] - dual[v]
				// dist[v] >= 0 (all reduced cost are positive)
				// dist[v] <= (n-1)C
				Cost dual_v = dual_dist[v].first, dist_v = dual_dist[v].second;
				for (int i = g.start[v]; i < g.start[v + 1]; i++) {
					auto e = g.elist[i];
					if (!e.cap) continue;
					// |-dual[e.to] + dual[v]| <= (n-1)C
					// cost <= C - -(n-1)C + 0 = nC
					Cost cost = e.cost - dual_dist[e.to].first + dual_v;
					if (dual_dist[e.to].second - dist_v > cost) {
						Cost dist_to = dist_v + cost;
						dual_dist[e.to].second = dist_to;
						prev_e[e.to] = e.rev;
						if (dist_to == dist_v) {
							que_min.push_back(e.to);
						} else {
							que.push_back(Q{dist_to, e.to});
						}
					}
				}
			}
			if (!vis[t]) {
				return false;
			}

			for (int v = 0; v < _n; v++) {
				if (!vis[v]) continue;
				// dual[v] = dual[v] - dist[t] + dist[v]
				//         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +
				//         (shortest(s, v) + dual[s] - dual[v]) = - shortest(s,
				//         t) + dual[t] + shortest(s, v) = shortest(s, v) -
				//         shortest(s, t) >= 0 - (n-1)C
				dual_dist[v].first -= dual_dist[t].second - dual_dist[v].second;
			}
			return true;
		};
		Cap flow = 0;
		Cost cost = 0, prev_cost_per_flow = -1;
		std::vector<std::pair<Cap, Cost>> result = {{Cap(0), Cost(0)}};
		while (flow < flow_limit) {
			if (!dual_ref()) break;
			Cap c = flow_limit - flow;
			for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
				c = std::min(c, g.elist[g.elist[prev_e[v]].rev].cap);
			}
			for (int v = t; v != s; v = g.elist[prev_e[v]].to) {
				auto& e = g.elist[prev_e[v]];
				e.cap += c;
				g.elist[e.rev].cap -= c;
			}
			Cost d = -dual_dist[s].first;
			flow += c;
			cost += c * d;
			if (prev_cost_per_flow == d) {
				result.pop_back();
			}
			result.push_back({flow, cost});
			prev_cost_per_flow = d;
		}
		return result;
	}
};

}	 // namespace atcoder
using namespace atcoder;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<int> b(N);
	for (int i = 0; i < N; ++i) {
		cin >> b[i];
	}
	vector<vector<int>> prize(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> prize[i][j];
		}
	}

	int M = 2*N + N*N + 2;
	mcf_graph<int, int> g(M);
	int s = M-2, t = M-1;
	// 3 layer graph
	// first layer (nodes [0,n)) are rows
	// third layer (nodes [n,2n)) are columns
	// middle layer (x,y) connects row x with column y
	auto row = [&](int i) { return i; };
	auto col = [&](int i) { return N+i; };
	auto middle = [&](int i, int j) { return 2*N + i * N + j; };

	for (int i = 0; i < N; ++i) {
		g.add_edge(s, row(i), a[i], 0);
		g.add_edge(col(i), t, b[i], 0);
	}
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			g.add_edge(row(i), middle(i, j), 1, 1000 - prize[i][j]);
			g.add_edge(middle(i, j), col(j), 1, 0);
		}
	}
	g.flow(s, t);

	ll tot_prize = 0;
	vector<vector<char>> ans(N, vector<char>(N, '.'));
	for (auto [from, to, cap, flow, cost] : g.edges()) {
		if (0 <= from && from < N) { // if edge goes from first to second layer
			if (flow) {
				ans[from][to - 2*N - from*N] = 'X';
				tot_prize += 1000 - cost;
			}
		}
	}

	bool good = [&]() -> bool {
		for (int i = 0; i < N; ++i) {
			int cntr = 0, cntc = 0;
			for (int j = 0; j < N; ++j) {
				cntr += ans[i][j] == 'X';
				cntc += ans[j][i] == 'X';
			}
			if (cntr != a[i]) return 0;
			if (cntc != b[i]) return 0;
		}
		return 1;
	}();
	if (!good) cout << -1 << '\n';
	else {
		cout << tot_prize << '\n';
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < N; ++j) {
				cout << ans[i][j];
			}
			cout << '\n';
		}
	}
}
