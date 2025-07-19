#include <algorithm>
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
	vector<vector<int>> lines = {
		{5, 0, 1},
		{6, 1, 2},
		{7, 2, 3},
		{8, 3, 4},
		{9, 4, 0},
	};
	vector<int> perm = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	ll ans = 0;
	do {
		if (min_element(perm.begin() + 5, perm.end()) != perm.begin() + 5) {
			// first external node must be smallest
			continue;
		}
		
		set<int> sums;
		string concat = "";
		for (auto line : lines) {
			int tot = 0;
			for (int idx : line) {
				tot += perm[idx];
				concat += to_string(perm[idx]);
			}
			sums.insert(tot);
		}
		if ((int)sums.size() == 1 && (int)concat.size() == 16) {
			debug(perm, concat);
			ans = max(ans, stoll(concat));
		}
	} while (next_permutation(perm.begin(), perm.end()));
	cout << ans << '\n';
}
