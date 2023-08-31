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
		string a, b; cin >> a >> b;
		int N = a.size();
		bool ok = 0;
		for (int i = 0; i < N-1; ++i) {
			if (a[i] == b[i] && a[i] == '0' && a[i+1] == b[i+1] && a[i+1] == '1') ok = 1;
		}
		cout << (ok ? "YES" : "NO") << '\n';
	}();
}
