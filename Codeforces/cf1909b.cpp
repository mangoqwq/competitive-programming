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
	int T; cin >> T;
	while (T--) [&]() {
		int N; cin >> N;
		vector<ll> v(N);
		for (int i = 0; i < N; ++i) {
			cin >> v[i];
		}
		auto test = [&](ll x) {
			set<ll> s;
			for (ll y : v) {
				s.insert(y % x);
			}
			return s.size() == 2;
		};
		for (ll i = 2; ; i *= 2) {
			if (test(i)) {
				cout << i << '\n';
				break;
			}
		}
	}();
}
