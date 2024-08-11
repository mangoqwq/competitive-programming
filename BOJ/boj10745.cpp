#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

const int MN = 1e5 + 10;
int trie[MN][26], ch[MN], par[MN], term[MN], link[MN], dp[MN][26];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string S; cin >> S;
	int N; cin >> N;
	int T = 1;
	for (int i = 0; i < N; ++i) {
		string t; cin >> t;
		int v = 0;
		for (char c : t) {
			c -= 'a';
			if (trie[v][c] == 0) trie[v][c] = T++;
			par[trie[v][c]] = v;
			v = trie[v][c];
			ch[v] = c;
		}
		term[v] = t.size();
	}
	memset(link, -1, sizeof(link));
	memset(dp, -1, sizeof(dp));
	auto get_link = [&](auto self, auto other, int v) -> int {
		if (link[v] == -1) {
			if (v == 0 || par[v] == 0) link[v] = 0;
			else link[v] = other(other, self, self(self, other, par[v]), ch[v]);
		}
		return link[v];
	};
	auto go = [&](auto self, auto other, int v, int c) -> int {
		if (link[v] == -1) other(other, self, v);
		if (dp[v][c] == -1) {
			if (trie[v][c]) dp[v][c] = trie[v][c];
			else if (v == 0) dp[v][c] = 0;
			else dp[v][c] = self(self, other, other(other, self, v), c);
		}
		return dp[v][c];
	};
	string ans = "";
	vector<int> stk = {0};
	for (char c : S) {
		ans.push_back(c);
		c -= 'a';
		int v = stk.back();
		debug(v);
		v = go(go, get_link, v, c);
		stk.push_back(v);
		for (int i = 0; i < term[v]; ++i) {
			stk.pop_back();
			ans.pop_back();
		}
		debug(ans);
	}
	cout << ans << '\n';
}
