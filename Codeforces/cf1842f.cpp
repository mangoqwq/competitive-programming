#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<vector<int>> adj(N);
	for (int i = 0; i < N-1; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}

	vector<ll> ans(N+1);
	ans[1] = N-1;
	auto attempt = [&](int rt) {
		struct Item {
			int st, v, dep;
			bool operator<(const Item &other) const {
				return dep > other.dep;
			}
		};
		priority_queue<Item> pq;
		vector<priority_queue<Item>> sts(N);
		vector<int> dep(N);
		vector<int> sub(N);
		dep[rt] = 0;
		for (int to : adj[rt]) {
			dep[to] = 1;
			sts[to].push({to, to, dep[to]});
			pq.push({to, to, dep[to]});
		}

		ll cur = N-1;
		for (int i = 2; i <= N; ++i) {
			Item x = pq.top(); pq.pop();
			if ((sub[x.st]+1) * 2 > i) {
				if (pq.empty()) return;
				Item y = x;
				x = pq.top(); pq.pop();
				pq.push(y);
			}
			debug(x.v, x.st, sub[x.st], i);
			sub[x.st]++;
			sts[x.st].pop();
			cur -= i-1; // old v
			cur += i-2; // v
			cur += (i-2); // +1s
			cur -= 2 * (x.dep-1); // path to root
			cur += (N-1) - (i-1); // outside black tree
			for (int to : adj[x.v]) {
				if (to != rt && !dep[to]) {
					dep[to] = dep[x.v] + 1;
					sts[x.st].push({x.st, to, dep[to]});
				}
			}
			if (!sts[x.st].empty()) {
				pq.push(sts[x.st].top());
			}
			ans[i] = max(ans[i], cur);
		}
	};

	for (int i = 0; i < N; ++i) {
		attempt(i);
	}

	for (int i = 0; i <= N; ++i) {
		cout << ans[i] << (i == N ? '\n' : ' ');
	}
}
