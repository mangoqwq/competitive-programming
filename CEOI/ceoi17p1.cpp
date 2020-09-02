#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1,L=17;

struct Edge{ int n,id; };
struct Edge2{ int a, b; } edges[MAXN];
vector<Edge> graph[MAXN], span[MAXN], back[MAXN];
int p[MAXN], depth[MAXN], val[MAXN];
bool vis[MAXN];
char ans[MAXN];

void build(int curr, int prev, int d){
    depth[curr]=d;
    bool flag=1;
    for (Edge x:graph[curr]){
        if (x.n==prev&&flag){ flag=0; continue; }
        if (depth[x.n]){
            back[curr].push_back({x.n,x.id});
            continue;
        }
        span[curr].push_back({x.n,x.id});
        span[x.n].push_back({curr,x.id});
        build(x.n,curr,d+1);
        p[x.n]=x.id;
        
    }
}

int dfs(int curr){
    int cnt=0;
    vis[curr]=1;
    for (Edge x:span[curr]){
        if (vis[x.n]) continue;
        cnt+=dfs(x.n);
        val[curr]+=val[x.n];
    }
    for (Edge x:back[curr]){
        if (depth[x.n]<depth[curr]) cnt++;
        if (depth[x.n]>depth[curr]) cnt--;
    }
    if (cnt!=0||val[curr]==0) return cnt;
    if ((edges[p[curr]].a==curr)^(val[curr]>0)) ans[p[curr]]='R';
    else ans[p[curr]]='L';
    return cnt;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    fill(ans+1,ans+1+m,'B');
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b;
        graph[a].push_back({b,i});
        graph[b].push_back({a,i});
        edges[i]={a,b};
    }
    for (int i=1;i<=n;++i) if (!depth[i]) build(i,i,1);
    int q; cin >> q;
    for (int i=1,a,b;i<=q;++i){
        cin >> a >> b;
        val[a]--; val[b]++;
    }
    for (int i=1;i<=n;++i) if (!vis[i]) dfs(i);
    for (int i=1;i<=m;++i) cout << ans[i];
    cout << '\n';
}