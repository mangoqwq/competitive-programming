#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
const int seed = 1;
#else
#define debug(...)
const int seed = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count();
#endif

mt19937 gen(seed);
int randint(int l, int r) { return uniform_int_distribution<int>(l, r)(gen); }

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int K; cin >> K;
		int N = (1 << (K+1));
		vector<ll> a(N+1);
		for (int i = 1; i <= N; ++i) {
			cin >> a[i];
			a[i] ^= a[i-1];
		}

		auto get = [&](int l, int r) {
			return a[r] ^ a[l-1];
		};

		bool found = 0;
		int l1, r1, l2, r2;
		for (int it = 0; it < 10000 && !found; ++it) {
			auto attempt = [&](int l, int r) {
				unordered_map<ll, vector<int>> seen;
				seen[0].push_back(0);
				ll want = get(l, r);
				for (int i = 1; i <= N; ++i) {
					ll cur = a[i];
					ll need = cur ^ want;
					if (i != r && seen.count(need)) {
						for (int _j : seen[need]) {
							int j = _j+1;
							if (j != l) {
								if (j >= l && i <= r) {
									debug(1);
									tie(l1, r1) = make_pair(l, j-1);
									tie(l2, r2) = make_pair(i+1, r);
								}
								else if (l >= j && r <= i) {
									debug(2);
									tie(l1, r1) = make_pair(j, l-1);
									tie(l2, r2) = make_pair(r+1, i);
								}
								else if (j > r || i < l) {
									debug(3);
									tie(l1, r1) = tie(j, i);
									tie(l2, r2) = tie(l, r);
								}
								else {
									debug(4);
									l1 = min(l, j);
									r1 = max(l, j)-1;
									l2 = min(r, i)+1;
									r2 = max(r, i);
								}
								found = 1;
								return;
							}
						}
					}
					seen[cur].push_back(i);
				}
				// for (auto [a, b] : seen) {
				// 	debug(a, b);
				// }
			};
			int l = randint(1, N);
			int r = randint(1, N);
			if (l > r) swap(l, r);
			attempt(l, r);
			if (found) break;
		}

		debug(found);
		debug(l1, r1, l2, r2);
		debug(get(l1, r1), get(l2, r2));
		assert(found);
		assert(get(l1, r1) == get(l2, r2));
		cout << l1 << " " << r1 << " " << l2 << " " << r2 << '\n';

	}();
}
