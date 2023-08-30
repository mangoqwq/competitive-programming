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
	int T; cin >> T;
	while (T--) [&]() {
		int N, M; ll K; cin >> N >> M >> K;
		vector<ll> h(N);
		for (int i = 0; i < N; ++i) {
			cin >> h[i];
		}
		vector<int> deg(N);
		vector<vector<int>> adj(N);
		for (int i = 0; i < M; ++i) {
			int a, b; cin >> a >> b;
			a--, b--;
			deg[b]++;
			adj[a].push_back(b);
		}

		using pii = pair<ll, ll>;
		vector<set<pii>> s(N);
		auto calc = [&](int i) {
			auto [d, t] = *(--s[i].end());
			if (t > h[i]) return d+1;
			else return d;
		};

		vector<int> day(N);
		queue<int> q;
		vector<int> rts;
		for (int i = 0; i < N; ++i) {
			if (deg[i] == 0) {
				day[i] = 0;
				q.push(i);
				rts.push_back(i);
			}
		}
		sort(rts.begin(), rts.end(), [&](int i, int j) -> bool {
			return h[i] < h[j];
		});

		while (!q.empty()) {
			int v = q.front(); q.pop();
			for (int to : adj[v]) {
				deg[to]--;
				s[to].insert({day[v], h[v]});
				if (deg[to] == 0) {
					day[to] = calc(to);
					q.push(to);
				}
			}
		}

		auto endtime = [&](int i) -> ll {
			return day[i] * K + h[i];
		};
		ll mx = 0;
		for (int i = 0; i < N; ++i) {
			mx = max(mx, endtime(i));
		}

		vector<int> inq(N);
		auto relax = [&](auto self, int rt) {
			queue<int> q;
			q.push(rt);
			inq[rt] = 1;
			while (!q.empty()) {
				int v = q.front(); q.pop();
				inq[v] = 0;
				for (int to : adj[v]) {
					s[to].erase({day[v], h[v]});
					s[to].insert({day[v]+1, h[v]});
					if (calc(to) != day[to] && !inq[to]) {
						q.push(to);
						inq[to] = 1;
					}
				}
				day[v]++;
				debug("->", v, day);
				mx = max(mx, endtime(v));
			}
		};

		ll ans = 9e18;
		for (int v : rts) {
			ans = min(ans, mx - endtime(v));
			relax(relax, v);
			debug(day);
		}
		cout << ans << '\n';
	}();
}
