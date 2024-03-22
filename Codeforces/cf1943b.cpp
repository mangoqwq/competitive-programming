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
const int base = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count();
const int base2 = chrono::duration_cast<chrono::nanoseconds>(chrono::steady_clock::now().time_since_epoch()).count();
const int mod = 1e9+7;
const int mod2 = 998244353;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&](){
		int N, Q; cin >> N >> Q;
		string s; cin >> s;
		vector<vector<int>> psa(N+1, vector<int>(26));
		vector<int> alt(N+1);
		for (int i = 1; i <= N; ++i) {
			psa[i] = psa[i-1];
			psa[i][s[i-1] - 'a']++;
			alt[i] = alt[i-1];
			if (s[i-1] != s[i]) alt[i]++;
		}
		Hash<mod> h1(s, base);
		Hash<mod2> h2(s, base2);
		reverse(s.begin(), s.end());
		Hash<mod> r1(s, base);
		Hash<mod2> r2(s, base2);

		auto palindrome = [&](int l, int r) -> bool {
			if (h1.get(l, r) != r1.get(N-r, N-l)) return 0;
			if (h2.get(l, r) != r2.get(N-r, N-l)) return 0;
			return 1;
		};
		auto same = [&](int l, int r) -> bool {
			for (int i = 0; i < 26; ++i) {
				if (psa[r][i] - psa[l][i] == r - l) return 1;
			}
			return 0;
		};
		auto alternating = [&](int l, int r) -> bool {
			int cnt = 0;
			for (int i = 0; i < 26; ++i) {
				if (psa[r][i] - psa[l][i]) cnt++;
			}
			if (cnt != 2) return 0;
			return (alt[r-1] -  alt[l]) == r-1 - l;
		};

		while (Q--) {
			int l, r; cin >> l >> r; l--;
			ll len = r - l;
			if (len == 1) {
				cout << 0 << '\n';
				continue;
			}
			ll ans = 0;
			debug(same(l, r), palindrome(l, r));
			if (same(l, r)) ans = 0;
			else {
				if (!palindrome(l, r)) ans += len;
				if (alternating(l, r)) {
					len--;
					ans += ((len/2) * (len/2 + 1) / 2) * 2;
				}
				else {
					ans += (len-1) * (len) / 2 - 1;
				}
			}
			cout << ans << '\n';
		}
	}();
}
