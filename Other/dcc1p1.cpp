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
	ll N; cin >> N;
	ll a, b; cin >> a >> b;
	if (a <= b && (b - a) % 2 == 0) cout << "YES" << '\n';
	else cout << "NO" << '\n';
}
