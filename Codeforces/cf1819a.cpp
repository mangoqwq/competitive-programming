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
		vector<int> a(N);
		map<int, vector<int>> idxs;
		for (int i = 0; i < N; ++i) {
			cin >> a[i];
			idxs[a[i]].push_back(i);
		}
		int mex = 0;
		while (idxs.count(mex)) mex++;
		if (mex == N) cout << "No" << '\n';
		else {
			if (idxs.count(mex + 1)) {
				for (int i = idxs[mex+1].front(); i <= idxs[mex+1].back(); ++i) {
					a[i] = mex;
				}
				idxs.clear();
				for (int i = 0; i < N; ++i) {
					idxs[a[i]].push_back(i);
				}
				int nmex = 0;
				while (idxs.count(nmex)) nmex++;
				if (nmex > mex) cout << "Yes" << '\n';
				else cout << "No" << '\n';
			}
			else {
				cout << "Yes" << '\n';
			}
		}
	}();
}
