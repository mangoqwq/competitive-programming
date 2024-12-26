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
	set<int> m30s = {9, 4, 6, 11};
	int date = 1;
	for (int y = 1901; y <= 2000; ++y) {
		for (int m = 1; m <= 12; ++m) {
			if (date == 6) {
				ans++;
			}
			if (m == 2) {
				if (y % 400 == 0) date++;
				else if (y % 4 == 0 && y % 100 != 0) date++;
				date += 28;
			}
			else if (m30s.contains(m)) date += 30;
			else date += 31;
			date %= 7;
		}
	}
	cout << ans << '\n';
}
