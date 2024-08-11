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
	int N, K; cin >> N >> K;
	vector<int> a = {0}; K--;
	for (int l = N-1; l >= 0; --l) {
		if (K >= (1 << l)) {
			K -= 1 << l;
			for (int i = (1 << l); i < (1 << (l+1)); ++i) {
				a.push_back(i);
			}
		}
	}
	sort(a.begin(), a.end());
	cout << "YES" << '\n';
	for (int i = 0; i < (int)a.size(); ++i) {
		cout << a[i] << (i == (int)a.size() - 1 ? '\n' : ' ');
	}
}
