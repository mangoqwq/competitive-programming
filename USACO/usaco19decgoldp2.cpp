#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=100001,L=17; 
vector<int> graph[MAXN];
bool ans[MAXN];
struct Query{int n,type,id;};
vector<Query> query[MAXN];
int cow[MAXN],up[L+1][MAXN],in[MAXN],out[MAXN];
int n,q,t;

void generate(int node, int prev){
    in[node]=++t;
    up[0][node]=prev;
    for (int i=1;i<=L;++i){
        up[i][node]=up[i-1][up[i-1][node]];
    }
    for (auto&&x:graph[node]){
        if (x==prev) continue;
        generate(x,node);
    }
    out[node]=++t;
}
bool is_ancestor(int a,int b){
    return in[a]<=in[b]&&out[a]>=out[b];
}
int lca(int a,int b){
    if (is_ancestor(a,b)) return a;
    if (is_ancestor(b,a)) return b;
    for (int i=L;i>=0;--i){
        if (!is_ancestor(up[i][a],b)){
            a=up[i][a];
        }
    }
    return up[0][a];
}
stack<int> s[MAXN];
void dfs(int node, int prev){
    s[cow[node]].push(node);
    for (Query x:query[node]){
        if (s[x.type].empty()) continue;
        int test=s[x.type].top();
        if (test==node){ ans[x.id]=1; continue; }
        if (!is_ancestor(test,x.n)||lca(node,x.n)==test) ans[x.id]=1;
    }
    for (int x:graph[node]){
        if (x==prev) continue;
        dfs(x,node);
    }
    s[cow[node]].pop();
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> cow[i];
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        graph[a].push_back(b); graph[b].push_back(a);
    }
    generate(1,1);
    for (int i=1,a,b,c;i<=q;++i){
        cin >> a >> b >> c;
        query[a].push_back({b,c,i});
        query[b].push_back({a,c,i});
    }
    dfs(1,1);
    for (int i=1;i<=q;++i){
        cout << ans[i];
    }
    cout << '\n'; return 0;
}