#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int dx[] = {-1, 0, 1, 0, 0};
int dy[] = {0, 1, 0, -1, 0};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    int x, y; cin >> x >> y;
    using pii = pair<int, int>;
    map<pii, ll> mp;
    mp[{x,y}] = 0;

    auto dist = [&](int a, int b, int c, int d){
        return abs(a-c) + abs(b-d);
    };

    for (int i = 0; i < N; ++i){
        cin >> x >> y;
        map<pii, ll> nxt;
        for (int d = 0; d < 5; ++d){
            int nx = x + dx[d], ny = y + dy[d];
            for (auto [p, lst] : mp){
                auto [a, b] = p;
                ll nd = lst + dist(a,b,nx,ny);
                pii to = {nx,ny};
                if (!nxt.count(to)) nxt[to] = nd;
                else nxt[to] = min(nxt[to], nd);
            }
        }
        swap(mp, nxt);
    }
    ll ans = 1e18;
    for (auto [p, lst] : mp){
        ans = min(ans, lst);
    }
    cout << ans << '\n';
}
