#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

int main(){
	cin.tie(0)->sync_with_stdio(0);
	int N, Q; cin >> N >> Q;
	vector<int> a(N);
	for (int i = 0; i < N; ++i){
		cin >> a[i];
	}
	const int L = 20;
	vector<vector<int>> st(L, vector<int>(N+1));
	a.push_back(2e9);
	for (int i = N-1; i >= 0; --i){
		if (a[i] < a[i+1]) st[0][i] = i+1;
		else if (a[i+1] < a[i+2]) st[0][i] = i+1;
		else st[0][i] = st[0][i+1];
	}

	for (int l = 1; l < L; ++l){
		st[l-1][N] = N;
		for (int i = 0; i < N; ++i){
			st[l][i] = st[l-1][st[l-1][i]];
		}
	}

	for (int q = 0; q < Q; ++q){
		int l, r; cin >> l >> r; l--; r--;
		int ans = 1;
		int i = l;
		for (int b = L-1; b >= 0; --b){
			if (st[b][i] <= r){
				ans += (1 << b);
				i = st[b][i];
			}
		}
		if (i != r) ans++;
		cout << ans << '\n';
	}
}
