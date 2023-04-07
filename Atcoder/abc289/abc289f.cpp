#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int main(){
	cin.tie(0)->sync_with_stdio(0);
	ll sx, sy; cin >> sx >> sy;
	ll tx, ty; cin >> tx >> ty;
	ll a, b, c, d; cin >> a >> b >> c >> d;

	bool solvable = [&]() -> bool {
		if (abs(sx - tx) % 2 == 1) return 0;
		if (abs(sy - ty) % 2 == 1) return 0;
		return 1;
	}();

	if (!solvable){
		cout << "No" << '\n';
		return 0;
	}

	// auto reflect = [&](ll x, ll y, ll &cx, ll &cy) -> void {
	// 	cx = 2*x - cx;
	// 	cy = 2*y - cy;
	// };

	struct Box{ ll x1, y1, x2, y2; };

	auto contains = [&](Box box, ll x, ll y){
		return x >= box.x1 && x <= box.x2 && y >= box.y1 && y <= box.y2;
	};

	Box cur = {tx, ty, tx, ty};
	vector<Box> hist = {cur};
	int its = 0;
	while (!contains(cur, sx, sy) && its <= 1e6){
		its++;
		ll nx1 = 2*a - cur.x2;
		ll nx2 = 2*b - cur.x1;
		ll ny1 = 2*c - cur.y2;
		ll ny2 = 2*d - cur.y1;
		cur = {nx1, ny1, nx2, ny2};
		hist.push_back(cur);
		// cout << "(" << nx1 << ", " << ny1 << "), (" << nx2 << ", " << ny2 << ")" << '\n';
	}

	if (its >= 1e6){
		cout << "No" << '\n';
		return 0;
	}

	using pii = pair<ll, ll>;
	vector<pii> ans;
	for (int i = hist.size()-2; i >= 0; --i){
		ll nx1 = 2*a - sx;
		ll nx2 = 2*b - sx;
		ll ny1 = 2*c - sy;
		ll ny2 = 2*d - sy;
		ll sxp = max(nx1, hist[i].x1);
		ll syp = max(ny1, hist[i].y1);
		ans.push_back({(sx + sxp)/2, (sy + syp)/2});
		tie(sx, sy) = tie(sxp, syp);
	}

	cout << "Yes" << '\n';
	for (auto [x, y] : ans){
		cout << x << " " << y << '\n';
	}
}
