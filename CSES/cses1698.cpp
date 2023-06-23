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
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i]; a[i]--;
	}

	vector<int> vis(N);
	map<int, vector<pair<int, int>>> ans;
	for (int i = 0; i < N; ++i) {
		if (vis[i]) continue;
		vis[i] = 1;
		deque<int> cur = {i};
		for (int j = a[i]; j != i; j = a[j]) {
			cur.push_back(j);
			vis[j] = 1;
		}
		int n = cur.size();
		if (n == 2) {
			ans[1].push_back({cur[0], cur[1]});
		}
		else if (n > 2) {
			if (n % 2 == 1) {
				ans[1].push_back({cur[0], cur[1]});
				cur.erase(cur.begin()+1);
				n--;
			}
			for (int i = 1; i < n-i; ++i) {
				ans[1].push_back({cur[i], cur[n-i]});
			}
			ans[2].push_back({cur[0], cur[1]});
			for (int i = 2; i < n-i+1; ++i) {
				ans[2].push_back({cur[i], cur[n-i+1]});
			}
		}
	}

	cout << ans.size() << '\n';
	for (auto [r, v] : ans) {
		cout << v.size() << '\n';
		for (auto [a, b] : v) {
			cout << a+1 << " " << b+1 << '\n';
		}
	}
}
