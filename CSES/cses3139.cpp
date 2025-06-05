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
	int N; cin >> N;
	auto lt = [&](int i, int j) {
		cout << "? " << i + 1 << " " << j + 1 << '\n';
		cout.flush();
		string res; cin >> res;
		return res == "YES";
	};

	vector<int> idxs(N);
	iota(idxs.begin(), idxs.end(), 0);
	auto go = [&](auto self, int l, int r) -> void {
		if (l + 1 == r) return;
		int m = (l + r) >> 1;
		self(self, l, m);
		self(self, m, r);
		vector<int> nxt(r - l);
		merge(idxs.begin() + l, idxs.begin() + m, idxs.begin() + m, idxs.begin() + r, nxt.begin(), lt);
		ranges::copy(nxt, idxs.begin() + l);
	};
	go(go, 0, N);

	vector<int> ans(N);
	for (int i = 0; i < N; ++i) {
		ans[idxs[i]] = i;
	}
	cout << "! ";
	for (int i = 0; i < N; ++i) {
		cout << ans[i] + 1 << (i == N - 1 ? '\n' : ' ');
	}
}
