#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=501, MAXM=1001;

namespace Dinic{
    const ll flow_inf=1e18;
    struct Edge{
        ll f, c;
        int to, nxt;
    } adj[2*MAXM];
    int head[MAXN], T, level[MAXN], idx[MAXN];
    int n, m, s, t;
    void init(int _n, int _m, int _s, int _t){
        ms(head,-1);
        tie(n,m,s,t)=tie(_n,_m,_s,_t);
    }
    void add_edge(int a, int b, ll c){
        adj[T]={0,c,b,head[a]}, head[a]=T++;
        adj[T]={0,0,a,head[b]}, head[b]=T++;
    }
    void bfs(){
        ms(level,-1);
        level[s]=1;
        queue<int> q; q.push(s);
        while (!q.empty()){
            int v=q.front(); q.pop();
            for (int i=head[v];i!=-1;i=adj[i].nxt){
                auto [f,c,to,nxt]=adj[i];
                if (c-f<=0||level[to]!=-1) continue;
                level[to]=level[v]+1;
                q.push(to);
            }
        }
    }
    ll dfs(int v, ll flow=flow_inf){
        if (flow==0) return 0;
        if (v==t) return flow;
        for (int &i=idx[v];i!=-1;i=adj[i].nxt){
            auto [f,c,to,nxt]=adj[i];
            if (c-f<=0||level[to]!=level[v]+1) continue;
            ll fi=dfs(to,min(flow,c-f));
            if (fi==0) continue;
            adj[i].f+=fi;
            adj[i^1].f-=fi;
            return fi;
        }
        return 0;
    }
    ll max_flow(){
        ll f=0;
        while (true){
            bfs();
            if (level[t]==-1) break;
            for (int i=1;i<=n;++i) idx[i]=head[i];
            while (ll fi=dfs(s)) f+=fi;
        }
        return f;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    Dinic::init(n,m,1,n);
    for (int i=1;i<=m;++i){
        int a, b; ll c; cin >> a >> b >> c;
        Dinic::add_edge(a,b,c);
    }
    cout << Dinic::max_flow() << '\n';
}