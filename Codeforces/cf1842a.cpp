#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int N, M; cin >> N >> M;
		priority_queue<int> a, b;
		for (int i = 0; i < N; ++i) {
			int x; cin >> x;
			a.push(x);
		}
		for (int i = 0; i < M; ++i) {
			int x; cin >> x;
			b.push(x);
		}

		while (!a.empty() && !b.empty()) {
			int ma = a.top(), mb = b.top();
			a.pop(), b.pop();
			ll nma = ma - mb, nmb = mb - ma;
			if (nma > 0) a.push(nma);
			if (nmb > 0) b.push(nmb);
		}
		if (a.empty() && b.empty()) {
			cout << "Draw" << '\n';
		}
		else if (a.empty()) {
			cout << "Tenzing" << '\n';
		}
		else if (b.empty()) {
			cout << "Tsondu" << '\n';
		}
	}();
}
