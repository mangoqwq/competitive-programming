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
		vector<int> a(N), b(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
		}		
		for (int i = 0; i < N; ++i) {
			cin >> b[i];
		}

		bool eq = [&]() -> bool {
			if (a == b) return 1;
			reverse(a.begin(), a.end());
			if (a == b) return 1;
			return 0;
		}();

		if (eq) {
			cout << "Bob" << '\n';
		}
		else {
			cout << "Alice" << '\n';
		}
	}();
}
