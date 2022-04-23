#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 1e5 + 1;

int p[MN], sz[MN], par[MN], bi[MN];
int Find(int x){
    if (p[x] != x){
        int up = Find(p[x]);
        par[x] ^= par[p[x]];
        p[x] = up;
    }
    return p[x];
}
void Union(int a, int b){
    int la = Find(a), lb = Find(b);
    if (la == lb){
        if (par[a] == par[b]){
            bi[la] = 0;
        }
    }
    else{
        if (sz[lb] > sz[la]) swap(la, lb);
        p[lb] = p[la];
        bi[la] |= bi[lb];
        sz[la] += sz[lb];
        par[lb] = par[a] ^ par[b] ^ 1;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M; cin >> N >> M;
    iota(p + 1, p + 1 + N, 1);
    fill(sz + 1, sz + 1 + N, 1);
    fill(bi + 1, bi + 1 + N, 1);
    for (int i = 1; i <= M; ++i){
        int a, b; cin >> a >> b;
        Union(a, b);
    }
    bool can = 1;
    for (int i = 1; i <= N; ++i){
        if (Find(i) != i) continue;
        can &= bi[i];
    }
    if (!can) cout << "IMPOSSIBLE" << '\n';
    else{
        for (int i = 1; i <= N; ++i){
            cout << par[i] + 1 << (i == N ? '\n' : ' ');
        }
    }
}
