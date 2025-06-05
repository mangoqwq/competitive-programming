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
	int N; cin >> N;
	for (int l = 0; l < 10; ++l) {
		cout << "? ";
		for (int i = 0; i < N; ++i) {
			cout << (1 & (i >> l));
		}
		cout << '\n';
	}
	cout.flush();
	vector<int> ans(N);
	for (int l = 0; l < 10; ++l) {
		string s; cin >> s;
		for (int i = 0; i < N; ++i) {
			if (s[i] == '1') ans[i] += 1 << l;
		}
	}
	cout << "! ";
	for (int i = 0; i < N; ++i) {
		cout << ans[i] + 1 << (i == N - 1 ? '\n' : ' ');
	}
}
