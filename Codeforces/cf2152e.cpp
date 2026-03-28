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
	int T; cin >> T;
	while (T--) [&]() {
		int N; cin >> N;
		int M = N * N + 1;
		vector<int> in(M, 1);
		vector<vector<int>> scrapers;
		auto read_int = [&]() -> int {
			int x; cin >> x;
			if (x == -1) exit(0);
			return x;
		};
		for (int i = 0; i < N; ++i) {
			vector<int> qry;
			for (int j = 0; j < M; ++j) {
				if (in[j]) qry.push_back(j);
			}
			cout << "? " << qry.size();
			for (int x : qry) {
				cout << " " << x + 1;
			}
			cout << '\n';
			cout.flush();
			int c = read_int();
			vector<int> ret;
			for (int j = 0; j < c; ++j) {
				int idx = read_int() - 1;
				ret.push_back(idx);
				in[idx] = 0;
			}
			if (c >= N + 1) {
				cout << "!";
				for (int j = 0; j <= N; ++j) {
					cout << " " << ret[j] + 1;
				}
				cout << '\n';
				cout.flush();
				return;
			}
			scrapers.push_back(ret);
		}
		vector<int> ans;
		int idx = ranges::find(in, 1) - in.begin();
		ans.push_back(idx);
		for (int i = N - 1; i >= 0; --i) {
			debug(scrapers[i], idx);
			idx = *(--ranges::lower_bound(scrapers[i], idx));
			ans.push_back(idx);
		}
		ranges::reverse(ans);
		cout << "!";
		for (int i = 0; i <= N; ++i) {
			cout << " " << ans[i] + 1;
		}
		cout << '\n';
		cout.flush();
	}();
}
