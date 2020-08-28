#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1,MAXM=5e4+1,L=17;

struct Edge{ int n, id; };
vector<Edge> graph[MAXN];
vector<int> ans;
int psa[MAXN],edge[MAXN],query[MAXN],n,m,k;
int in[MAXN],out[MAXN],up[MAXN][L+1],T;

bool cmp(int a, int b){ return in[a]<in[b]; }

void dfs0(int curr, int prev){
    in[curr]=++T;
    up[curr][0]=prev;
    for (int i=1;i<=L;++i) up[curr][i]=up[up[curr][i-1]][i-1];
    for (Edge x:graph[curr]){
        if (x.n==prev) continue;
        edge[x.n]=x.id;
        dfs0(x.n,curr);
    }
    out[curr]=T;
}

bool is(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

int lca(int a, int b){
    if (is(a,b)) return a;
    if (is(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

int solve(int curr, int prev){
    int gone=psa[curr];
    for (Edge x:graph[curr]){
        if (x.n==prev) continue;
        gone+=solve(x.n,curr);
    }
    if (gone>=2*k) ans.push_back(edge[curr]);
    return gone;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k;
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
    }
    dfs0(1,1);
    for (int q=1,s,a,anc;q<=m;++q){
        cin >> s;
        for (int i=1;i<=s;++i) cin >> query[i];
        sort(query+1,query+1+s,cmp);
        for (int i=2;i<=s;++i){
            psa[query[i]]++, psa[query[i-1]]++, psa[lca(query[i],query[i-1])]-=2;
        }
        psa[query[s]]++, psa[query[1]]++, psa[lca(query[s],query[1])]-=2;
    }
    solve(1,1);
    sort(ans.begin(),ans.end());
    cout << ans.size() << '\n';
    for (int x:ans) cout << x << " ";
    cout << '\n';
}