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
const int mod2 = 1e9+7;


int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		string s; cin >> s;
		int N = (int)s.size();
		vector<int> nona;
		for (int i = 0; i < N; ++i) {
			if (s[i] != 'a') nona.push_back(i);
		}
		if (nona.empty()) {
			cout << N-1 << '\n';
			return;
		}
		Hash<mod> h(s, base);
		Hash<mod2> h2(s, base2);
		ll ans = 0;
		for (int len = 1; len <= N; ++len) {
			int l = nona[0];
			int r = l + len;
			if (r > N) continue;
			int expand = l;
			int pl = l, pr = r;
			bool good = 1;
			while (!(nona.back() < pr)) {
				int npl = *lower_bound(nona.begin(), nona.end(), pr);
				expand = min(expand, npl - pr);
				pl = npl;
				pr = pl + len;
				if (pr > N || h.get(pl, pr) != h.get(l, r) || h2.get(pl, pr) != h2.get(l, r)) {
					good = 0;
					break;
				}
			}
			// debug(l, r, good, expand+1);
			if (good) ans += expand + 1;
		}
		cout << ans << '\n';
	}();
}
