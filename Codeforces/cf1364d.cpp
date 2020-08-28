#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1,L=17;

vector<int> graph[MAXN];
bool vis[MAXN]; int dis[MAXN],p[MAXN],sz[MAXN];
int up[MAXN][L+1], in[MAXN], out[MAXN], T;
int startc, endc, mincycle=0x3f3f3f3f;
vector<int> cycle;
vector<pii> Edges;

int Find(int x){ return (p[x]==x)?x:Find(p[x]); }

void Union(int a, int b){
    a=Find(a); b=Find(b);
    if (sz[b]>sz[a]) swap(a,b);
    p[b]=p[a];
    sz[a]+=sz[b];
}

void dfs(int node, int prev, int d){
    in[node]=++T;
    up[node][0]=prev;
    for (int i=1;i<=L;++i){ up[node][i]=up[up[node][i-1]][i-1]; }
    dis[node]=d;
    for (int x:graph[node]){
        if (x==prev) continue;
        dfs(x,node,d+1);
    }
    out[node]=T;
}

bool is_anc(int a, int b){ return in[a]<=in[b] && out[a]>=out[b]; }

int get_dist(int a, int b){
    int lca;
    if (is_anc(a,b)) lca=a;
    else if (is_anc(b,a)) lca=b;
    else{
        for (int i=L;i>=0;--i){
            if (!is_anc(up[a][i],b)) a=up[a][i];    
        }
        lca=up[a][0];
    }
    return dis[a]+dis[b]-2*dis[lca];
}

void trace(int node, vector<int> &path, int d){
    path.push_back(node);
    vis[node]=1;
    if (node==endc&&d==mincycle) cycle=path;
    for (int x:graph[node]){
        if (vis[x]) continue;
        trace(x,path,d+1);
    }
    path.pop_back();
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m,k; cin >> n >> m >> k;
    for (int i=1;i<=n;++i) p[i]=i;
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b;
        if (Find(a)!=Find(b)){
            graph[a].push_back(b);
            graph[b].push_back(a);
            Union(a,b);
        }
        else{
            Edges.push_back({a,b});
        }
    }
    dfs(1,1,0);
    int distance;
    for (pii x:Edges){
        distance=get_dist(x.f,x.s);
        if (distance<mincycle) mincycle=distance, startc=x.f, endc=x.s;
    }
    vector<int> temp;
    trace(startc,temp,0);

    if (!Edges.empty()){

        if (cycle.size()<=k){
            cout << 2 << '\n';
            cout << cycle.size() << '\n';
            for (int i=0;i<cycle.size();++i) cout << cycle[i] << " ";
            cout << '\n';
        }
        else{
            cout << 1 << '\n';
            for (int i=0;i<=k;i+=2) cout << cycle[i] << " ";
            cout << '\n';
        }
    }
    else{
        vector<int> even,odd;
        int cnt=0,curr;
        queue<int> q; q.push(1); 
        ms(vis,0); vis[1]=1;
        while (!q.empty()){
            int qsize=q.size();
            for (int i=0;i<qsize;++i){
                curr=q.front(); q.pop();
                
                if (cnt%2==0) even.push_back(curr);
                if (cnt%2==1) odd.push_back(curr);
                for (int x:graph[curr]){
                    if (!vis[x]) vis[x]=1, q.push(x);
                }
            }
            cnt++;
        }
        if (even.size()>odd.size()) swap(odd,even);
        cout << 1 << '\n';
        for (int i=0;i<(k+1)/2;++i){
            cout << odd[i] << " ";
        }
        cout << '\n';
    }
}