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
		string s; cin >> s;
		map<char, int> idx;
		for (int i = 0; i < s.size(); ++i) {
			idx[s[i]] = i;
		}
		if (idx['1'] < idx['7']) {
			cout << "17" << '\n';
		}
		else cout << 71 << '\n';
	}();
}
