#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1, MM = 1e7 + 1;

struct Edge{
    int a, b, w;
    bool operator<(const Edge &rhs) const{
        return w < rhs.w; 
    }
} edges[6 * MM];
int p[MM], sz[MM], T;
int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
bool Union(int a, int b){
    a = Find(a), b = Find(b);
    if (a == b) return 0;
    if (sz[b] > sz[a]) swap(a, b);
    sz[a] += sz[b];
    p[b] = a;
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    vector<int> a(N);
    for (int &x : a) cin >> x;
    sort(a.begin(), a.end());
    a.resize(unique(a.begin(), a.end()) - a.begin());
    int mx = a.back();
    iota(p + 1, p + 1 + mx, 1);
    fill(sz + 1, sz + 1 + mx, 1);
    for (int x : a){
        for (int i = 1; ; ++i){
            int cur = (i == 1 ? x + 1 : x * i);
            if (cur > mx) break;
            int to = *lower_bound(a.begin(), a.end(), cur);
            edges[++T] = {x, to, to % x};
        }
    }
    sort(edges + 1, edges + 1 + T);
    ll ans = 0;
    for (int i = 1; i <= T; ++i){
        auto [a, b, w] = edges[i];
        if (Union(a, b)){
            ans += w;
        }
    }
    cout << ans << '\n';
}
