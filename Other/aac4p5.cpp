#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 5e5 + 1;

int p[MN], sz[MN];
set<int> adj[MN];
vector<int> comp[MN];
int Find(int x){ return p[x] == x ? x : p[x] = Find(p[x]); }
void Union(int a, int b){
    a = Find(a), b = Find(b);
    if (p[a] != p[b]){
        p[b] = a;
        sz[a] += sz[b];
    }
}
void bad(){
    cout << -1 << '\n';
    exit(0);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N, M, X, Q; cin >> N >> M >> X >> Q;
    int tmp = M;
    for (int i = 1; i <= N; ++i){
        p[i] = i;
        sz[i] = 1;
    }
    for (int i = 1; i <= Q; ++i){
        int a, b; cin >> a >> b;
        Union(a, b);
    }
    vector<int> rts;
    for (int i = 1; i <= N; ++i){
        if (Find(i) == i){
            rts.push_back(i);
        }
    }
    if (rts.size() < X) bad();
    sort(rts.begin(), rts.end(), [](int a, int b){ return sz[a] < sz[b]; });
    while (rts.size() > X){
        int v = rts.back(); rts.pop_back();
        Union(v, rts.back());
    }
    rts.clear();
    for (int i = 1; i <= N; ++i){
        comp[Find(i)].push_back(i);
        if (Find(i) == i) rts.push_back(i);
    }
    for (int rt : rts){
        if (comp[rt].size() == 1) continue;
        for (int i = 1; i < comp[rt].size(); ++i){
            adj[comp[rt][i - 1]].insert(comp[rt][i]);
            M--;
        }
        adj[comp[rt].back()].insert(comp[rt][0]);
        M--;
    }
    if (M < 0) bad();
    [&]{
        if (!M) return;
        for (int i = 1; i <= N; ++i){
            for (int j = 1; j <= N; ++j){
                if (i == j) continue;
                if (Find(i) > Find(j)) continue;
                if (adj[i].count(j)) continue;
                adj[i].insert(j);
                M--;
                if (!M) return;
            }
        }
    }();
    if (M != 0) bad();
    int cnt = 0;
    for (int i = 1; i <= N; ++i){
        for (int to : adj[i]){
            cout << i << " " << to << '\n';
            cnt++;
        }
    }
    assert(cnt == tmp);
}
