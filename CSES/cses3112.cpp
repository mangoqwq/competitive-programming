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
	int lo = 1, hi = 1e9;
	while (lo < hi) {
		int mi = (lo + hi) >> 1;
		cout << "? " << mi << '\n';
		cout.flush();
		string s; cin >> s;
		if (s == "YES") lo = mi + 1;
		else hi = mi;
	}
	cout << "! " << lo << '\n';
}
