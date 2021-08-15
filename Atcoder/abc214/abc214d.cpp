#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

ll p[MN], sz[MN];
int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
ll Union(int a, int b){
    a = Find(a), b = Find(b);
    if (sz[b] > sz[a]) swap(a, b);
    ll ret = sz[a] * sz[b];
    p[b] = a, sz[a] += sz[b];
    return ret;
}

struct Edge{ int a, b, w; };
vector<Edge> edges;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    fill(sz + 1, sz + 1 + N, 1);
    iota(p + 1, p + 1 + N, 1);
    for (int i = 1; i < N; ++i){
        int a, b, w; cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }    
    sort(edges.begin(), edges.end(), [](Edge a, Edge b){ return a.w < b.w; });
    ll ans = 0;
    for (auto [a, b, w] : edges){
        ans += w * Union(a, b);
    }
    cout << ans << '\n';
}
