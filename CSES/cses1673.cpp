#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3f;
const int MN = 5e3 + 1;

int a[MN], b[MN], vis[MN], chg[MN];
ll c[MN], dist[MN];
vector<int> rev[MN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= M; ++i){
        cin >> a[i] >> b[i] >> c[i];
        c[i] *= -1;
        rev[b[i]].push_back(a[i]);
    }
    ms(dist, 0x3f); dist[1] = 0;
    bool changed;
    for (int it = 1; it <= N; ++it){
        changed = 0; ms(chg, 0);
        for (int i = 1; i <= M; ++i){
            if (dist[a[i]] == infll) continue;
            if (dist[a[i]] + c[i] < dist[b[i]]){
                changed = 1;
                chg[b[i]] = 1;
                dist[b[i]] = min(dist[b[i]], dist[a[i]] + c[i]);
            }
        }
        if (!changed) break;
    }
    function<void(int)> dfs = [&](int v){
        if (chg[v]){
            cout << -1 << '\n';
            exit(0);
        }
        for (int to : rev[v]){
            if (vis[to]) continue;
            vis[to] = 1;
            dfs(to);
        }
    };
    dfs(N);
    cout << -dist[N] << '\n';
}
