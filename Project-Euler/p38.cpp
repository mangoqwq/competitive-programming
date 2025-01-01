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
	int ans = 0;
	for (int n = 2; n < 10; ++n) {
		for (int p = 1; ; ++p) {
			string s;
			for (int i = 1; i <= n; ++i) s += to_string(i * p);
			if ((int)s.size() >= 10) break;
			if ((int)s.size() == 9 && s.find('0') == s.npos && s.size() == set<char>(s.begin(), s.end()).size()) {
				ans = max(ans, stoi(s));
			}
		}
	}
	cout << ans << '\n';
}
