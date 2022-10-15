#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
typedef pair<ll,ll> pll;

const int L=17;
int t=0;
vector<pii> graph[100001];
int d[100001],in[100001],out[100001],up[L+1][100001];

void dfs(int node, int prev, int dist){
    in[node]=++t;
    d[node]=dist;
    up[0][node]=prev;
    for (int i=1;i<=L;++i){
        up[i][node]=up[i-1][up[i-1][node]];
    }
    for (auto&&x:graph[node]){
        if (x.first==prev) continue;
        dfs(x.first,node,dist+x.second);
    }
    out[node]=++t;
}
bool is_ancestor(int a, int b){
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

int dist(int a,int b){
    return d[a]+d[b]-2*d[lca(a,b)];
}
int main(){
    int nodes,days,a,b,c; cin >> nodes >> days;
    for (int i=0;i<nodes-1;++i){
        cin >> a >> b >> c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }
    dfs(1,1,0);
    pll owo={0,0};
    pii bananas={1,1};
    ll temp1,temp2;
    for (int _=0;_<days;++_){
        cin >> a >> b;
        temp1=min(dist(bananas.first,b)+owo.first,dist(bananas.second,b)+owo.second)+dist(a,b);
        temp2=min(dist(bananas.first,a)+owo.first,dist(bananas.second,a)+owo.second)+dist(a,b);
        owo.first=temp1; owo.second=temp2;
        bananas={a,b};
    }
    cout << min(owo.first,owo.second) << '\n';
}