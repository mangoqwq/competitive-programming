#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt{ int x, y; };
double sq(double x){ return x*x; }
double dist(pt a, pt b){
    return sqrt(sq(b.x-a.x) + sq(b.y-a.y));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int L, W, N; cin >> L >> W >> N;
    vector<pt> v(N);
    for (int i = 0; i < N; ++i){
        cin >> v[i].x >> v[i].y;
        swap(v[i].x, v[i].y);
    }
    auto good = [&](double d) -> bool{
        queue<pt> q;
        vector<int> vis(N);
        for (int i = 0; i < N; ++i){
            if (v[i].x < d){
                vis[i] = 1;
                q.push(v[i]);
            }
        }
        while (!q.empty()){
            pt p = q.front(); q.pop();
            for (int i = 0; i < N; ++i){
                if (!vis[i] && dist(p, v[i]) <= 2*d){
                    vis[i] = 1;
                    q.push(v[i]);
                }
            }
        }
        for (int i = 0; i < N; ++i){
            if (vis[i] && W - v[i].x < d) return 0;
        }
        return 1;
    };
    double lo = 0, hi = W;
    for (int it = 0; it < 50; ++it){
        double mi = (lo + hi) / 2;
        if (good(mi)) lo = mi;
        else hi = mi;
    }
    cout << fixed << setprecision(14) << lo << '\n';
}
