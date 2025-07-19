#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M; cin >> N >> M;
	vector<vector<int>> adj(N + 1);
	vector<vector<int>> rev(N + 1);
	for (int i = 0; i < M; ++i) {
		int a, b; cin >> a >> b;
		adj[a].push_back(b);
		rev[b].push_back(a);
	}

	vector<int> deg(N + 1);
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		deg[i] = rev[i].size();
		if (deg[i] == 0) {
			q.push(i);
		}
	}

	vector<int> ord;
	while (!q.empty()) {
		int v = q.front(); q.pop();
		ord.push_back(v);
		for (int to : adj[v]) {
			deg[to]--;
			if (deg[to] == 0) q.push(to);
		}
	}

	vector<int> other(N);
	set<int> ends = {0};
	for (int i = 1; i < N; ++i) {
		int v = ord[i];
		int lst = ord[i - 1];
		bool from_lst = ranges::find(rev[v], lst) != rev[v].end();
		bool from_ends = [&]() {
			for (int from : rev[v]) {
				if (ends.count(from)) {
					other[i] = lst;
					other[i - 1] = from;
					return 1;
				}
			}
			if (ends.count(0)) {
				other[i] = lst;
				other[i - 1] = 0;
				return 1;
			}
			return 0;
		}();
		if (from_lst) {
			if (from_ends) ends.insert(lst);
			other[i] = *ends.begin();
		}
		else {
			if (!from_ends) {
				cout << "NO" << '\n';
				return 0;
			}
			ends = {lst};
		}
	}

	vector<vector<int>> paths(2);
	int target = other[N - 1], cur = 0;
	paths[cur] = {ord[N - 1]};
	for (int i = N - 2; i >= 0; --i) {
		int v = ord[i];
		if (v == target) {
			target = other[i];
			cur ^= 1;
		}
		paths[cur].push_back(v);
	}
	cout << "YES" << '\n';
	for (int p = 0; p < 2; ++p) {
		ranges::reverse(paths[p]);
		cout << paths[p].size();
		for (int v : paths[p]) {
			cout << " " << v;	
		}
		cout << '\n';
	}
}
