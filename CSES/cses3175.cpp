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
	if (N == 1) {
		cout << 1 << '\n';
		return 0;
	}
	if (N < 4) {
		cout << "NO SOLUTION" << '\n';
		return 0;
	}
	vector<int> ans;
	int b = 0;
	while (N > 8) {
		ans.push_back(b + 1);
		ans.push_back(b + 3);
		ans.push_back(b + 5);
		ans.push_back(b + 2);
		ans.push_back(b + 4);
		b += 5;
		N -= 5;
	}
	map<int, vector<int>> sols {
		{4, {2, 4, 1, 3}},
		{5, {1, 3, 5, 2, 4}},
		{6, {1, 3, 5, 2, 4, 6}},
		{7, {1, 3, 5, 2, 6, 4, 7}},
		{8, {1, 3, 5, 2, 6, 8, 4, 7}},
	};
	for (int x : sols[N]) {
		ans.push_back(b + x);
	}
	N = ans.size();
	for (int i = 0; i < N; ++i) {
		cout << ans[i] << (i == N - 1 ? '\n' : ' ');
	}
}
