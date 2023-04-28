#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

typedef unsigned long long ull;
ull modmul(ull a, ull b, ull M) {
	return __int128_t(a) * b % M;
}

typedef complex<double> C;
typedef vector<double> vd;
void fft(vector<C>& a) {
	int n = sz(a), L = 31 - __builtin_clz(n);
	static vector<complex<long double>> R(2, 1);
	static vector<C> rt(2, 1);  // (^ 10% faster if double)
	for (static int k = 2; k < n; k *= 2) {
		R.resize(n); rt.resize(n);
		auto x = polar(1.0L, acos(-1.0L) / k);
		rep(i,k,2*k) rt[i] = R[i] = i&1 ? R[i/2] * x : R[i/2];
	}
	vi rev(n);
	rep(i,0,n) rev[i] = (rev[i / 2] | (i & 1) << L) / 2;
	rep(i,0,n) if (i < rev[i]) swap(a[i], a[rev[i]]);
	for (int k = 1; k < n; k *= 2)
		for (int i = 0; i < n; i += 2 * k) rep(j,0,k) {
			// C z = rt[j+k] * a[i+j+k]; // (25% faster if hand-rolled)  /// include-line
			auto x = (double *)&rt[j+k], y = (double *)&a[i+j+k];        /// exclude-line
			C z(x[0]*y[0] - x[1]*y[1], x[0]*y[1] + x[1]*y[0]);           /// exclude-line
			a[i + j + k] = a[i + j] - z;
			a[i + j] += z;
		}
}

ll M;
typedef vector<ll> vl;
vl convMod(const vl &a, const vl &b) {
	if (a.empty() || b.empty()) return {};
	vl res(sz(a) + sz(b) - 1);
	int B=32-__builtin_clz(sz(res)), n=1<<B, cut=int(sqrt(M));
	vector<C> L(n), R(n), outs(n), outl(n);
	rep(i,0,sz(a)) L[i] = C((ll)a[i] / cut, (ll)a[i] % cut);
	rep(i,0,sz(b)) R[i] = C((ll)b[i] / cut, (ll)b[i] % cut);
	fft(L), fft(R);
	rep(i,0,n) {
		int j = -i & (n - 1);
		outl[j] = (L[i] + conj(L[j])) * R[i] / (2.0 * n);
		outs[j] = (L[i] - conj(L[j])) * R[i] / (2.0 * n) / 1i;
	}
	fft(outl), fft(outs);
	rep(i,0,sz(res)) {
		ll av = ll(real(outl[i])+.5), cv = ll(imag(outs[i])+.5);
		ll bv = ll(imag(outl[i])+.5) + ll(real(outs[i])+.5);
		res[i] = ((av % M * cut + bv) % M * cut + cv) % M;
	}
	return res;
}

// https://mathexp.eu/bostan/publications/BoGaSc04.pdf page 5
// main trick: if we have degree d polynomial f with f(0), ..., f(d) known,
// we can calculate f(d+1), ..., f(4d+1) in dlogd time (one fft)

// f1(x) = (x+1)
// f2(x) = (2x+1)(2x+2)
// f4(x) = (4x+1)(4x+2)(4x+3)(4x+4)
// fd(x) = (dx+1)...(dx+d) for d power of 2
// for d=1:
// obviously f1(0), f1(1) are known
// we find f1(2), f1(3), f1(4), f1(5) using paper algorithm
// note f1(0) * f1(1) = 1*2 = f2(0)
// 			f1(2) * f1(3) = 3*4 = f2(1)
// 			f1(4) * f1(5) = 5*6 = f2(2)
// we now have f2(0), ... f2(d+1)
// repeat to get the terms of f4, f8, ..., fn
// this is good because fn(0)fn(1)fn(2)...fn(d) = (nd+n)!

int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll N, P; cin >> N >> P;
	if (N >= P){
		cout << 0 << '\n';
	}
	M = P;

	// precompute some stuff
	const int L = 3e5+10;
	vector<ll> fact(L), inv_fact(L), inverse(L);
	fact[0] = inv_fact[0] = 1;
	inverse[1] = fact[1] = inv_fact[1] = 1;
	for (int i = 2; i < L; ++i){
		inverse[i] = modmul(P - P / i, inverse[P % i], P);
		fact[i] = modmul(fact[i-1], i, P);
		inv_fact[i] = modmul(inv_fact[i-1], inverse[i], P);
	}

	ll d = 1;
	// p = {fd(0), fd(1), ... fd(d)}
	vector<ll> p = {1, 2};
	for (; d < (1 << 17) && d * d < N; d *= 2){
		vector<ll> ptilde(d+1);
		for (int i = 0; i <= d; ++i){
			ptilde[i] = modmul(modmul(inv_fact[d-i], inv_fact[i], P), p[i],P);
			if ((d-i) & 1) ptilde[i] = P - ptilde[i];
		}
		vector<ll> s(inverse.begin(), inverse.begin() + 4*d+2);

		vector<ll> ps = convMod(ptilde, s);
		vector<ll> vals(4*d+2);
		copy(p.begin(), p.end(), vals.begin());

		for (int i = d+1; i <= 4*d+1; ++i){
			vals[i] = modmul(modmul(fact[i], inv_fact[i - (d+1)], P), ps[i], P);
		}

		p = vector<ll>(2*d+1);
		for (int i = 0; i <= 2*d; ++i){
			p[i] = modmul(vals[2*i], vals[2*i+1], P);
		}
	}

	ll ans = 1;
	ll i = 0;
	for (; i <= d * d && i + d <= N; i += d){
		ans = modmul(ans, p[i/d], P);
	}
	i++;
	for (; i <= N; ++i){
		ans = modmul(ans, i, P);
	}
	cout << ans << '\n';
}
