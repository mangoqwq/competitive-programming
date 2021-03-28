#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

vector<int> adj[MAXN];
bool vis[MAXN];
int dep[MAXN], par[MAXN], n, k;
int ord[MAXN], in[MAXN], out[MAXN], T, deep[MAXN];

struct Fenwick{
    int a[MAXN];
    void upd(int i, int v){ for (;i<MAXN;i+=i&-i) a[i]+=v; }
    int qry(int i){
        int ret=0;
        for (;i;i-=i&-i) ret+=a[i];
        return ret;
    }
} bit;

void reset(int v, int p, int d){
    in[v]=++T;
    par[v]=p;
    dep[v]=d;
    deep[v]=0;
    for (int to:adj[v]){
        if (to==p) continue;
        reset(to,v,d+1);
        deep[v]=max(deep[v],deep[to]+1);
    }
    out[v]=T;
}

int eek;

void flood(int v, int p, int d){
    vis[v]=1;
    if (!d) return;
    for (int to:adj[v]){
        if (to==p) continue;
        if (dep[to]>dep[v]){
            if (deep[to]<=d-1) bit.upd(in[to],1), bit.upd(out[to]+1,-1);
            else if (deep[to]>eek) flood(to,v,d-1);
        }
        else flood(to,v,d-1);
    }
}

bool solve(int d){
    ms(vis,0);
    ms(bit.a,0);
    eek=d;
    int used=0;
    for (int i=n;i>=1;--i){
        int v=ord[i];
        if (bit.qry(in[v])||vis[v]) continue;
        for (int i=1;i<=d;++i) v=par[v];
        bit.upd(in[v],1), bit.upd(out[v]+1,-1);
        used++;
        if (used>k) return 0;
        if (d) flood(par[v],v,d-1);
    }
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1;i<=n-1;++i){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    reset(1,1,1);
    iota(ord+1,ord+1+n,1);
    sort(ord+1,ord+1+n,[](int a, int b){ return dep[a]<dep[b]; });
    int lo=0, hi=n, mid;
    while (lo<hi){
        mid=lo+hi>>1;
        if (solve(mid)) hi=mid;
        else lo=mid+1;
    }
    cout << lo << '\n';
}