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
	string s; cin >> s;
	int goods = 0, score = 0, ans = 1;
	for (int i = 0; i < N; ++i) {
		if (i > 0 && s[i] == 'P' && s[i-1] == 'P') ans = 0;
		goods += s[i] != 'F';
		if (goods > K) ans = 0;
		if (i >= K) goods -= s[i-K] != 'F';
		if (s[i] == 'P') score += 2;
		else if (s[i] == 'S') score += 1;
	}
	if (ans) cout << "YES" << '\n' << score << '\n';
	else cout << "NO" << '\n';
}
