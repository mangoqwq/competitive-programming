#include <algorithm>
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
	string key;
	vector<vector<int>> adj(10);
	vector<int> deg(10);
	while (cin >> key) {
		for (auto &c : key) c -= '0';
		adj[key[0]].push_back(key[1]);
		adj[key[1]].push_back(key[2]);
		deg[key[1]]++;
		deg[key[2]]++;
	}

	debug(deg);

	queue<int> q;
	for (int i = 0; i < 10; ++i) {
		if (deg[i] == 0 && !adj[i].empty()) q.push(i);
	}
	while (!q.empty()) {
		int x = q.front(); q.pop();
		cout << x;
		for (int to : adj[x]) {
			deg[to]--;
			if (deg[to] == 0) q.push(to);
		}
	}
	cout << '\n';
}
