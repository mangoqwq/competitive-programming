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
	vector<int> basis(30);
	for (int i = 0; i < N; ++i) {
		int x; cin >> x;
		for (int b = 29; b >= 0; --b) {
			if (1 & (x >> b)) x ^= basis[b];
		}
		if (x && !basis[__lg(x)]) basis[__lg(x)] = x;
	}
	int dim = ranges::count_if(basis, [&](int x) { return x != 0; });
	cout << (1 << dim) << '\n';
}
