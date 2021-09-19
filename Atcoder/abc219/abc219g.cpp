#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
typedef long long ll;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1, SZ = 1000;

int n, m, q; 
vector<int> adj[MN];

vector<int> big;
const int MB = 501;
int lz[MN], lzt[MN], tc[MN];
bool edge[MB][MN];

int val[MN], T;

void prop(int v){
    int j = -1;
    for (int i = 0; i < big.size(); ++i){
        if (!edge[i][v]) continue;
        if (j == -1 || lzt[big[i]] > lzt[big[j]]) j = i;
    }
    // cout << v << " -> " << big[j] << " | " << val[v] << " " << lz[big[j]] << '\n';
    if (j == -1 || !edge[j][v] || lz[big[j]] == 0 || tc[v] > lzt[big[j]]) return;
    val[v] = lz[big[j]];
    tc[v] = lzt[big[j]];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    iota(val + 1, val + 1 + n, 1);
    for (int i = 1; i <= m; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; ++i){
        if (adj[i].size() >= SZ){
            big.push_back(i);
            int t = big.size() - 1;
            for (auto to : adj[i]) edge[t][to] = 1;
        }
    }
    for (T = 1; T <= q; ++T){
        int v; cin >> v;
        if (adj[v].size() < SZ){
            prop(v);
            for (int to : adj[v]) val[to] = val[v], tc[to] = T;
        }
        else{
            prop(v);
            lz[v] = val[v];
            lzt[v] = T;
        }
    }
    for (int i = 1; i <= n; ++i){
        prop(i);
        cout << val[i] << " ";
    }
    cout << '\n';
}
