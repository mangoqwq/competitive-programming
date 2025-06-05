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
	int T; cin >> T;
	while (T--) [&]() {
		int N, A, B; cin >> N >> A >> B;
		if (A + B > N || (A && !B) || (!A && B)) {
			cout << "NO" << '\n';
		}
		else {
			cout << "YES" << '\n';
			vector<int> v(N);
			iota(v.begin(), v.end(), 0);
			rotate(v.begin(), v.begin() + B, v.begin() + A + B);
			for (int i = 0; i < N; ++i) {
				cout << v[i] + 1 << (i == N-1 ? '\n' : ' ');
			}
			for (int i = 0; i < N; ++i) {
				cout << i + 1 << (i == N-1 ? '\n' : ' ');
			}
		}
	}();
}
