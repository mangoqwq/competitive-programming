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
		set<int> s;
		for (int i = 1; i <= N; ++i) {
			if (N % i == 0) s.insert(i);
		}

		int mex = 1;
		for (;;++mex) {
			if (!s.count(mex)) break;
		}

		for (int i = 0; i < N; ++i) {
			cout << (char)('a' + (i % mex));
		}
		cout << '\n';
	}();
}
