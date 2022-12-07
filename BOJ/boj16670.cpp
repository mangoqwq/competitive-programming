#include <bits/stdc++.h>

using namespace std;
using ll = long long;
#define mid ((l+r)>>1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l))

struct SegmentTree{
	vector<ll> a, lz;
	SegmentTree(int N) : a(2*N), lz(2*N) {}
	void push(int v, int l, int r){
		a[v] += lz[v];
		if (l + 1 != r){
			lz[lc] += lz[v];
			lz[rc] += lz[v];
		}
		lz[v] = 0;
	}
	void inc(int ql, int qr, ll val, int v, int l, int r){
		push(v, l, r);
		if (l >= qr || ql >= r) return;
		if (l >= ql && r <= qr){
			lz[v] += val, push(v, l, r);
			return;
		}
		inc(ql, qr, val, lc, l, mid), inc(ql, qr, val, rc, mid, r);
		a[v] = max(a[lc], a[rc]);
	};
	ll qry(int ql, int qr, int v, int l, int r){
		push(v, l, r);
		if (l >= qr || ql >= r) return 0;
		if (l >= ql && r <= qr) return a[v];
		return max(qry(ql, qr, lc, l, mid), qry(ql, qr, rc, mid, r));
	}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
	const int MT = 1e6 + 5;
    int N; cin >> N;
	vector<int> qt(N), qd(N);
	vector<int> qs(N);
	SegmentTree st(MT);
	for (int i = 0; i < MT; ++i){
		st.inc(i, i+1, i, 0, 0, MT);
	}
	for (int i = 0; i < N; ++i){
		char c; cin >> c;
		if (c == '+'){
			int t, d; cin >> t >> d;
			st.inc(0, t+1, d, 0, 0, MT);
			qt[i] = t, qd[i] = d;
		}
		if (c == '-'){
			int j; cin >> j; j--;
			int t = qt[j], d = qd[j];
			st.inc(0, t+1, -d, 0, 0, MT);
		}
		if (c == '?'){
			int t; cin >> t;
			ll sub = st.qry(t+1, t+2, 0, 0, MT) - (t+1);
			cout << st.qry(0, t+1, 0, 0, MT) - sub - t << '\n';
		}
		// for (int i = 0; i < 10; ++i){
		// 	cout << st.qry(i, i+1, 0, 0, MT) << " ";
		// }
		// cout << '\n';
	}
}
