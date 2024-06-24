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
	int N; cin >> N;
	vector<ll> B(N), P(N), U(N);
	for (int i = 0; i < N; ++i) cin >> B[i];
	for (int i = 1; i < N; ++i) cin >> P[i];
	for (int i = 1; i < N; ++i) cin >> U[i];
	vector<ll> b = B, p = P, u = U;
	vector<ll> C(N);
	ll shift = 0;
	vector<pair<int, ll>> dq;
	int poi = 0;
	for (int i = 1; i < N; ++i) {
		ll del;

		del = min(p[i], b[i-1]);
		b[i-1] -= del, p[i] -= del;

		del = min(p[i], b[i]);
		b[i] -= del, p[i] -= del;
		ll support = del;

		while (poi != (int)dq.size() && p[i]) {
			auto &[j, r] = dq[poi];
			del = min(r, p[i]);
			r -= del, p[i] -= del, shift -= del;
			C[j] += del;
			if (r == 0) poi++;
		}

		del = min(p[i], u[i]);
		u[i] -= del, p[i] -= del;
		C[i] += del;
		if (p[i]) {
			cout << "NO" << '\n';
			return 0;
		}

		support = min(support, shift + u[i]);
		if (support > shift) {
			dq.push_back({i, support - shift});
			shift = support;
		}
		else {
			while (shift > support) {
				auto &[j, r] = dq[poi];
				del = min(shift-support, r);
				r -= del, shift -= del;
				if (r == 0) poi++;
			}
		}
	}

	cout << "YES" << '\n';
	ll ans = accumulate(C.begin(), C.end(), 0LL);
	cout << ans << '\n';
	for (int i = 1; i < N; ++i) {
		ll del;
		P[i] -= C[i];
		del = min(B[i-1], P[i]);
		B[i-1] -= del, P[i] -= del;
		ll L = del;
		del = min(B[i], P[i]);
		B[i] -= del, P[i] -= del;
		ll R = del;
		cout << L << " " << C[i] << " " << R << '\n';
	}
}
