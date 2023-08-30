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
		cin >> a[i];
	}

	struct Item {
		int idx, x;
	};
	set<int> in = {a[0]};
	vector<Item> stk = {{0, a[0]}};
	for (int i = 1; i < N; ++i) {
		while (in.count(a[i])) {
			int c = stk.back().x;
			stk.pop_back();
			in.erase(c);
		}
		stk.push_back({i, a[i]});
		in.insert(a[i]);
	}

	vector<int> ans(N);
	int i = 0;
	for (auto [idx, x] : stk) {
		while (i <= idx) ans[i++] = x;
	}
	for (int i = 0; i < N; ++i) {
		cout << ans[i] << '\n';
	}
}
