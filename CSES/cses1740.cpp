#include <bits/stdc++.h>

using namespace std;

struct Fenwick{
    vector<int> a;
    Fenwick(int N){ a.resize(N, 0); }
    void ins(int i, int v){
        for (; i < a.size(); i += i & -i) a[i] += v;
    }
    int qry(int i){
        int ret = 0;
        for (; i; i -= i & -i) ret += a[i];
        return ret;
    }
    int qry(int l, int r){
        return qry(r) - qry(l - 1);
    }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    using ll = long long;
    int N; cin >> N;
    struct Seg{ int x, c, l, r; };
    vector<Seg> eve;
    for (int i = 1; i <= N; ++i){
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        x1 += 1e6 + 1; y1 += 1e6 + 1, x2 += 1e6 + 1, y2 += 1e6 + 1;
        if (x1 == x2) eve.push_back({x1, 1, y1, y2});
        if (y1 == y2){
            eve.push_back({x1, 0, y1, 1});
            eve.push_back({x2 + 1, 0, y1, -1});
        }
    }
    sort(eve.begin(), eve.end(), [](Seg a, Seg b){ return tie(a.x, a.c) < tie(b.x, b.c); });
    Fenwick bit(2e6 + 10);
    ll ans = 0;
    for (auto [x, c, l, r] : eve){
        if (c == 0){
            bit.ins(l, r);
        }
        if (c == 1){
            ans = ans + bit.qry(l, r);
        }
    }
    cout << ans << '\n';
}
