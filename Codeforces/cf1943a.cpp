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
			int x; cin >> x;
			a[x]++;
		}
		vector<int> cnt(N + 5);
		for (int i = 0; i < N; ++i) {
			cnt[a[i]]++;
			if (cnt[0] || cnt[1] >= 2) {
				cout << i << '\n';
				return;
			}
		}
		cout << N << '\n';
	}();
}
