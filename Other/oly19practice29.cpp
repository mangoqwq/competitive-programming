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
	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}

	int x = 1;
	int mn = a[0];
	for (int i = 1; i < N; ++i) {
		x += mn > a[i];
		mn = min(mn, a[i]);
	}
	cout << x << '\n';
}
