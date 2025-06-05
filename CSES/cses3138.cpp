#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
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
const int mod = 1e9 + 7;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	string s; cin >> s;
	int N = (int)s.size();
	Hash<mod> hs(s, base);
	string t = s;
	ranges::reverse(t);
	Hash<mod> ht(t, base);
	auto palindrome = [&](int l, int r) {
		return hs.get(l, r) == ht.get(N - r, N - l);
	};
	vector<int> ans(N);
	for (int i = 0; i < N; ++i) {
		int lo = 1, hi = min(i + 1, N - i);
		while (lo < hi) {
			int mi = (lo + hi + 1) >> 1;
			if (palindrome(i - mi + 1, i + mi)) lo = mi;
			else hi = mi - 1;
		}
		ans[i + lo - 1] = max(ans[i + lo - 1], 2 * lo - 1);
	}
	for (int i = 1; i < N; ++i) {
		int lo = 0, hi = min(i, N - i);
		while (lo < hi) {
			int mi = (lo + hi + 1) >> 1;
			if (palindrome(i - mi, i + mi)) lo = mi;
			else hi = mi - 1;
		}
		ans[i + lo - 1] = max(ans[i + lo - 1], 2 * lo);
	}
	for (int i = N - 2; i >= 0; --i) {
		ans[i] = max(ans[i], ans[i + 1] - 2);
	}
	for (int i = 0; i < N; ++i) {
		cout << ans[i] << (i == N - 1 ? '\n' : ' ');
	}
}
