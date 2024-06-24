#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

struct Line {
	mutable double k, m, p;
	mutable int val;
	bool operator<(const Line& o) const { return k < o.k; }
	bool operator<(double x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
	// (for doubles, use inf = 1/.0, div(a,b) = a/b)
	double inf = 1/.0;
	double div(double a, double b) { // floored division
		return a/b; }
	bool isect(iterator x, iterator y) {
		if (y == end()) return x->p = inf, 0;
		if (x->k == y->k) x->p = x->m > y->m ? inf : -inf;
		else x->p = div(y->m - x->m, x->k - y->k);
		return x->p >= y->p;
	}
	void add(double k, double m, int val) {
		auto z = insert({k, m, 0, val}), y = z++, x = y;
		while (isect(y, z)) z = erase(z);
		if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
		while ((y = x) != begin() && (--x)->p >= y->p)
			isect(x, erase(y));
	}
	pair<double, int> query(double x) {
		assert(!empty());
		auto l = *lower_bound(x);
		return {l.k * x + l.m, l.val};
	}
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, K; cin >> N >> K;

	auto h = [&](double lambda) -> pair<int, double> {
		LineContainer hull;
		vector<double> dp(N+1);
		vector<int> val(N+1);
		hull.add(0, 0, 0);
		dp[0] = 0;
		for (int i = 1; i <= N; ++i) {
			tie(dp[i], val[i]) = hull.query(1.0 / i);
			dp[i]++;
			dp[i] -= lambda;
			val[i]++;
			hull.add(-i, dp[i], val[i]);
		}
		return {val[N], -lambda * K - dp[N]};
	};

	double lo = 0, hi = 1;
	for (int its = 0; its < 50; ++its) {
		double mi = (lo + hi) / 2;
		auto [x, hx] = h(mi);
		if (x > K) lo = mi;
		else hi = mi;
	}
	cout << fixed << setprecision(14);
	auto [x, hx] = h(lo);
	cout << -hx << '\n';
}
