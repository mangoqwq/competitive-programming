#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct Point{
	ll x, y;
	bool operator<(const Point &other) const{
		return tie(x, y) < tie(other.x, other.y);
	}
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
	vector<Point> oa(N), ob(M);
	for (int i = 0; i < N; ++i){
		cin >> oa[i].x >> oa[i].y;
	}
	for (int i = 0; i < M; ++i){
		cin >> ob[i].x >> ob[i].y;
	}
	sort(oa.begin(), oa.end());
	sort(ob.begin(), ob.end());
	vector<Point> a, b;
	for (auto [x, y] : oa){
		if (a.empty() || y < a.back().y){
			a.push_back({x, y});
		}
	}
	for (auto [x, y] : ob){
		while (!b.empty() && b.back().y <= y){
			b.pop_back();
		}
		b.push_back({x, y});
	}
	ll ans = 0;
	auto go = [&](auto self, int l, int r, int ql, int qr){
		if (l >= r) return;
		if (ql == qr) return;
		int m = (ql + qr) >> 1;
		ll best = 0, arg = l, cur;
		for (int i = l; i < r; ++i){
			if (b[m].x <= a[i].x) break;
			cur = (b[m].x - a[i].x) * (b[m].y - a[i].y);
			if (a[i].y >= b[m].y) cur = 0;
			if (cur >= best){
				best = cur;
				arg = i;
			}
		}
		ans = max(ans, best);
		self(self, l, arg+1, ql, m);
		self(self, arg, r, m+1, qr);
	};
	go(go, 0, a.size(), 0, b.size());
	cout << ans << '\n';
}
