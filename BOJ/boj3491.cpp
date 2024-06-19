#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

struct DisjointSet {
	vector<int> p, sz;
	DisjointSet(int N) {
		p.resize(N);
		iota(p.begin(), p.end(), 0);
		sz.resize(N, 1);
	}
	int root(int x) { return p[x] == x ? x : p[x] = root(p[x]); }
	bool unite(int a, int b) {
		a = root(a), b = root(b);
		if (a == b) return 0;
		if (sz[b] > sz[a]) swap(a, b);
		p[b] = a;
		sz[a] += sz[b];
		return 1;
	}
};

ll euclid(ll a, ll b, ll &x, ll &y) {
	if (!b) return x = 1, y = 0, a;
	ll d = euclid(b, a % b, y, x);
	return y -= a/b * x, d;
}

ll crt(ll a, ll m, ll b, ll n) {
	if (n > m) swap(a, b), swap(m, n);
	ll x, y, g = euclid(m, n, x, y);
	assert((a - b) % g == 0);
	x = (b - a) % n * x % n / g * m + a;
	return x < 0 ? x + m*n/g : x;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int T; cin >> T;
	while (T--) [&]() {
		ll F, N, A, B; cin >> F >> N >> A >> B;
		vector<ll> X(N), Y(N);
		for (int i = 0; i < N; ++i) {
			cin >> X[i] >> Y[i];
		}
		DisjointSet dsu(N+2);
		if (A == B) dsu.unite(N, N+1);
		for (int i = 0; i < N; ++i) {
			for (int j = i+1; j < N; ++j) {
				if (dsu.root(i) == dsu.root(j)) continue;
				ll g = __gcd(X[i], X[j]);
				if (Y[i] % g != Y[j] % g) continue;
				ll x = crt(Y[i] % X[i], X[i], Y[j] % X[j], X[j]);
				ll l = X[i] * X[j] / g;
				ll meet = (F / l * l + l);
				meet += x;
				while (meet >= F) meet -= l;
				ll base = max(Y[i], Y[j]);
				if (meet >= base) {
					dsu.unite(i, j);
				}
			}
			if ((A - Y[i]) % X[i] == 0 && A >= Y[i]) dsu.unite(N, i);
			if ((B - Y[i]) % X[i] == 0 && B >= Y[i]) dsu.unite(N+1, i);
			if (dsu.root(N) == dsu.root(N+1)) {
				cout << "It is possible to move the furniture." << '\n';
				return;
			}
		}
		cout << "The furniture cannot be moved." << '\n';
	}();
}
