#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
#define mid ((l + r) >> 1)
#define lc (v + 1)
#define rc (v + 2 * (mid - l + 1))
typedef long long ll;
const int mod = 1e9 + 7;
const ll inf = 0x3f3f3f3f3f3f3f3f;
const int MN = 2e5 + 1;

ll N, M, K, Q;
ll c[MN], t[MN];
vector<ll> cs[MN], nxt[MN], st[MN * 2], ccomp, tcomp;
struct Edge{ ll to, w; };
bool operator<(Edge a, Edge b){ return a.w > b.w; }
vector<Edge> adj[MN];
void compress(ll arr[], int n, vector<ll> &comp){
    for (int i = 1; i <= n; ++i) comp.push_back(arr[i]);
    sort(comp.begin(), comp.end());
    for (int i = 1; i <= n; ++i){
        if (arr[i] == inf) continue;
        arr[i] = lower_bound(comp.begin(), comp.end(), arr[i]) - comp.begin() + 1;
    }
}

void dijkstra(){
    ms(t, 0x3f); t[0] = 0;
    priority_queue<Edge> pq;
    pq.push({0, 0});
    while (!pq.empty()){
        auto [v, ct] = pq.top(); pq.pop();
        for (auto [to, w] : adj[v]){
            if (t[to] > ct + w){
                t[to] = ct + w;
                pq.push({to, t[to]});
            }
        }
    }
}

void build(int v = 1, int l = 1, int r = N){
    if (l == r) st[v] = nxt[l];
    else{
        build(lc, l, mid), build(rc, mid + 1, r);
        st[v].resize(st[lc].size() + st[rc].size());
        merge(st[lc].begin(), st[lc].end(), st[rc].begin(), st[rc].end(), st[v].begin());
    }
}

int qry(int ql, int qr, ll x, int v = 1, int l = 1, int r = N){
    if (l > qr || r < ql || ql > qr) return 0;
    if (l >= ql && r <= qr) return st[v].end() - upper_bound(st[v].begin(), st[v].end(), x);
    return qry(ql, qr, x, lc, l, mid) + qry(ql, qr, x, rc, mid + 1, r);
}

signed main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> N >> M >> K >> Q;
    for (int i = 1; i <= N - 1; ++i){
        cin >> c[i];
    }
    compress(c, N - 1, ccomp);
    for (int i = 1; i <= K; ++i){
        ll v, w; cin >> v >> w;
        adj[0].push_back({v, w});
    }
    for (int i = 1; i <= M; ++i){
        ll a, b, w; cin >> a >> b >> w;
        adj[b].push_back({a, w});
    }
    dijkstra();
    compress(t, N - 1, tcomp);
    for (int i = 1; i <= N - 1; ++i){
        if (t[i] == inf) continue;
        cs[c[i]].push_back(t[i]);
    }
    for (int i = 1; i <= N - 1; ++i){
        sort(cs[i].begin(), cs[i].end());
        cs[i].push_back(inf);
        for (int j = 0; j < cs[i].size() - 1; ++j){
            nxt[cs[i][j]].push_back(cs[i][j + 1]);
        }
    }
    for (int i = 1; i <= N; ++i) sort(nxt[i].begin(), nxt[i].end());
    build();
    ll ans = 0;
    for (int i = 1; i <= Q; ++i){
        ll l, r; cin >> l >> r;
        l ^= ans, r ^= ans;
        l = lower_bound(tcomp.begin(), tcomp.end(), l) - tcomp.begin() + 1;
        r = upper_bound(tcomp.begin(), tcomp.end(), r) - tcomp.begin();
        cout << (ans = qry(l, r, r)) << '\n';
    }
}
