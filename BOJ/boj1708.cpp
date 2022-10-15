#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt{
    ll x, y;
};
ll sq(ll x){ return x*x; }
ll cross(pt a, pt b, pt c){
    return (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<pt> v(N);
    for (int i = 0; i < v.size(); ++i){
        cin >> v[i].x >> v[i].y;
    }
    sort(v.begin(), v.end(), [&](pt a, pt b){
        return tie(a.x, a.y) < tie(b.x, b.y);
    });
    pt v0 = v[0];
    vector<pt> ans = {v0};
    sort(v.begin(), v.end(), [&](pt a, pt b){
        ll c = cross(v0, a, b);
        if (c == 0){
            return sq(a.x-v0.x) + sq(a.y-v0.y) < sq(b.x-v0.x) + sq(b.y-v0.y);
        }
        else return c > 0;
    });
    for (int i = 1; i < v.size(); ++i){
        while (ans.size() >= 2 && cross(ans[ans.size()-2], ans.back(), v[i]) <= 0){
            ans.pop_back();
        }
        ans.push_back(v[i]);
    }
    cout << ans.size() << '\n';
}
