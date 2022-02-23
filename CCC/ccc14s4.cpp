#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 0;

struct Seg{
    int x, y1, y2, t, c;
    bool operator<(const Seg &s) const{
        return x < s.x;
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, T; cin >> N >> T;
    vector<Seg> v;
    for (int i = 1; i <= N; ++i){
        int x1, y1, x2, y2, t; cin >> x1 >> y1 >> x2 >> y2 >> t;
        v.push_back({x1, y1, y2, t, 1});
        v.push_back({x2, y1, y2, t, 0});
    }
    sort(v.begin(), v.end());
    int p = 0, lstx = 0; ll ans = 0;
    map<int, int> mp;
    while (p < v.size()){
        int curx = v[p].x;
        int lsty = 0, tint = 0, cur = 0;
        for (auto [y, t] : mp){
            if (tint >= T) cur += (y - lsty);
            lsty = y;
            tint += t;
        }

        ans += 1LL * cur * (curx - lstx);
        lstx = curx;

        while (p < v.size() && v[p].x == curx){
            if (v[p].c == 1){
                mp[v[p].y1] += v[p].t;
                mp[v[p].y2] -= v[p].t;
            }
            if (v[p].c == 0){
                mp[v[p].y1] -= v[p].t;
                mp[v[p].y2] += v[p].t;
            }
            p++;
        }
    }
    cout << ans << '\n';
}
