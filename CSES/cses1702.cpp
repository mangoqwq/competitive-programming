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
	vector<int> pre(N), in(N);
	for (int i = 0; i < N; ++i) {
		cin >> pre[i]; pre[i]--;
	}
	vector<int> idx(N);
	for (int i = 0; i < N; ++i) {
		cin >> in[i]; in[i]--;
		idx[in[i]] = i;
	}
	int p = 1;
	vector<vector<int>> c(N, vector<int>(2, -1));
	auto dfs = [&](auto self, int rt, int l, int r) {
		if (p == N) return;
		int mid = idx[rt];
		int nrt = pre[p]; 
		if (l <= idx[nrt] && idx[nrt] < mid) {
			c[rt][0] = nrt;
			p++;
			self(self, nrt, l, mid);
		}
		nrt = pre[p]; 
		if (mid <= idx[nrt] && idx[nrt] < r) {
			c[rt][1] = nrt;
			p++;
			self(self, nrt, mid, r);
		}
	};
	int rt = pre[0]; 
	dfs(dfs, rt, 0, N);

	vector<int> post;
	auto go = [&](auto self, int v) -> void {
		if (c[v][0] != -1) self(self, c[v][0]);
		if (c[v][1] != -1) self(self, c[v][1]);
		post.push_back(v);
	};
	go(go, rt);
	debug(c);
	for (int i = 0; i < N; ++i) {
		cout << post[i]+1 << (i == N-1 ? '\n' : ' ');
	}
}
