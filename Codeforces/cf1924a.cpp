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
		int N, K, M; cin >> N >> K >> M;
		string s; cin >> s;
		set<int> see;
		string ans = "";
		for (int i = 0; i < s.size(); ++i) {
			see.insert(s[i]);
			if (see.size() == K) {
				ans.push_back(s[i]);
				see.clear();
			}
		}
		for (int i = 'a'; i < 'a' + K; ++i) {
			if (!see.count(i)) {
				ans.push_back(i);
				break;
			}
		}
		while (ans.size() < N) ans.push_back('a');
		if (ans.size() == N) {
			cout << "NO" << '\n';
			cout << ans << '\n';
		}
		else {
			cout << "YES" << '\n';
		}
	}();
}
