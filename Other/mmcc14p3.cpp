#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

vector<int> adj[MAXN];
set<int> cnt[MAXN];
bool vis[MAXN];
int dep[MAXN], par[MAXN], n, k;

void reset(int v, int p, int d){
    par[v]=p;
    cnt[d].insert(v);
    dep[v]=d;
    for (int to:adj[v]){
        if (to==p) continue;
        reset(to,v,d+1);
    }
}

void flood(int v, int p, int d){
    vis[v]=1;
    cnt[dep[v]].erase(v);
    if (!d) return;
    for (int to:adj[v]){
        if (to==p) continue;
        flood(to,v,d-1);
    }
}

bool solve(int d){
    ms(vis,0);
    for (int i=1;i<=n;++i) cnt[dep[i]].insert(i);
    int p=n;
    int used=0;
    while (p){
        while (p&&cnt[p].empty()) p--;
        if (p==0) break;
        used++;
        int v=*cnt[p].begin(); cnt[p].erase(v);
        for (int i=1;i<=d;++i) v=par[v];
        flood(v,v,d);
    }
    return used<=k;
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
    int lo=0, hi=n, mid;
    while (lo<hi){
        mid=lo+hi>>1;
        if (solve(mid)) hi=mid;
        else lo=mid+1;
    }
    cout << lo << '\n';
}