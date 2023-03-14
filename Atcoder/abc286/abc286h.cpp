#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

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
	long double dist() const { return sqrtl((long double)dist2()); }
	// angle to x-axis in interval [-pi, pi]
	long double angle() const { return atan2l(y, x); }
	P unit() const { return *this/dist(); } // makes dist()=1
	P perp() const { return P(-y, x); } // rotates +90 degrees
	P normal() const { return perp().unit(); }
	// returns point rotated 'a' radians ccw around the origin
	P rotate(long double a) const {
		return P(x*cos(a)-y*sin(a),x*sin(a)+y*cos(a)); }
	friend ostream& operator<<(ostream& os, P p) {
		return os << "(" << p.x << "," << p.y << ")"; }
};

template<class P> bool onSegment(P s, P e, P p) {
	return p.cross(s, e) == 0 && (s - p).dot(e - p) <= 0;
}

template<class P> vector<P> segInter(P a, P b, P c, P d) {
	auto oa = c.cross(d, a), ob = c.cross(d, b),
	     oc = a.cross(b, c), od = a.cross(b, d);
	// Checks if intersection is single non-endpoint point.
	if (sgn(oa) * sgn(ob) < 0 && sgn(oc) * sgn(od) < 0)
		return {(a * ob - b * oa) / (ob - oa)};
	set<P> s;
	if (onSegment(c, d, a)) s.insert(a);
	if (onSegment(c, d, b)) s.insert(b);
	if (onSegment(a, b, c)) s.insert(c);
	if (onSegment(a, b, d)) s.insert(d);
	return {all(s)};
}

int main(){
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	using P = Point<long double>;

	int N; cin >> N;
	vector<P> poly(N);
	for (int i = 0; i < N; ++i){
		cin >> poly[i].x >> poly[i].y;
	}
	P S, T;
	cin >> S.x >> S.y;
	cin >> T.x >> T.y;

	bool intersects = [&]() -> bool {
		for (int i = 0; i < N; ++i){
			if (!segInter(S, T, poly[i], poly[(i+1)%N]).empty()){
				return 1;
			}
		}
		return 0;
	}();

	if (!intersects){
		cout << fixed << setprecision(14) << (S-T).dist() << '\n';
		return 0;
	}

	for (P &pt : poly) pt = pt - S;
	T = T - S;
	S = S - S;

	long double ang = T.angle();
	for (P &pt : poly){
		pt = pt.rotate(-ang);
	}
	T = T.rotate(-ang);

	// for (P pt : poly){
	// 	cout << pt << '\n';
	// }

	auto compute = [&](vector<P> poly) -> long double {
		int idx = 0;
		for (int i = 0; i < N; ++i){
			if (poly[i].y <= 0 && poly[(i+1)%N].y >= 0) idx = i;
		}
		rotate(poly.begin(), poly.begin()+idx, poly.end());
		deque<P> vec;
		for (P pt : poly){
			if (pt.y >= 0) vec.push_back(pt);
		}
		reverse(vec.begin(), vec.end());
		int p1 = 0;
		while (p1 != vec.size()-1 && (vec[p1] - S).angle() <= (vec[p1+1] - S).angle()){
			p1++;
		}
		int p2 = vec.size() - 1;
		while (p2 != 0 && (vec[p2] - T).angle() >= (vec[p2-1] - T).angle()){
			p2--;
		}
		// for (P pt : vec){
		// 	cout << pt << " ";
		// }
		// cout << '\n';
		// cout << vec[p1] << " " << vec[p2] << '\n';
		long double ret = (vec[p1] - S).dist() + (vec[p2] - T).dist();
		// cout << ret << '\n';
		for (int i = p1; i < p2; ++i){
			ret += (vec[i+1] - vec[i]).dist();
			// cout << (vec[i+1] - vec[i]).dist() << '\n';
		}
		return ret;
	};

	long double ans1 = compute(poly);
	for (P &pt : poly) pt.y = -pt.y;
	reverse(poly.begin(), poly.end());
	long double ans2 = compute(poly);
	cout << fixed << setprecision(14) << min(ans1, ans2) << '\n';
}
