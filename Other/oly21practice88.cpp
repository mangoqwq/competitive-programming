#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

ll p[MN], cnt[MN], sz[MN];
struct Edge{
    int a, b, w;
    bool operator<(const Edge &x) const{
        return w < x.w;
    }
};
vector<Edge> edges;
vector<int> changes;
int Find(int x){ return p[x] == x ? p[x] : p[x] = Find(p[x]); }
void Union(int a, int b){
    a = Find(a), b = Find(b);
    if (a != b){
        p[b] = a;
        cnt[a] += cnt[b] + 1;
        sz[a] += sz[b];
        changes.push_back(a);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    iota(p + 1, p + 1 + N, 1);
    fill(sz + 1, sz + 1 + N, 1);
    for (int i = 1; i < N; ++i){
        int a, b, w; cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }
    sort(edges.begin(), edges.end());
    int last = -1;
    ll ans = 0;
    for (auto [a, b, w] : edges){
        if (w != last){
            for (int v : changes){
                v = Find(v);
                ll nxt = sz[v] * (sz[v] - 1) / 2;
                ans += (nxt - cnt[v]) * (last + 1);
                cnt[v] = nxt;
            }
            changes.clear();
        }
        Union(a, b);
        ans += w;
        last = w;
    }
    for (int v : changes){
        v = Find(v);
        ll nxt = sz[v] * (sz[v] - 1) / 2;
        ans += (nxt - cnt[v]) * (last + 1);
        cnt[v] = nxt;
    }
    changes.clear();
    cout << ans << '\n';
}
