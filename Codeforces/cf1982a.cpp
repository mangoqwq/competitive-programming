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
		int a, b, c, d; cin >> a >> b >> c >> d;
		cout << ((a < b) != (c < d) ? "NO" : "YES") << '\n';		
	}();
}
