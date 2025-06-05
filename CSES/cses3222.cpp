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
	vector<int> vec(N);
	for (int i = 0; i < N; ++i) {
		cin >> vec[i];
	}
	map<int, int> mp;
	for (int i = 0; i < K; ++i) {
		mp[vec[i]]++;
	}
	vector<ll> ans(N - K + 1);
	ans[0] = mp.size();
	for (int i = 0; i < N - K; ++i) {
		mp[vec[i + K]]++;
		mp[vec[i]]--;
		if (mp[vec[i]] == 0) mp.erase(vec[i]);
		ans[i + 1] = mp.size();
	}
	for (int i = 0; i <= N - K; ++i) {
		cout << ans[i] << (i == N - K ? '\n' : ' ');
	}
}
