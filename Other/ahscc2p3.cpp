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
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	auto ok = [&](int a, int b, int c) {
		return ((b > a) && (b > c)) || ((b < a) && (b < c));
	};
	vector<int> pre(N), suf(N);
	pre[0] = a[0] != a[1];
	for (int i = 1; i < N-1; ++i) {
		pre[i] = pre[i-1] & ok(a[i-1], a[i], a[i+1]);
	}
	suf[N-1] = a[N-1] != a[N-2];
	for (int i = N-2; i > 0; --i) {
		suf[i] = suf[i+1] & ok(a[i-1], a[i], a[i+1]);
	}
	bool win0 = pre[N-2];
	bool win1 = 0;
	auto test = [&](int i, int del) {
		bool ok_l = i <= 1 || ok(a[i-2], a[i-1], a[i]+del);
		bool ok_m = i == 0 || i == N-1 || ok(a[i-1], a[i]+del, a[i+1]);
		bool ok_r = i >= N-2 || ok(a[i]+del, a[i+1], a[i+2]);
		bool ok_pre = i <= 1 || pre[i-2];
		bool ok_suf = i >= N-2 || suf[i+2];
		if (ok_l && ok_m && ok_r && ok_pre && ok_suf) win1 = 1;
	};
	for (int i = 0; i < N; ++i) {
		test(i, 1);
		test(i, -1);
	}
	if (win0) cout << 0 << '\n';
	else if (win1) cout << 1 << '\n';
	else cout << -1 << '\n';
}
