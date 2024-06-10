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
		for (int i = 0; i < N; ++i) cin >> a[i];
		if (a[0] == a.back()) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
			for (int i = 0; i < N; ++i) {
				cout << (i == 1 ? 'B' : 'R');
			}
			cout << '\n';
		}
	}();
}
