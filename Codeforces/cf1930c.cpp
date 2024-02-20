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
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
			a[i] += i + 1;
		}
		sort(a.begin(), a.end(), greater<int>());
		vector<int> ans = {a[0]};
		for (int i = 1; i < N; ++i) {
			if (a[i] >= ans.back()) {
				ans.push_back(ans.back()-1);
			}
			else ans.push_back(a[i]);
		}
		for (int i = 0; i < N; ++i) {
			cout << ans[i] << (i == N-1 ? '\n' : ' ');
		}
	}();
}
