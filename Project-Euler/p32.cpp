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
	set<int> prods;
	for (int i = 1; i <= 10000; ++i) {
		for (int j = i; j <= 10000; ++j) {
			int p = i * j;
			string s = to_string(i) + to_string(j) + to_string(p);
			if (s.find('0') == s.npos && s.size() == 9 && s.size() == set<char>(s.begin(), s.end()).size()) {
				prods.insert(p);
			}
		}
	}
	debug(prods);
	ll ans = accumulate(prods.begin(), prods.end(), 0LL);
	cout << ans << '\n';
}
