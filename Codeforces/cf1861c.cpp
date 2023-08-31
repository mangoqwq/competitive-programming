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
		bool ans = [&]() -> bool {
			vector<int> ans;
			map<int, int> cnt;
			auto add = [&](int x) {
				ans.push_back(x);
				cnt[x]++;
			};
			auto rem = [&]() {
				cnt[ans.back()]--;
				ans.pop_back();
			};
			auto mod = [&](int i, int x) {
				cnt[ans[i]]--;
				ans[i] = x;
				cnt[x]++;
			};
			for (char c : s) {
				if (c == '+') add(0);
				if (c == '-') rem();
				if (c == '1') {
					if (cnt[-1]) return 0;
					for (int i = ans.size()-1; i >= 1; --i) {
						if (ans[i] == 1) break;
						ans[i] = 1;
					}
				}
				if (c == '0') {
					if (ans.size() < 2 || ans.back() == 1) return 0;
					mod(ans.size()-1, -1);
				}
				debug(ans);
			}
			return 1;
		}();
		cout << (ans ? "YES" : "NO") << '\n';
	}();
}
