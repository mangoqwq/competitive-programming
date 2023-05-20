#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

/*
which course is completed last?
clearly must be a course with no other courses requiring it
pick the one with the largest index i
this must be optimal (say some j < i was picked as last instead, then we can swap j and i in final ordering)
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> adj(N);
	vector<int> deg(N);
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[b].push_back(a);
		deg[a]++;
	}

	priority_queue<int> pq;
	for (int i = 0; i < N; ++i) {
		if (deg[i] == 0) pq.push(i);
	}

	vector<int> ans(N);
	int idx = N-1;
	while (!pq.empty()) {
		int v = pq.top(); pq.pop();
		ans[idx--] = v;
		for (int to : adj[v]) {
			deg[to]--;
			if (deg[to] == 0) {
				pq.push(to);
			}
		}
	}

	for (int i = 0; i < N; ++i) {
		cout << ans[i]+1 << (i == N-1 ? '\n' : ' ');
	}
}
