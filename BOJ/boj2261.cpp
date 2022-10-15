#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt{
    int x, y;  
};
int sq(int x){ return x*x; }
int dist(pt a, pt b){
    return sq(b.x-a.x) + sq(b.y-a.y);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<pt> v(N);
    for (int i = 0; i < N; ++i){
        cin >> v[i].x >> v[i].y;
    }
    auto cmpx = [](pt a, pt b){ return a.x < b.x; };
    auto cmpy = [](pt a, pt b){ return a.y < b.y; };

    sort(v.begin(), v.end(), cmpx);
    int ans = 1e9;
    auto solve = [&](auto self, int l, int r){
        if (r - l <= 3){
            for (int i = l; i < r; ++i){
                for (int j = i+1; j < r; ++j){
                    ans = min(ans, dist(v[i], v[j]));
                }
            }
            sort(v.begin() + l, v.begin() + r, cmpy);
            return;
        }
        int m = (l+r) >> 1;
        int mx = v[m].x;
        self(self, l, m), self(self, m, r);
        vector<pt> tmp(r-l);
        merge(v.begin() + l, v.begin() + m, v.begin() + m, v.begin() + r, tmp.begin(), cmpy);
        copy(tmp.begin(), tmp.end(), v.begin() + l);
        int T = 0;
        for (int i = l; i < r; ++i){
            if (sq(abs(v[i].x - mx)) < ans){
                for (int j = T-1; j >= 0 && sq(v[i].y - tmp[j].y) < ans; --j){
                    ans = min(ans, dist(v[i], tmp[j]));
                }
                tmp[T++] = v[i];
            }
        }
    };
    solve(solve, 0, N);
    cout << ans << '\n';
}
