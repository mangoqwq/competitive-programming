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
	ll N = 100;
	ll sum2 = N * (N + 1) * (2 * N + 1) / 6;
	ll sum3 = N * N * (N + 1) * (N + 1) / 4;
	cout << sum3 - sum2 << '\n';
}
