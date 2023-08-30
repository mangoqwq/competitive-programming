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
		int N, K; cin >> N >> K;
		int tot = 0;
		for (int i = 0; i <= N; ++i) tot ^= i;
		vector<int> a(N);
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
			tot ^= a[i];
		}
		a.push_back(tot);
		int start = N+1 - (K % (N+1));
		debug(a, start);
		for (int i = 0; i < N; ++i) {
			cout << a[(start+i) % (N+1)] << (i == N-1 ? '\n' : ' ');
		}
	}();
}
