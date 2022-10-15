#include <bits/stdc++.h>

using namespace std;
using ll = long long;

struct pt{ ll x, y; };
ll sq(int x){ return x*x; }
ll cross(pt a, pt b, pt c){
    return (b.x-a.x)*(c.y-b.y) - (b.y-a.y)*(c.x-b.x);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<pt> p1(N), p2(N);
    for (int i = 0; i < N; ++i){
        cin >> p1[i].x >> p1[i].y;
        cin >> p2[i].x >> p2[i].y;
    }
    vector<int> sz(N), p(N);
    iota(p.begin(), p.end(), 0);
    fill(sz.begin(), sz.end(), 1);
    function<int(int)> root = [&](int x){
        return p[x] == x ? x : p[x] = root(p[x]);
    };
    auto unite = [&](int a, int b){
        a = root(a), b = root(b);
        if (a != b){
            sz[a] += sz[b];
            p[b] = a;
        }
    };

    auto intersect1d = [&](int l1, int r1, int l2, int r2) -> bool{
        if (l1 > r1) swap(l1, r1);
        if (l2 > r2) swap(l2, r2);
        return max(l1, l2) <= min(r1, r2);
    };

    auto intersect = [&](int i, int j) -> bool{
        return intersect1d(p1[i].x, p2[i].x, p1[j].x, p2[j].x) &&
                intersect1d(p1[i].y, p2[i].y, p1[j].y, p2[j].y) &&
                cross(p1[i], p2[i], p1[j]) * cross(p1[i], p2[i], p2[j]) <= 0 &&
                cross(p1[j], p2[j], p1[i]) * cross(p1[j], p2[j], p2[i]) <= 0;
    };

    for (int i = 0; i < N; ++i){
        for (int j = i+1; j < N; ++j){
            if (intersect(i, j)){
                unite(i, j);
            }
        }
    }
    int ccs = 0;
    for (int i = 0; i < N; ++i){
        if (root(i) == i) ccs++;
    }
    cout << ccs << '\n';
    cout << *max_element(sz.begin(), sz.end()) << '\n';
}   
