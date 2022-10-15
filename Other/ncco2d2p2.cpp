#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1,L=17;

map<int,int> graph[MAXN];
vector<int> tree[MAXN];
int colour[MAXN], lcas[MAXN],cnt[MAXN], arr[MAXN];
int in[MAXN],out[MAXN],T,up[L+1][MAXN];
int ans=0;

void dfs(int node, int prev){
    in[node]=++T;
    up[0][node]=prev;
    for (int i=1;i<=L;++i) up[i][node]=up[i-1][up[i-1][node]];
    for (int x:tree[node]){
        if (x==prev) continue;
        dfs(x,node);
    }
    out[node]=T;
}

bool is_anc(int a,int b){
    return in[a]<=in[b]&&out[a]>=out[b];
}

int lca(int a, int b){
    if (is_anc(a,b)) return a;
    if (is_anc(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is_anc(up[i][a],b)) a=up[i][a];
    }
    return up[0][a];
}

int solve(int node, int prev){
    int uwu=arr[node];
    for (int x:tree[node]){
        if (x==prev) continue;
        uwu+=solve(x,node);
    }
    if (uwu==0) ans++;
    //cout << node << "->" << uwu << ":" << arr[node] << '\n';
    return uwu;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a,b,c,d;i<=n-2;++i){
        cin >> a >> b >> c >> d;
        colour[i]=d;
        if (graph[a].count(b)){
            tree[i].push_back(graph[a][b]);
            tree[graph[a][b]].push_back(i);
        }
        if (graph[b].count(c)){
            tree[i].push_back(graph[b][c]);
            tree[graph[b][c]].push_back(i);
        }
        if (graph[c].count(a)){
            tree[i].push_back(graph[c][a]);
            tree[graph[c][a]].push_back(i);
        }
        graph[a][b]=i;
        graph[b][a]=i;
        graph[b][c]=i;
        graph[c][b]=i;
        graph[a][c]=i;
        graph[c][a]=i;
    }
    // /////////////////////////////////////
    // for (int i=1;i<=n;++i){
    //     cin >> colour[i];
    // }
    // for (int i=1,a,b;i<n;++i){
    //     cin >> a >> b;
    //     tree[a].push_back(b);
    //     tree[b].push_back(a);
    // }
    // ////////////////////////////////////
    dfs(1,1);
    ms(lcas,-1);
    for (int i=1;i<=n;++i){
        if (lcas[colour[i]]==-1) lcas[colour[i]]=i;
        else lcas[colour[i]]=lca(lcas[colour[i]],i);
        cnt[colour[i]]++;
    }
    for (int i=1;i<=n;++i){
        arr[i]++;
        if (lcas[i]!=-1) arr[lcas[i]]-=cnt[i];
        //cout << "color:" << i << "->" << lcas[i] << '\n';
    }
    solve(1,1);
    cout << ans-1 << '\n';
}