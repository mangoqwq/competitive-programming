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
	for (int a = 1; a <= 100; ++a) {
		vector<int> digits(210);
		for (char c : to_string(a)) digits.push_back(c - '0');
		ranges::reverse(digits);
		for (int b = 1; b <= 100; ++b) {
			ans = max(ans, accumulate(digits.begin(), digits.end(), 0));
			for (int &x : digits) x *= a;
			for (int i = 0; i < (int)digits.size() - 1; ++i) {
				digits[i+1] += digits[i] / 10;
				digits[i] %= 10;
			}
		}
	}
	cout << ans << '\n';
}
