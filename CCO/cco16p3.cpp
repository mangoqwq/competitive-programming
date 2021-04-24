#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int n, m;
vector<int> adj[MAXN];
int dep[MAXN], val[MAXN];
bool ans1, ans3, ans4, ans5;

int dfs1(int v, int p){
    for (int to:adj[v]){
        if (to==p||dep[to]) continue;
        dep[to]=dep[v]+1;
        val[v]+=dfs1(to,v);
    }
    for (int to:adj[v]){
        if (to==p||dep[to]>dep[v]) continue;
        val[v]++; val[to]--;
    }
    if (val[v]>=2) ans1=1;
    return val[v];
}

bool solve1(){
    ans1=0;
    for (int i=1;i<=n;++i) dep[i]=val[i]=0;
    dep[1]=1; dfs1(1,0);
    return ans1;
}

bool solve2(){
    return m>=n;
}

void dfs3(int v, int p){
    for (int to:adj[v]){
        if (to==p||dep[to]) continue;
        dep[to]=dep[v]+1;
        dfs3(to,v);
    }
    for (int to:adj[v]){
        if (to==p||dep[to]>dep[v]) continue;
        if (dep[v]-dep[to]+1>=4) ans3=1;
        val[v]=1;
    }
}

bool solve3(){
    ans3=0;
    for (int i=1;i<=n;++i) dep[i]=val[i]=0;
    dep[1]=1; dfs3(1,0);
    for (int v=1;v<=n;++v){
        int cnt=val[v];
        for (int to:adj[v]){
            if (dep[to]!=dep[v]+1) continue;
            cnt+=val[to];
        }
        if (cnt>=2) ans3=1;
    }
    return ans3;
}

bool solve4(){
    ans4=0;
    for (int i=1;i<=n;++i){
        ans4|=adj[i].size()>=3;
    }
    return ans4;
}

int va, vb;
int onloop[MAXN], last[MAXN], fox[MAXN];
queue<int> q;
void bfs5(int src){
    while (!q.empty()) q.pop();
    for (int i=1;i<=n;++i){
        dep[i]=inf;
        last[i]=onloop[i]=fox[i]=0;
    }
    dep[src]=0; q.push(src);
    while (!q.empty()){
        int v=q.front(); q.pop();
        for (int to:adj[v]){
            if (tie(v,to)==tie(va,vb)||tie(v,to)==tie(vb,va)) continue;
            if (dep[v]+1<dep[to]){
                dep[to]=dep[v]+1;
                last[to]=v;
                q.push(to);
            }
        }
    }
}

bool solve5(){
    ans5=0;
    for (va=1;va<=n;++va){
        for (int v:adj[va]){
            vb=v;
            bfs5(va);
            if (dep[vb]==inf) continue;
            for (int i=vb;;i=last[i]){
                onloop[i]=1;
                if (i==va) break;
            }
            int cnt=0;
            for (int i=vb;;i=last[i]){
                bool can=0;
                for (int to:adj[i]){
                    if (onloop[to]) continue;
                    can=1;
                    fox[to]=1;
                }
                cnt+=can;
                if (i==va) break;
            }
            if (cnt>=2&&accumulate(fox+1,fox+1+n,0)>=2) ans5=1;
        }
    }
    return ans5;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int s, t; cin >> s >> t;
    while (t--){
        cin >> n >> m;
        for (int i=1;i<=n;++i) adj[i].clear();
        for (int i=1;i<=m;++i){
            int a, b; cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        bool ans=0;
        if (s==1) ans=solve1();
        if (s==2) ans=solve2();
        if (s==3) ans=solve3();
        if (s==4) ans=solve4();
        if (s==5) ans=solve5();
        cout << (ans?"YES":"NO") << '\n';
    }
}