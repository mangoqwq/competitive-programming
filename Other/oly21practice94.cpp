#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 301;

ll p[MN];
struct Edge{
    int a, b, w;
    bool operator<(const Edge &x) const{
        return w < x.w;
    }
};
vector<Edge> edges;
int Find(int x){ return p[x] == x ? p[x] : p[x] = Find(p[x]); }
bool Union(int a, int b){
    a = Find(a), b = Find(b);
    if (a != b){
        p[b] = a;
        return 1;
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        p[i] = i;
        int x; cin >> x;
        edges.push_back({0, i, x});
    }
    for (int i = 1; i <= N; ++i){
        for (int j = 1; j <= N; ++j){
            int x; cin >> x;
            if (i < j){
                edges.push_back({i, j, x});
            }
        }
    }
    sort(edges.begin(), edges.end());
    ll ans = 0;
    for (auto [a, b, w] : edges){
        if (Union(a, b)){
            ans += w;
        }
    }
    cout << ans << '\n';
}
