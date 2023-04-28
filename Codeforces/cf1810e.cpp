#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int N, M; cin >> N >> M;
		vector<int> power(N);
		for (int i = 0; i < N; ++i){
			cin >> power[i];
		}
		vector<vector<int>> adj(N);
		for (int i = 0; i < M; ++i){
			int a, b; cin >> a >> b;
			a--, b--;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}

		vector<int> based(N);
		vector<int> inq(N);
		auto prims = [&](int src) -> int {
			vector<int> touched;
			int in = 0;
			using pii = pair<int, int>;
			priority_queue<pii, vector<pii>, greater<pii>> pq;
			pq.push({0, src});
			inq[src] = 1;
			touched.push_back(src);
			while (!pq.empty()){
				auto [d, v] = pq.top(); pq.pop();
				if (d > in) break;
				based[v] = 1;
				in++;
				for (int to : adj[v]){
					if (!inq[to]){
						inq[to] = 1;
						touched.push_back(to);
						pq.push({power[to], to});
					}
				}
			}

			for (int x : touched) inq[x] = 0;
			return in;
		};

		for (int i = 0; i < N; ++i){
			if (!based[i] && power[i] == 0 && prims(i) == N){
				cout << "YES" << '\n';
				return;
			}
		}
		cout << "NO" << '\n';
	}();
}
