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
	string A, B; cin >> A >> B;
	for (char &c : A) c -= '0';
	for (char &c : B) c -= '0';
	ll ans = 0;
	for (char a : A) for (char b : B) {
		ans += a * b;
	}
	cout << ans << '\n';
}
