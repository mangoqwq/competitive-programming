#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

vector<string> singles = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> teens = {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen",  "sixteen", "seventeen", "eighteen", "nineteen"};
vector<string> tys = {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	// 0 < n < 100
	auto count = [&](int n) -> int {
		if (n <= 9) return singles[n].length();
		else if (n < 20) return teens[n - 10].length();
		else if (n % 10) return (tys[n / 10] + singles[n % 10]).length();
		else return tys[n / 10].length();
	};
	int ans = 0;
	for (int i = 1; i <= 9; ++i) {
		ans += (singles[i] + "hundredand").length() * 99;
		ans += (singles[i] + "hundred").length();
	}
	for (int i = 1; i <= 99; ++i) {
		ans += count(i) * 10;
	}
	ans += 11; // one thousand
	cout << ans << '\n';
}
