#include <bits/stdc++.h>

using namespace std;
using ll = long long;

#ifdef _DEBUG
#include "utils/debug.h"
#else
#define debug(...)
#endif

template <class T> int sgn(T x) { return (x > 0) - (x < 0); }
template<class T>
struct Point {
	typedef Point P;
	T x, y;
	explicit Point(T x=0, T y=0) : x(x), y(y) {}
	bool operator<(P p) const { return tie(x,y) < tie(p.x,p.y); }
	bool operator==(P p) const { return tie(x,y)==tie(p.x,p.y); }
	P operator+(P p) const { return P(x+p.x, y+p.y); }
	P operator-(P p) const { return P(x-p.x, y-p.y); }
	P operator*(T d) const { return P(x*d, y*d); }
	P operator/(T d) const { return P(x/d, y/d); }
	T dot(P p) const { return x*p.x + y*p.y; }
	T cross(P p) const { return x*p.y - y*p.x; }
	T cross(P a, P b) const { return (a-*this).cross(b-*this); }
	T dist2() const { return x*x + y*y; }
	double dist() const { return sqrt((double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	double angle() const { return atan2(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};
using P = Point<ll>;

int main() {
	cin.tie(0)->sync_with_stdio(0);
	int N, M; cin >> N >> M;
	vector<P> p(N);
	for (int i = 0; i < N; ++i) { 
		cin >> p[i].x >> p[i].y;
	}
	p.push_back(p[0]);

	while (M--) {
		P x; cin >> x.x >> x.y;
		auto boundary = [&]() -> bool {
			for (int i = 0; i < N; ++i) {
				bool on = 1;
				on &= p[i].cross(x, p[i+1]) == 0;
				on &= x.x >= min(p[i].x, p[i+1].x);
				on &= x.x <= max(p[i].x, p[i+1].x);
				on &= x.y >= min(p[i].y, p[i+1].y);
				on &= x.y <= max(p[i].y, p[i+1].y);
				if (on) return 1;
			}
			return 0;
		}();

		if (boundary) {
			cout << "BOUNDARY" << '\n';
		}
		else {
			int src = 0;
			while (p[src].y == x.y) {
				src++;
			}

			ll lsty = p[src].y;
			int cnt = 0;
			for (int _i = 1; _i <= N; ++_i) {
				int i = (_i + src) % N;
				int j = (i-1+N) % N;
				// crossed the ray ----->
				if ((lsty - x.y) * (p[i].y - x.y) < 0) {
					double lambda = 1.0 * (x.y - p[i].y) / (p[j].y - p[i].y);
					double sect = lambda * (p[j].x - p[i].x) + p[i].x;
					// debug(sect);
					if (sect > x.x) cnt++;
				}
				// debug(lsty);
				if (p[i].y != x.y) lsty = p[i].y;
			}
			// debug(cnt);
			cout << (cnt % 2 == 0 ? "OUTSIDE" : "INSIDE") << '\n';
		}
	}
}
