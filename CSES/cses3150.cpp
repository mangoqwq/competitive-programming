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
	vector<int> nxt(N, N);
	unordered_map<int, int> lst;
	for (int i = 0; i < N; ++i) {
		int x; cin >> x;
		if (lst.contains(x)) nxt[lst[x]] = i;
		lst[x] = i;
	}
	ll ans = 0;
	for (int i = 0; i < N; ++i) {
		ans += 1LL * (nxt[i] - i) * (i + 1);
	}
	cout << ans << '\n';
}
