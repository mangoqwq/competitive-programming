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
	vector<int> can(M+1);
	can[0] = 1;
	for (int i = 0; i < N; ++i) {
		vector<int> nxt = can;
		string s; cin >> s;
		int cnt = ranges::count_if(s, [&](char c) { return c == '1'; });
		for (int j = 0; j <= M; ++j) {
			if (!can[j]) continue;
			for (int overlap = 0; overlap <= cnt; ++overlap) {
				int other = cnt - overlap;
				if (overlap > j || other > M-j) continue;
				nxt[j - overlap + other] = 1;
			}
		}
		can = nxt;
		debug(can);
	}
	int ans = 0;
	for (int i = 0; i <= M; ++i) {
		if (can[i]) ans = i;
	}
	for (int i = 0; i < M; ++i) {
		cout << (i < ans ? '1' : '0');
	}
	cout << '\n';
}
