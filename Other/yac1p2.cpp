#include <bits/stdc++.h>

using namespace std;
#define ms(x, a) memset(x, a, sizeof x)
using ll = long long;
const int mod = 1e9 + 7, inf = 0x3f3f3f3f;
const int MN = 2e5 + 1;

ll ans;
int c[MN]; ll cnt[MN][2];
vector<int> adj[MN];
ll c2(ll x){ return x * (x - 1) / 2; }

void dfs0(int v, int p){
    for (int to : adj[v]){
        if (to == p) continue;
        dfs0(to, v);
        cnt[v][c[to]]++;
    }
    if (v != p) cnt[v][c[p]]++;
}

void dfs(int v, int p){
    for (int to : adj[v]){
        if (to == p) continue;
        dfs(to, v);
    }

    if (c[v] != 0) ans -= c2(cnt[v][0]);
    if (c[v] != 1) ans -= c2(cnt[v][1]);
    ans -= cnt[v][0] * cnt[v][1];
    if (v == p) return;
    
    cnt[v][c[p]]--;
    cnt[p][c[v]]--;
    if (c[v] == c[p]){
        ans -= cnt[v][c[v] ^ 1] * cnt[p][c[v] ^ 1];
    }
    else{
        ans -= cnt[v][0] * cnt[p][1];
        ans -= cnt[v][1] * cnt[p][0];
    }
    cnt[v][c[p]]++;
    cnt[p][c[v]]++;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int N; cin >> N;
    for (int i = 1; i <= N; ++i){
        char x; cin >> x;
        c[i] = x == 'W';
    }
    for (int i = 1; i <= N - 1; ++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    ans = c2(N) - (N - 1);
    // cout << ans << '\n';
    dfs0(1, 1); dfs(1, 1);
    cout << ans << '\n';
}
