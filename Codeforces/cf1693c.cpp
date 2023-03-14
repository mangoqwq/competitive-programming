#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> adj(N);
	vector<vector<int>> rev(N);
	for (int i = 0; i < M; ++i){
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}

	vector<int> ans(N, 1e9), vis(N), deg(N);
	for (int i = 0; i < N; ++i) deg[i] = adj[i].size();

	using pii = pair<int, int>;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	ans[N-1] = 0;
	pq.push({0, N-1});
	while (!pq.empty()){
		auto [d, v] = pq.top(); pq.pop();
		if (vis[v]) continue;
		ans[v] = d;
		vis[v] = 1;
		for (int to : rev[v]){
			if (!vis[to]){
				deg[to]--;
				pq.push({d + deg[to] + 1, to});
			}
		}
	}
	cout << ans[0] << '\n';
}
