#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...) 0
#endif

struct Segtree {
	int v, lc, rc;
	Segtree() = default;
	void push(int l, int r);
	void upd(int l, int r, int ql, int qr, int new_v);
	int qry(int l, int r, int i);
};
struct Segtree2D {
	int v, lc, rc;
	Segtree2D();
	void push(int l, int r);
	void upd(int l, int r, int Y, int ql, int qr, int qyl, int qyr, int new_v);
	int qry(int l, int r, int Y, int x, int y);
};

Segtree t[15'000'000]; int pt = 1;
Segtree2D t2[400'000]; int pt2 = 1;

void Segtree::push(int l, int r) {
	if (l == r) return;
	if (!lc) lc = pt++;
	if (!rc) rc = pt++;
}
void Segtree::upd(int l, int r, int ql, int qr, int new_v) {
	if (qr < l || r < ql) return;
	if (l >= ql && r <= qr) {
		v = new_v;
		return;
	}
	int m = (l + r) >> 1;
	push(l, r);
	t[lc].upd(l, m, ql, qr, new_v);
	t[rc].upd(m+1, r, ql, qr, new_v);
}
int Segtree::qry(int l, int r, int i) {
	if (!lc || !rc) return v;
	int m = (l + r) >> 1;
	if (i <= m) return max(v, t[lc].qry(l, m, i));
	else return max(v, t[rc].qry(m+1, r, i));
}

Segtree2D::Segtree2D() : v{pt++}, lc{0}, rc{0} { }
void Segtree2D::push(int l, int r) {
	if (l == r) return;
	if (!lc) lc = pt2++, t2[lc] = Segtree2D();
	if (!rc) rc = pt2++, t2[rc] = Segtree2D();
}
void Segtree2D::upd(int l, int r, int Y, int ql, int qr, int qyl, int qyr, int new_v) {
	if (qr < l || r < ql) return;
	if (l >= ql && r <= qr) {
		t[v].upd(0, Y, qyl, qyr, new_v);
		return;
	}
	int m = (l + r) >> 1;
	push(l, r);
	t2[lc].upd(l, m, Y, ql, qr, qyl, qyr, new_v);
	t2[rc].upd(m+1, r, Y, ql, qr, qyl, qyr, new_v);
}
int Segtree2D::qry(int l, int r, int Y, int x, int y) {
	if (!lc || !rc) return t[v].qry(0, Y, y);
	int m = (l + r) >> 1;
	if (x <= m) return max(t[v].qry(0, Y, y), t2[lc].qry(l, m, Y, x, y));
	else return max(t[v].qry(0, Y, y), t2[rc].qry(m+1, r, Y, x, y));
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int X, Y; cin >> X >> Y;
	int N; cin >> N;

	struct Rect { int x1, x2, y1, y2; }; // [x1, x2] x [y1, y2]
	vector<Rect> rects = {{0, X, 0, Y}};
	auto area = [&](Rect r) -> ll { return 1LL * (r.x2 - r.x1) * (r.y2 - r.y1); };
	Segtree2D st;
	for (int i = 0; i < N; ++i) {
		int x, y, d; cin >> x >> y >> d;
		int j = st.qry(0, X, Y, x, y);
		Rect r = rects[j];
		Rect r1, r2;
		if (d == 1) {
			r1 = {r.x1, r.x2, r.y1, y};
			r2 = {r.x1, r.x2, y, r.y2};
		}
		if (d == 2) {
			r1 = {r.x1, x, r.y1, r.y2};
			r2 = {x, r.x2, r.y1, r.y2};
		}
		ll a1, a2;
		tie(a1, a2) = minmax(area(r1), area(r2));
		cout << a1 << " " << a2 << '\n';
		st.upd(0, X, Y, r1.x1, r1.x2, r1.y1, r1.y2, rects.size());
		rects.push_back(r1);
		st.upd(0, X, Y, r2.x1, r2.x2, r2.y1, r2.y2, rects.size());
		rects.push_back(r2);
	}
}
