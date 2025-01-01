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
	int N = 1e6;
	string s;
	int t = 1;
	while ((int)s.size() < N) {
		s += to_string(t++);
	}
	int ans = 1;
	for (int i = N; i >= 1; i /= 10) {
		ans *= s[i-1] - '0';
	}
	cout << ans << '\n';
}
