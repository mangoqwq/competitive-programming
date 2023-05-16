#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

template <int mod>
struct Hash {
	vector<ll> p, h;
	Hash(string s, int base) {
		int N = s.size();
		p.resize(N + 1);
		h.resize(N + 1);
		p[0] = 1;
		for (int i = 1; i <= N; ++i) {
			p[i] = p[i - 1] * base % mod;
			h[i] = (h[i - 1] * base + s[i - 1]) % mod;
		}
	}
	// [l, r)
	ll get(int l, int r) {
		ll val = h[r] - h[l] * p[r - l];
		return ((val % mod) + mod) % mod;
	}
};
const int mod = 1e9 + 7;
const int seed = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count() % mod;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		int N; cin >> N;
		string s; cin >> s;		
		Hash<mod> forwards(s, seed);
		reverse(s.begin(), s.end());
		Hash<mod> backwards(s, seed);
		reverse(s.begin(), s.end());

		auto is_palindrome = [&](int l, int r) -> bool {
			return forwards.get(l, r) == backwards.get(N-r, N-l);
		};

		vector<int> len(N);
		for (int i = 0; i < N-1; ++i) {
			int lo = 0, hi = min(i+1, N-i-1);
			while (lo < hi) { 
				int mi = (lo + hi + 1) >> 1;
				int l = i-(mi-1);
				int r = i+mi+1;
				if (is_palindrome(l, r)) {
					lo = mi;
				}
				else hi = mi - 1;
			}
			len[i] = lo;
		}

		vector<ll> dp(N);
		set<int> in;
		vector<vector<int>> rem(N);
		for (int i = 0; i < N; ++i) {
			if (!in.empty()) {
				int j = *prev(in.end());
				int l = j - (i-j);
				if (l == -1) dp[i] = 1;
				else dp[i] = 1 + dp[l];
			}
			if (len[i]) {
				in.insert(i);
				rem[i + len[i]].push_back(i);
			}
			for (int j : rem[i]) {
				in.erase(j);
			}
		}
		ll ans = accumulate(dp.begin(), dp.end(), 0LL);
		cout << ans << '\n';
	}();
}


