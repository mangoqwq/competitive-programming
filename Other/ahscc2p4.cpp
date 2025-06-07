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
	int N, M; cin >> N >> M;
	if (N + M > N * 2 + 1) {
		cout << -1 << '\n';
		return 0;
	}
	if (N + M <= 3) {
		if (N == 1 && M == 2) {
			cout << 2 << " " << 3 << '\n';
		}
		else {
			cout << -1 << '\n';
		}
		return 0;
	}
	auto pick = [&](int x) -> pair<int, int> {
		vector<int> v;
		for (int i = 2; i <= N+M; ++i) {
			if (i != x) v.push_back(i);
			if ((int)v.size() >= 2) break;
		}
		return {v[0], v[1]};
	};
	for (int i = 1; i <= N; ++i) {
		if (i*2 > N+M) {
			auto [a, b] = pick(i);
			cout << a << " " << b << '\n';
		}
		else if (i*2+1 > N+M) {
			auto [a, _] = pick(i);
			cout << a << " " << i*2 << '\n';
		}
		else {
			cout << i*2 << " " << i*2+1 << '\n';
		}
	}
}
