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
		string s; cin >> s;
		int N = s.size();
		for (int i = 1; i < N; ++i) {
			if (s[i] == s[i-1]) {
				cout << s.substr(i-1, 2) << '\n';
				return;
			}
			else if (i >= 2 && s[i] != s[i-1] && s[i-1] != s[i-2] && s[i] != s[i-2]) {
				cout << s.substr(i-2, 3) << '\n';
				return;
			}
		}
		cout << -1 << '\n';
	}();
}
