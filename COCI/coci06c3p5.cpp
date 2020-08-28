#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9,seed=131,MAXN=1e4+1;

vector<int> first[MAXN],graph[MAXN],other[MAXN];
ll val[MAXN];
int in[MAXN];
bool vis[MAXN][2];
bool large;

struct Edge{int a,b;};
vector<Edge> edges;

void dfs(int curr){
    vis[curr][0]=1;
    for (int x:other[curr]){
        if (!vis[x][0]) dfs(x);
    }
}

void dfs2(int curr){
    vis[curr][1]=1;
    for (int x:first[curr]){
        if (!vis[x][1]) dfs2(x);
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i=0,a,b;i<m;++i){
        cin >> a >> b;
        first[a].push_back(b);
        other[b].push_back(a);
        edges.push_back({a,b});
    }
    dfs(2);
    dfs2(1);
    bool yes=vis[1][0];
    for (Edge x:edges){
        if (vis[x.a][0]&&vis[x.a][1]&&vis[x.b][0]&&vis[x.b][1]){
            graph[x.a].push_back(x.b);
            in[x.b]++;
        }
    }
    ms(vis,0);
    int curr;
    queue<int> q; q.push(1); val[1]=1;
    while (!q.empty()){
        curr=q.front(); q.pop();
        //cout << curr << " ";
        for (int x:graph[curr]){
            val[x]+=val[curr];
            if (val[x]>mod) val[x]%=mod,large=true;
            in[x]--;
            if (in[x]==0) q.push(x);
        }
    }
    if (yes&&val[2]==0) cout << "inf" << '\n';
    else if (large) cout << setw(9) << setfill('0') << val[2]%mod << '\n';
    else cout << val[2] << '\n';
}