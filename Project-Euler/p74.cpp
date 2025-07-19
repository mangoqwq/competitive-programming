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
	const int MN = 1e6;
	auto fact = [&](int x) {
		int ret = 1;
		for (int i = 2; i <= x; ++i) ret *= i;
		return ret;
	};
	auto chain = [&](int n) {
		set<int> vis = {n};
		while (true) {
			int nxt = 0;
			for (char c : to_string(n)) {
				nxt += fact(c - '0');
			}
			if (vis.count(nxt)) return vis.size();
			vis.insert(nxt);
			n = nxt;
		}
	};
	int ans = 0;
	for (int i = 1; i < MN; ++i) {
		if (chain(i) == 60) ans++;
	}
	cout << ans << '\n';
}
