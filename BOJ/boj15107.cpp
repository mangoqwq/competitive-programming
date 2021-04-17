#include <bits/stdc++.h>

using namespace std;
const int MAXN=5e4+5;

struct Edge{ int to, c; };
vector<Edge> adj[MAXN];
vector<int> ans;
int n, in[MAXN], out[MAXN], T, arr[MAXN];

void dfs(int v, int p, int pc){
    in[v]=++T;
    unordered_map<int,int> cnt;
    for (auto [to,c]:adj[v]){
        if (to==p) continue;
        dfs(to,v,c);
        cnt[c]++;
    }
    out[v]=T;
    for (auto [to,c]:adj[v]){
        if (to==p) continue;
        if (cnt[c]!=1) arr[in[to]]--, arr[out[to]+1]++;
        if (c==pc){
            arr[1]--;
            arr[in[to]]--, arr[out[to]+1]++;
            arr[in[v]]++, arr[out[v]+1]--;
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n-1;++i){
        int a, b, c; cin >> a >> b >> c;
        adj[a].push_back({b,c});
        adj[b].push_back({a,c});
    }
    dfs(1,1,0);
    for (int i=1;i<=n;++i) arr[i]+=arr[i-1];
    for (int i=1;i<=n;++i){
        if (arr[in[i]]==0) ans.push_back(i);
    }
    cout << ans.size() << '\n';
    for (int x:ans) cout << x << '\n';
}