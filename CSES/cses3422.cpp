#include <bits/stdc++.h>
#include <random>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

mt19937 gen(chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count());

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<int> a(N), b(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> b[i];
	}
	for (int it = 0; it < 1000; ++it) {
		vector<int> c(N);
		iota(c.begin(), c.end(), 1);
		ranges::shuffle(c, gen);
		bool ok = 1;
		for (int i = 0; i < N; ++i) {
			ok &= c[i] != a[i] && c[i] != b[i];
		}
		if (ok) {
			for (int i = 0; i < N; ++i) {
				cout << c[i] << (i == N - 1 ? '\n' : ' ');
			}
			return 0;
		}
	}
	cout << "IMPOSSIBLE" << '\n';
}
