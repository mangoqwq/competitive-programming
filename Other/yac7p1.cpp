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
	int N; cin >> N;
	vector<ll> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	vector<int> ord(N);
	iota(ord.begin(), ord.end(), 0);
	sort(ord.begin(), ord.end(), [&](int i, int j) {
		return a[i]% 2 < a[j]%2;
	});
	ord.insert(ord.begin(), ord.back());
	ord.pop_back();
	ll ans = accumulate(a.begin(), a.end(), 0LL) / 2;
	ll cur = 0;
	for (int i = 0; i < N-1; ++i) {
		cur += a[ord[i]];
		if (cur % 2 == 1) ans--;
	}
	cout << ans << '\n';
	for (int i = 0; i < N; ++i) {
		cout << ord[i]+1 << (i == N-1 ? '\n' : ' ');
	}
}
