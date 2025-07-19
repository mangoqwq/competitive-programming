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
	const int N = 1e6;
	for (int n = 1; n <= N; ++n) {
		set<multiset<char>> uniq;
		for (int k = 1; k <= 6; ++k) {
			string num = to_string(k * n);
			uniq.emplace(num.begin(), num.end());
		}
		if ((int)uniq.size() == 1) {
			cout << n << '\n';
			break;
		}
	}
}
