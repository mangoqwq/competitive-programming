#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

// f(x) denote minimum answer if we pick x discs
// convex program:
// min f(x)
// s.t. x - k = 0

// solution 1:
// dual:
// max_{lambda} min_{x} h(lambda) := f(x) - lambda * (x - k)
// equivalently h(lambda) = (f(x) - lambda x) + lambda k
// h(lambda) is concave, so binary search on its derivative

// solution 2:
// legendre fenchel conjucate is h(lambda) := f(x) - lambda * (x-k)
// let G be the epigraph of the piecewise extension of f(x), which is convex
// lambda * (x-k) is a supporting hyperplane of G at some x.
// the greater lambda is, the greater x is
// binary search on lambda, find a supporting hyperplane f(x) >= lambda_opt * (x-k) + h(lambda_opt)
// answer h(lambda_opt)

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K; cin >> N >> K;
	vector<ll> a(N), b(N);
	for (int i = 0; i < N; ++i) {
		cin >> a[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> b[i];
	}

	// h(lambda) returns (x_opt, f(x_opt) - lambda * (x_opt - k))
	auto h = [&](ll lambda) -> pair<int, ll> {
		int x = 0;
		ll hx = lambda * K;
		priority_queue<ll, vector<ll>, greater<ll>> pq_a;
		priority_queue<ll> pq_b;
		for (int i = 0; i < N; ++i) {
			pq_a.push(a[i]);
			ll match = pq_a.top() + b[i] - lambda;
			ll replace = (pq_b.empty() ? 0 : b[i] - pq_b.top());
			if (match >= 0 && replace >= 0) continue;
			if (replace <= match) {
				pq_b.pop();
				pq_b.push(b[i]);
				hx += replace;
			}
			else {
				pq_a.pop();
				pq_b.push(b[i]);
				hx += match;
				x++;
			}
		}
		return {x, hx};
	};

	ll lo = 0, hi = 2e9;
	while (lo < hi) {
		ll mi = (lo + hi + 1) >> 1;
		auto [x_opt, hx_opt] = h(mi);
		if (x_opt <= K) lo = mi;
		else hi = mi-1;
	}
	auto [x_opt, hx_opt] = h(lo);
	cout << hx_opt << '\n';
}
