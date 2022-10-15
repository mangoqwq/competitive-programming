#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1,L=18;

vector<int> graph[MAXN];
int dist[MAXN],in[MAXN],out[MAXN],up[MAXN][19],T;

void dfs(int curr, int prev, int d){
    in[curr]=++T;
    dist[curr]=d;
    up[curr][0]=prev;
    for (int i=1;i<=L;++i) up[curr][i]=up[up[curr][i-1]][i-1];
    for (int x:graph[curr]){
        if (x==prev) continue;
        dfs(x,curr,d+1);
    }
    out[curr]=T;
}

bool is(int a, int b){ return in[a]<=in[b]&&out[a]>=out[b]; }

int lca(int a, int b){
    if (is(a,b)) return a;
    if (is(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is(up[a][i],b)) a=up[a][i];
    }
    return up[a][0];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1,a,b;i<n;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    dfs(n,n,0);
    for (int i=1,a,b,c,d;i<=q;++i){
        cin >> a >> b >> c >> d;
        if (dist[a]!=dist[c]) cout << -1 << '\n';
        else if (lca(a,c)==n) cout << -1 << '\n';
        else{
            cout << dist[a]-dist[lca(a,c)] << '\n';
        }
    }

}