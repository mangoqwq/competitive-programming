#include <bits/stdc++.h>
 
using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;
int p[MN];
int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
bool Union(int a, int b){
    a = Find(a), b = Find(b);
    if (a == b) return 0;
    return p[b] = a, 1;
}
 
int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    iota(p + 1, p + 1 + N, 1);
    struct Edge{ int a, b, w; };
    vector<Edge> edges;
    for (int i = 1; i <= M; ++i){
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end(), [](Edge x, Edge y){ return x.w < y.w; });
    ll tot = 0, cc = N;
    for (auto [a, b, w] : edges){
        if (Union(a, b)){
            tot += w; cc--;
        }
    }
    if (cc != 1) cout << "IMPOSSIBLE" << '\n';
    else cout << tot << '\n';
}
