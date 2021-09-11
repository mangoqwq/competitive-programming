#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

struct Edge{
    int a, b, c;
    bool operator<(const Edge &rhs) const{
        return c < rhs.c;
    }
};
vector<Edge> edges;
int p[MN], sz[MN];
int Find(int x){ return (p[x] == x ? x : p[x] = Find(p[x])); }
void Union(int a, int b){
    a = Find(a), b = Find(b);
    if (sz[b] > sz[a]) swap(a, b);
    p[b] = a;
    sz[a] += sz[b];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    for (int i = 1; i <= N; ++i) p[i] = i, sz[i] = 1;
    for (int i = 1; i <= M; ++i){
        int a, b, c; cin >> a >> b >> c;
        edges.push_back({a, b, c});
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for (auto [a, b, c] : edges){
        if (Find(a) != Find(b)){
            Union(a, b);
        }
        else{
            if (c > 0) ans += c;
        }
    }
    cout << ans << '\n';
}
