#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

struct Function {
	ll m, b;
	double sect(Function o) {
		if (m == o.m) {
			if (b < o.b) return -1e300; // this dominates o always
			else return 1e300; // this never dominates o
		}
		return (double)(b - o.b) / (o.m - m);
	}
	ll eval(ll x) { return m*x + b; }
};

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	vector<ll> d(N);
	vector<ll> w(N);
	for (int i = 0; i < N; ++i) {
		cin >> w[i] >> d[i];
	}
	d.push_back(0);
	w.push_back(0);
	reverse(d.begin(), d.end());
	reverse(w.begin(), w.end());
	auto partials = [&](const vector<ll> &arr) -> vector<ll> {
		vector<ll> psa = arr;
		for (int i = 1; i < arr.size(); ++i) psa[i] += psa[i-1];
		return psa;
	};
	auto p_d = partials(d);
	auto p_w = partials(w);
	vector<ll> pdw(N+1);
	for (int i = 0; i <= N; ++i) {
		pdw[i] = p_d[i] * w[i];
	}
	auto p_pdw = partials(pdw);

	const int L = 2;
	vector<vector<ll>> dp(N+1, vector<ll>(L+1, 4e18));
	vector<deque<Function>> cht(L+1);
	auto optimal = [&](int i, int l) -> ll {
		auto &dq = cht[l-1];
		if (dq.empty()) return 4e18;
		ll x = p_w[i];
		while (dq.size() >= 2 && dq[1].eval(x) < dq[0].eval(x)) {
			dq.pop_front();
		}
		return min(p_pdw[i] + dq[0].eval(x), dp[i-1][l-1]);
	};
	auto insert = [&](int i, int l) -> void {
		ll last_dp = (i == 0 ? 0 : dp[i-1][l]);
		Function f = {-p_d[i], -(p_pdw[i]) + (p_d[i] * p_w[i]) + last_dp};
		debug(f.m, f.b);
		auto &dq = cht[l];
		while (dq.size() >= 2 && f.sect(end(dq)[-2]) >= f.sect(end(dq)[-1])) {
			dq.pop_back();
		}
		dq.push_back(f);
	};
	dp[0][1] = dp[0][2] = 0;
	cht[0].push_front({0, 0});
	cht[1].push_front({0, 0});
	cht[2].push_front({0, 0});
	for (int i = 1; i <= N; ++i) {
		for (int l = L; l >= 1; --l) {
			debug(i, l);
			dp[i][l] = optimal(i, l);
			insert(i, l);
		}
	}
	for (int i = 0; i <= N; ++i) {
		debug(i, dp[i]);
	}
	ll ans = optimal(N, L+1);
	cout << ans << '\n';
	debug(d);
	debug(w);
	debug(p_d);
	debug(p_w);
	debug(pdw);
	debug(p_pdw);
}
