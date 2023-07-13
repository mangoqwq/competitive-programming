#include "cyberland.h"

#include <bits/stdc++.h>
using namespace std;

double solve(int N, int M, int K, int H, vector<int> x, vector<int> y, vector<int> c, vector<int> arr) {
	struct Edge { int to; double w; };
	vector<vector<Edge>> adj(N);
	for (int i = 0; i < M; ++i) {
		adj[x[i]].push_back({y[i], (double)c[i]});
		adj[y[i]].push_back({x[i], (double)c[i]});
	}

	K = min(K, 100);

	double eps = 1e-9;
	auto eq = [&](double a, double b) {
		if (a == 0 && b == 0) return true;
		return min(abs(a-b)/a, abs(a-b)/b) <= eps;
	};

	vector<bool> reach(N);
	auto dfs = [&](auto self, int v) -> void {
		reach[v] = 1;
		if (v == H) return;
		for (auto [to, w] : adj[v]) {
			if (reach[to]) continue;
			self(self, to);
		}
	};
	dfs(dfs, 0);

	struct Item {
		int v, num;
		double d;
		bool operator<(const Item &other) const {
			return d > other.d;
		}
	};
	vector<vector<double>> dist(N, vector<double>(K+1, 1e18));
	priority_queue<Item> pq;
	dist[H][0] = 0;
	pq.push({H, 0, 0});

	double ans = 1e18;
	while (!pq.empty()) {
		auto [v, num, d] = pq.top(); pq.pop();
		if (!eq(d, dist[v][num])) continue;
		for (auto [to, w] : adj[v]) {
			if (to == H) continue;
			double nd = d + (w / pow(2, num));
			if (nd < dist[to][num]) {
				dist[to][num] = nd;
				pq.push({to, num, nd});
			}
			if (arr[to] == 2 && num < K) {
				if (nd < dist[to][num+1]) {
					dist[to][num+1] = nd;
					pq.push({to, num+1, nd});
				}
			}
			if (arr[to] == 0 && reach[to]) {
				ans = min(ans, nd);
			}
		}
	}

	for (int i = 0; i <= K; ++i) {
		ans = min(ans, dist[0][i]);
	}
	if (eq(ans, 1e18)) return -1;
	else return ans;
}
