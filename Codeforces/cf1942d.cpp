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
		int N, K; cin >> N >> K;
		vector<vector<ll>> a(N, vector<ll>(N));
		for (int i = 0; i < N; ++i) {
			for (int j = i; j < N; ++j) {
				cin >> a[i][j];
			}
		}

		vector<vector<ll>> cul(N+2);
		cul[N+1] = {0};
		cul[N+0] = {0};
		for (int i = N-1; i >= 0; --i) {
			struct Item {
				ll val, idx, j;
				bool operator<(const Item &other) const {
					return tie(val, idx, j) < tie(other.val, other.idx, other.j);
				}
			};
			priority_queue<Item> pq;
			for (int j = i; j < N; ++j) {
				pq.push({a[i][j] + cul[j+2][0], 0, j});
			}
			while (!pq.empty() && (int)cul[i].size() < K) {
				auto [val, idx, j] = pq.top(); pq.pop();
				cul[i].push_back(val);
				idx++;
				if (idx < (int)cul[j+2].size()) {
					pq.push({a[i][j] + cul[j+2][idx], idx, j});
				}
			}
			vector<ll> tmp(cul[i].size() + cul[i+1].size());
			merge(cul[i].begin(), cul[i].end(), cul[i+1].begin(), cul[i+1].end(), tmp.begin(), greater<ll>());
			swap(tmp, cul[i]);
			if ((int)cul[i].size() > K) cul[i].resize(K);
		}
		for (int i = 0; i < K; ++i) {
			cout << cul[0][i] << (i == K-1 ? '\n' : ' ');
		}
	}();
}
