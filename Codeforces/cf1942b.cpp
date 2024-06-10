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
		int mex = 0;
		for (int i = 0; i < N; ++i) {
			int a; cin >> a;
			if (a >= 1) {
				cout << mex;
				mex += a;
			}
			else {
				cout << mex - a;
			}
			cout << (i == N-1 ? '\n' : ' ');
		}		
	}();
}
