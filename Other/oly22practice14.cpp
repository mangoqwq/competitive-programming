#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e4 + 1;
const long double EPS = 1e-15;

struct pt {
    double x, y;
};

int orientation(pt a, pt b, pt c) {
    double v = a.x*(b.y-c.y)+b.x*(c.y-a.y)+c.x*(a.y-b.y);
    if (v < 0) return -1; // clockwise
    if (v > 0) return +1; // counter-clockwise
    return 0;
}

bool cw(pt a, pt b, pt c, bool include_collinear) {
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}
bool collinear(pt a, pt b, pt c) { return orientation(a, b, c) == 0; }

void convex_hull(vector<pt>& a, bool include_collinear = false) {
    pt p0 = *min_element(a.begin(), a.end(), [](pt a, pt b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });
    sort(a.begin(), a.end(), [&p0](const pt& a, const pt& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });
    if (include_collinear) {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<pt> st;
    for (int i = 0; i < (int)a.size(); i++) {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    a = st;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<pt> pts(N);
    for (auto &[x, y] : pts) cin >> x >> y, y *= x;
    convex_hull(pts);

    double ans = 0;
    int p = 0;
    function<double(int, int)> f = [&](int i, int j){
        return abs(pts[i].x * pts[j].y - pts[j].x * pts[i].y);
    };
    for (int i = 0; i < pts.size(); ++i){
        while (f(i, p) < f(i, (p - 1 + pts.size()) % pts.size())) p = p - 1 + pts.size(), p %= pts.size();
        ans = max(ans, f(i, p));
    }
    cout << fixed << setprecision(6) << ans << '\n';

    pts.push_back(pts[0]);
    ans = 0;
    for (int i = 0; i < pts.size() - 1; ++i){
        ans += pts[i].x * pts[i + 1].y - pts[i + 1].x * pts[i].y;
    }
    cout << fixed << setprecision(6) << abs(ans) << '\n';
}
