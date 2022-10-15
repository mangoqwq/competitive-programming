#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1,L=17;

struct Toll{int a,b;};
struct Cnt{ll start,end,anc;};
vector<Toll> tolls;
vector<int> graph[MAXN];
vector<int> stops={1};
int in[MAXN],out[MAXN],up[MAXN][L+1],T;
int depth[MAXN]; Cnt cnt[MAXN];
ll pows[1'000'001];

void dfs(int curr, int prev, int d){
    in[curr]=++T;
    depth[curr]=d;
    up[curr][0]=prev;
    for (int i=1;i<=L;++i) up[curr][i]=up[up[curr][i-1]][i-1];
    for (int x:graph[curr]){
        if (x==prev) continue;
        dfs(x,curr,d+1);
    }
    out[curr]=T;
}

bool is_anc(int a, int b){
    return in[a]<=in[b]&&out[a]>=out[b];
}

int lca(int a, int b){
    if (is_anc(a,b)) return a;
    if (is_anc(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is_anc(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

void dfs2(int curr, int prev){
    for (int x:graph[curr]){
        if (x==prev) continue;
        dfs2(x,curr);
        cnt[curr].start+=cnt[x].start;
        cnt[curr].end+=cnt[x].end;
        cnt[curr].anc+=cnt[x].anc;
    }
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    pows[0]=1;
    for (int i=1;i<=1'000'000;++i){
        pows[i]=pows[i-1]*2;
        pows[i]%=mod;
    }
    for (int i=0,a,b,c;i<n-1;++i){
        cin >> a >> b >> c;
        if (c){tolls.push_back({a,b});}
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    int k; cin >> k;
    for (int i=1,a;i<=k;++i){
        cin >> a;
        stops.push_back(a);
    }
    dfs(1,1,0);
    for (int i=1,a,b;i<=k;++i){
        a=stops[i-1],b=stops[i];
        cnt[a].start++;
        cnt[b].end++;
        cnt[lca(a,b)].anc++;
    }
    dfs2(1,1);
    ll ans=0;
    for (Toll x:tolls){
        if (depth[x.a]<depth[x.b]){
            ans+=pows[cnt[x.b].start-cnt[x.b].anc];
        }
        if (depth[x.a]>depth[x.b]){
            ans+=pows[cnt[x.a].end-cnt[x.a].anc];
        }
        ans--; ans%=mod;
    }
    cout << ans << '\n';
}