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
		string s; cin >> s;
		int ans = 0;
		for (char c : s) {
			if (c == '-') ans--;
			else ans++;
		}
		cout << abs(ans) << '\n';
	}();
}
