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
	int N; cin >> N;
	auto ask = [&](int i) -> int {
		cout << "? " << i + 1 << '\n';
		cout.flush();
		char c; cin >> c;
		return (c == 'R') ^ (i & 1);
	};

	int a = ask(0);
	int b = ask(N - 1);
	if (a == b) {
		cout << "! " << N << '\n';
		return 0;
	}
	int lo = 0, hi = N - 1;
	while (lo + 1 < hi) {
		int mi = (lo + hi) >> 1;
		int c = ask(mi);
		if (c == a) lo = mi;
		else hi = mi;
	}
	cout << "! " << lo + 1 << '\n';
}
