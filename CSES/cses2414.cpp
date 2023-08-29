#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

/*
sort B first, so B = b0, b1, b2, ...
let a0 ... a_{n-1} be A in order

we try possibilities for a0
start with A0 = {a0}, B0 = B
we know smallest of B0 would be a0 + a1, so we can find a1
write A1 = {a0, a1}, B1 = B - pairwise sums(A1)

now smallest of B1 is a0 + a2, so we can find a2
write A2 = {a0, a1, a2} = B - pairwise sums (A2)

repeat this process until pairwise sums not subset of B, or we find all of A

so given a0 we can check if it works in around quadratic time
now what values of a0 can we test?
we know a0 + b1 = b0 and a0 + b2 = b1
then what is b1 + b2? it must be within the first 2N elements of B,
so we just try a1 + a2 = bi for each 2 <= i < min(2N, M)
then		2a0 + a1 + a2 = b0 + b1
		==> 2a0 = b0 + b1 - bi
*/

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	int M = N * (N-1) / 2;
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	sort(B.begin(), B.end());

	auto attempt = [&](int a0) -> pair<bool, vector<int>> {
		vector<int> ans = {a0};
		map<int, int> mp;
		for (int x : B) mp[x]++;
		for (int i = 1; i < N; ++i) {
			int ai = mp.begin()->first - a0;
			for (int aj : ans) {
				if (!mp.count(ai + aj)) return {0, {}};
				mp[ai+aj]--;
				if (mp[ai+aj] == 0) mp.erase(ai+aj);
			}
			ans.push_back(ai);
		}
		return {1, ans};
	};

	for (int i = 2; i < min(2*N, M); ++i) {
		int cur = B[0] + B[1] - B[i];
		if (cur % 2 == 1) continue;
		auto [ok, ans] = attempt(cur / 2);
		if (ok) {
			for (int i = 0; i < N; ++i) {
				cout << ans[i] << (i == N-1 ? '\n' : ' ');
			}
			break;
		}
	}
}
