#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void FST(vi& a, bool inv) {
	for (int n = sz(a), step = 1; step < n; step *= 2) {
		for (int i = 0; i < n; i += 2 * step) rep(j,i,i+step) {
			int &u = a[j], &v = a[j + step]; tie(u, v) =
				// inv ? pii(v - u, u) : pii(v, u + v); // AND
				// inv ? pii(v, u - v) : pii(u + v, u); // OR /// include-line
				pii(u + v, u - v);                   // XOR /// include-line
		}
	}
	if (inv) for (int& x : a) x /= sz(a); // XOR only /// include-line
}
vi conv(vi a, vi b) {
	FST(a, 0); FST(b, 0);
	rep(i,0,sz(a)) a[i] *= b[i];
	FST(a, 1); return a;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N; cin >> N;
	int sum = 0;
	bool make0 = 0;
	vector<int> p(1 << 20);
	p[0] = 1;
	for (int i = 0; i < N; ++i) {
		int x; cin >> x;
		sum ^= x;
		make0 |= p[sum];
		p[sum] = 1;
	}

	p = conv(p, p);
	p[0] = make0;
	vector<int> ans;
	for (int i = 0; i < (int)p.size(); ++i) {
		if (p[i]) ans.push_back(i);
	}
	int n = ans.size();
	cout << n << '\n';
	for (int i = 0; i < n; ++i) {
		cout << ans[i] << (i == n - 1 ? '\n' : ' ');
	}
}
