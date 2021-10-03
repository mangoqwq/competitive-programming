#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 401;

int n, k;
set<int> adj[MN];
int dist[MN], keep[MN], l[MN], r[MN], T;
bool dp[MN][1 << 20];

void prune(int v, int p, int d){
    dist[v] = d;
    if (d == k){
        l[v] = r[v] = ++T;
        keep[v] = 1;
        return;
    }
    l[v] = inf;
    vector<int> rem;
    for (int to : adj[v]){
        if (to == p) continue;
        prune(to, v, d + 1);

        l[v] = min(l[v], l[to]);
        r[v] = max(r[v], r[to]);
        keep[v] |= keep[to];
        if (!keep[to]) rem.push_back(to);
    }
    if (!keep[v]){
        adj[v].clear();
    }
    else{
        for (int x : rem) adj[v].erase(x);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i = 1; i < n; ++i){
        int a, b; cin >> a >> b;
        adj[a].insert(b);
        adj[b].insert(a);
    }
    prune(1, 1, 0);
    if (k > 20){ cout << "DA" << '\n'; return 0; }
    vector<int> vec;
    for (int i = 2; i <= n; ++i){
        if (keep[i]) vec.push_back(i);
    }
    sort(vec.begin(), vec.end(), [](int a, int b){ return r[a] < r[b]; });
    dp[0][0] = 1;
    for (auto v : vec){
        for (int msk = 0; msk < (1 << k); ++msk){
            if (!(1 & (msk >> (dist[v] - 1)))) continue;
            dp[r[v]][msk] |= dp[l[v] - 1][msk - (1 << (dist[v] - 1))];
        }
    }
    cout << (accumulate(dp[T], dp[T] + (1 << k), 0) ? "DA" : "NE") << '\n';
}
