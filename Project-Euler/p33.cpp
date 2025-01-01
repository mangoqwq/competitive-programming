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
	int ans_n = 1, ans_d = 1;
	auto go = [&](int n, int d, int on, int od) {
		if (od * n != on * d) return;
		ans_n *= on;
		ans_d *= od;
	};
	for (int n = 1; n < 10; ++n) {
		for (int d = n+1; d < 10; ++d) {
			for (int i = 1; i < 10; ++i) {
				go(n, d, stoi(to_string(n) + to_string(i)), stoi(to_string(d) + to_string(i)));
				go(n, d, stoi(to_string(n) + to_string(i)), stoi(to_string(i) + to_string(d)));
				go(n, d, stoi(to_string(i) + to_string(n)), stoi(to_string(i) + to_string(d)));
				go(n, d, stoi(to_string(i) + to_string(n)), stoi(to_string(d) + to_string(i)));
			}
		}
	}
	int g = gcd(ans_n, ans_d);
	ans_n /= g, ans_d /= g;
	cout << ans_d << '\n';
}
