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
	int N, K; cin >> N >> K;
	vector<vector<int>> adj(N);
	for (int i = 0; i < N-1; ++i) {
		int a, b; cin >> a >> b;
		a--, b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	vector<ll> val(N);
	for (int i = 0; i < N; ++i) {
		cin >> val[i];
	}
 
	vector<int> ans;
 
	if (K == 1) {
		vector<int> best(N, -1);
		auto calc = [&](auto self, int v, int p) -> ll {
			ll ret = 0;
			for (int to : adj[v]) {
				if (to == p) continue;
				ll nxt = self(self, to, v);
				if (nxt > ret) best[v] = to, ret = nxt;
			}
			ret += val[v];
			return ret;
		};
		calc(calc, 0, 0);
		ans = {0};
		while (best[ans.back()] != -1) {
			ans.push_back(best[ans.back()]);
		}
	}
	else if (K == 2) {
		struct pi { 
			ll val; int x;
			bool operator< (const pi &other) const {
				return val < other.val;
			}
		};
		struct pii { 
			ll val; int x, y;
			bool operator< (const pii &other) const {
				return val < other.val;
			}
		};
		struct piii {
			ll val; int x, y, z;
			bool operator< (const piii &other) const {
				return val < other.val;
			}
		};
		// 1 dark, 1 white, (collect)
		vector<pii> white1(N, {0, -1, -1});
		// 1 dark, 1 light, 1 black (collect)
		vector<piii> white2(N, {0, -1, -1, -1});
		// 1 white
		vector<pi> black1(N, {0, -1});
		// 1 light, 1 black, (collect)
		vector<pii> black2(N, {0, -1, -1});
		// 1 light, (collect)
		vector<pi> dark(N, {0, -1});
		// 1 dark, (collect)
		vector<pi> light(N, {0, -1});
 
		auto getwhite = [&](int v) -> ll {
			return max(white1[v].val, white2[v].val);
		};
		auto getblack = [&](int v) -> ll {
			return max(black1[v].val, black2[v].val);
		};
 
		vector<ll> collect(N, 0);
		auto dfs = [&](auto self, int v, int p) -> void {
			for (int to : adj[v]) {
				if (to == p) continue;
				self(self, to, v);
				collect[v] += val[to];
			}
 
			// calc white1
			{
				vector<pii> best(4, {0, -1, -1});
				for (int to : adj[v]) if (to != p) {
					for (int h = 3; h >= 0; --h) {
						if (!(1 & h)) {
							pii cur = {best[h].val + dark[to].val, to, best[h].y};
							best[1|h] = max(best[1|h], cur);
						}
						if (!(2 & h)) {
							pii cur = {best[h].val + getwhite(to), best[h].x, to};
							best[2|h] = max(best[2|h], cur);
						}
						best[h].val += val[to];
					}
				}
				white1[v] = (*max_element(best.begin(), best.end()));
				white1[v].val += val[v];
			}
 
			// calc white2
			{
				vector<piii> best(8, {0, -1, -1, -1});
				for (int to : adj[v]) if (to != p) {
					for (int h = 7; h >= 0; --h) {
						if (!(1 & h)) {
							piii cur = {best[h].val + dark[to].val, to, best[h].y, best[h].z};
							best[1|h] = max(best[1|h], cur);
						}
						if (!(2 & h)) {
							piii cur = {best[h].val + light[to].val, best[h].x, to, best[h].z};
							best[2|h] = max(best[2|h], cur);
						}
						if (!(4 & h)) {
							piii cur = {best[h].val + getblack(to), best[h].x, best[h].y, to};
							best[4|h] = max(best[4|h], cur);
						}
						best[h].val += val[to];
					}
				}
				white2[v] = (*max_element(best.begin(), best.end()));
				white2[v].val += val[v];
			}
 
			// calc black1
			{
				for (int to : adj[v]) if (to != p) {
					pi cur = {getwhite(to), to};
					black1[v] = max(black1[v], cur);
				}
				black1[v].val += val[v];
			}
 
			// calc black2
			{
				vector<pii> best(4, {0, -1, -1});
				for (int to : adj[v]) if (to != p) {
					for (int h = 3; h >= 0; --h) {
						if (!(1 & h)) {
							pii cur = {best[h].val + light[to].val, to, best[h].y};
							best[1|h] = max(best[1|h], cur);
						}
						if (!(2 & h)) {
							pii cur = {best[h].val + getblack(to), best[h].x, to};
							best[2|h] = max(best[2|h], cur);
						}
						best[h].val += val[to];
					}
				}
				black2[v] = (*max_element(best.begin(), best.end()));
				black2[v].val += val[v];
			}
 
			// calc dark
			{
				for (int to : adj[v]) if (to != p) {
					pi cur = {collect[v] - val[to] + light[to].val, to};
					dark[v] = max(dark[v], cur);
				}
				dark[v].val += val[v];
			}
 
			// calc light
			{
				for (int to : adj[v]) if (to != p) {
					pi cur = {collect[v] - val[to] + dark[to].val, to};
					light[v] = max(light[v], cur);
				}
				light[v].val += val[v];
			}
		};
		dfs(dfs, 0, 0);
		auto construct = [&](auto self, int v, int p, int b) -> void {
			if (b == 0) { // black
				if (black1[v].val >= black2[v].val) {
					// 1 white
					int nwhite = black1[v].x;
					ans.push_back(v);
					if (nwhite != -1) self(self, nwhite, v, 1);
				}
				else {
					// 1 light, collect, 1 black
					int nlight = black2[v].x;
					int nblack = black2[v].y;
					ans.push_back(v);
					if (nlight != -1) self(self, nlight, v, 3);
					for (int to : adj[v]) {
						if (to == p) continue;
						if (to == nlight || to == nblack) continue;
						ans.push_back(to);
					}
					if (nblack != -1) self(self, nblack, v, 0);
				}
			}
			else if (b == 1) { // white
				if (white1[v].val == getwhite(v)) {
					// collect, 1 dark, 1 white
					int ndark = white1[v].x;
					int nwhite = white1[v].y;
					for (int to : adj[v]) {
						if (to == p) continue;
						if (to == nwhite || to == ndark) continue;
						ans.push_back(to);
					}
					if (ndark != -1) self(self, ndark, v, 2);
					ans.push_back(v);
					if (nwhite != -1) self(self, nwhite, v, 1);
				}
				else if (white2[v].val == getwhite(v)) {
					// 1 dark, collect, 1 light, 1 black
					int ndark = white2[v].x;
					int nlight = white2[v].y;
					int nblack = white2[v].z;
					if (ndark != -1) self(self, ndark, v, 2);
					ans.push_back(v);
					if (nlight != -1) self(self, nlight, v, 3);
					for (int to : adj[v]) {
						if (to == p) continue;
						if (to == ndark || to == nlight || to == nblack) continue;
						ans.push_back(to);
					}
					if (nblack != -1) self(self, nblack, v, 0);
				}
			}
			else if (b == 2) { // dark
				// one light, collect
				int nlight = dark[v].x;
				ans.push_back(v);
				if (nlight != -1) self(self, nlight, v, 3);
				for (int to : adj[v]) {
					if (to == p) continue;
					if (to == nlight) continue;
					ans.push_back(to);
				}
			}
			else if (b == 3) { // light
				// collect, one dark
				int ndark = light[v].x;
				for (int to : adj[v]) {
					if (to == p) continue;
					if (to == ndark) continue;
					ans.push_back(to);
				}
				if (ndark != -1) self(self, ndark, v, 2);
				ans.push_back(v);
			}
		};
		construct(construct, 0, 0, 0);
	}
	else if (K == 3) { // always possible to visit everywhere
		auto dfs = [&](auto self, int v, int p, bool root_first) -> void {
			if (root_first) ans.push_back(v);
			for (int to : adj[v]) {
				if (to == p) continue;
				self(self, to, v, !root_first);
			}
			if (!root_first) ans.push_back(v);
		};
		dfs(dfs, 0, 0, 1);
	}
 
	ll tot = 0;
	for (int x : ans) tot += val[x];
	cout << tot << '\n';
	cout << ans.size() << '\n';
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i]+1 << (i == ans.size()-1 ? '\n' : ' ');
	}
}
