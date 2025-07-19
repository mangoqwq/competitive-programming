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
	const int MN = 1e6;
	vector<int> phi(MN + 1, 1);
	int best = 1;
	for (int i = 2; i <= MN; ++i) {
		if (phi[i] == 1) {
			for (int j = i; j <= MN; j += i) {
				int x = 1;
				while (j % (1LL * x * i) == 0) x *= i;
				phi[j] *= x - x / i;
			}
		}
		if (1LL * i * phi[best] > 1LL * best * phi[i]) {
			best = i;
		}
	}
	cout << best << '\n';
}
