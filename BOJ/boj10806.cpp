#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
	struct Edge{ int to, i; };
	vector<vector<Edge>> graph(N);
	for (int i = 0; i < M; ++i){
		int a, b; cin >> a >> b;
		a--, b--;
		graph[a].push_back({b, i});
		graph[b].push_back({a, i});
	}
	int T = 0;
	vector<int> stk;
	vector<int> in(N), up(N), rt(N);
	auto go = [&](auto self, int v, int p) -> void{
		in[v] = up[v] = ++T;
		stk.push_back(v);
		for (auto [to, id] : graph[v]){
			if (id == p) continue;
			if (in[to]) up[v] = min(up[v], in[to]);
			else{
				self(self, to, id);
				up[v] = min(up[v], up[to]);
			}
		}
		if (in[v] == up[v]){
			while (true){
				int u = stk.back();
				stk.pop_back();
				rt[u] = v;
				if (u == v) break;
			}
		}
	};
	go(go, 0, -1);
	
	vector<set<int>> adj(N);
	for (int i = 0; i < N; ++i){
		for (auto [to, id] : graph[i]){
			if (rt[to] == rt[i]) continue;
			adj[rt[i]].insert(rt[to]);
		}
	}

	vector<int> cl(N);
	auto cntleaves = [&](auto self, int v, int p) -> int{
		cl[v] = (adj[v].size() == 1);
		for (int to : adj[v]){
			if (to == p) continue;
			cl[v] += self(self, to, v);
		}
		return cl[v];
	};
	cntleaves(cntleaves, 0, 0);

	auto locate = [&](auto self, int v, int p, int rtcl) -> int{
		for (int to : adj[v]){
			if (to == p) continue;
			if (cl[to] * 2 > rtcl)
				return self(self, to, v, rtcl);
		}
		return v;
	};
	int cen = locate(locate, 0, 0, cl[0]);

	vector<vector<int>> leaves(N);
	auto work = [&](auto self, int v, int p, int rt) -> void{
		if (adj[v].size() == 1) leaves[rt].push_back(v);
		for (int to : adj[v]){
			if (to == p) continue;
			self(self, to, v, rt);
		}
	};
	for (int to : adj[cen]){
		work(work, to, cen, to);
	}

	using pii = pair<int, int>;
	priority_queue<pii> pq;
	for (int to : adj[cen]){
		pq.push({leaves[to].size(), to});
	}
	vector<pii> ans;
	while (!pq.empty()){
		if (pq.size() == 1){
			auto [_, c] = pq.top(); pq.pop();
			ans.push_back({leaves[c][0], cen});
			assert(leaves[c].size() == 1);
		}
		else{
			auto [_, c] = pq.top(); pq.pop();
			auto [__, d] = pq.top(); pq.pop();
			ans.push_back({leaves[c].back(), leaves[d].back()});
			leaves[c].pop_back();
			leaves[d].pop_back();
			if (leaves[c].size()){
				pq.push({leaves[c].size(), c});
			}
			if (leaves[d].size()){
				pq.push({leaves[d].size(), d});
			}
		}
	}
	cout << ans.size() << '\n';
	for (auto [a, b] : ans){
		a++, b++;
		cout << a << " " << b << '\n';
	}
}
