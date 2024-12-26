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
		int N; cin >> N;
		for (int i = 0; i < N; ++i) {
			cout << 2*i + 1 << (i == N-1 ? '\n' : ' ');
		}		
	}();
}
