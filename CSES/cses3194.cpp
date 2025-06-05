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
	const int L = 30;
	for (int i = 0; i < L; ++i) {
		for (int x = 0; x < N; ++x) {
			if (x & (1 << i)) a[x] ^= a[x ^ (1 << i)];
		}
	}
	for (int i = 0; i < N; ++i) {
		cout << a[i] << (i == N - 1 ? '\n' : ' ');
	}
}
