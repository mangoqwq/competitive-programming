#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1,L=18;

struct Pass{ int one,multi; } cost[MAXN];
struct Edge{ int x,id; };
vector<Edge> graph[MAXN];
int in[MAXN],out[MAXN],T,up[L+1][MAXN];
int cnt[MAXN],diff[MAXN];

int dfs2(int curr, int prev, int id){
    int d=diff[curr];
    for (Edge x:graph[curr]){
        if (x.x==prev) continue;
        d+=dfs2(x.x,curr,x.id);
    }
    cnt[id]=d;
    return d;
}

void dfs(int curr, int prev){
    in[curr]=++T;
    up[0][curr]=prev;
    for (int i=1;i<=L;++i) up[i][curr]=up[i-1][up[i-1][curr]];
    for (Edge x:graph[curr]){
        if (x.x==prev) continue;
        dfs(x.x,curr);
    }
    out[curr]=T;
}

bool is_anc(int a, int b){ return (in[a]<=in[b] && out[a]>=out[b]); }

int lca(int a, int b){
    if (is_anc(a,b)) return a;
    if (is_anc(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is_anc(up[i][a],b)) a=up[i][a];
    }
    return up[0][a];
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a,b,c,d;i<n;++i){
        cin >> a >> b >> c >> d;
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
        cost[i]={c,d};
    }
    dfs(1,1);
    for (int i=2,a,b,c;i<=n;++i){
        a=i-1; b=i; c=lca(a,b);
        diff[c]-=2; diff[a]++; diff[b]++;
    }
    dfs2(1,1,0);
    ll tot=0;
    //for (int i=1;i<=n;++i) cout << diff[i] << " ";
    for (int i=1;i<=n-1;++i){
        //cout << cnt[i] << " ";
        tot+=min((ll)cnt[i]*(ll)cost[i].one,(ll)cost[i].multi);
    }
    cout << tot << '\n';
}