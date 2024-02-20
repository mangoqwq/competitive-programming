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
		int N; cin >> N;
		deque<int> a(N);
		iota(a.begin(), a.end(), 1);
		vector<int> ans;
		while (!a.empty()) {
			ans.push_back(a.front());
			a.pop_front();
			if (!a.empty()) {
				ans.push_back(a.back());
				a.pop_back();
			}
		}
		for (int i = 0; i < N; ++i) {
			cout << ans[i] << (i == N - 1 ? '\n' : ' ');
		}
	}();
}
