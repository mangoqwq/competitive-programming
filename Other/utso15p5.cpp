#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// LCA, sparse table

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=50'001,L=17;

struct Edge{int n, w;}; struct Test{int a,b,w;}; struct Sparse{int anc,w;};
vector<Test> edges;
vector<Test> owo;
vector<Edge> tree[MAXN];
int st[L][MAXN],p[MAXN],in[MAXN],out[MAXN],t,tcost;
Sparse up[L+1][MAXN];

bool cmp(Test a, Test b){return a.w<b.w;}

int find_(int a){
    if (p[a]==a) return a;
    return p[a]=find_(p[a]);
}

void union_(int a, int b){
    p[find_(a)]=find_(b);
}

void dfs(int node, int prev){
    in[node]=++t;
    up[0][node].anc=prev;
    for (int i=1;i<=L;++i){
        up[i][node].anc=up[i-1][up[i-1][node].anc].anc;
        up[i][node].w=max(up[i-1][node].w,up[i-1][up[i-1][node].anc].w);
    }
    for (Edge x:tree[node]){
        if (x.n==prev) continue;
        up[0][x.n].w=x.w;
        dfs(x.n,node);
    }
    out[node]=t;
}

bool anc(int a, int b){
    return in[a]<=in[b]&&out[a]>=out[b];
}

int solve(int a,int curr,int x){
    int ans=0;
    while (curr!=a){
        if (up[0][curr].w!=x) ans=max(ans,up[0][curr].w);
        curr=up[0][curr].anc;
    }
    return ans;
}
int query(int a,int b,int x){
    if (anc(a,b)) return solve(a,b,x);
    if (anc(b,a)) return solve(b,a,x);
    for (int i=L;i>=0;--i){
        if (!anc(up[i][a].anc,b)){
            a=up[i][a].anc;
        }
    }
    return max(solve(up[0][a].anc,a,x),solve(up[0][a].anc,b,x));
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i=1;i<=n;++i) p[i]=i;
    for (int i=0,a,b,w;i<m;++i){
        cin >> a >> b >> w;
        edges.push_back({a,b,w});
    }
    sort(edges.begin(),edges.end(),cmp);
    int a,b,w;
    for (Test x:edges){
        a=x.a,b=x.b,w=x.w;
        if (find_(a)==find_(b)){
            owo.push_back({a,b,w});
            continue;
        }
        tcost+=w;
        tree[a].push_back({b,w});
        tree[b].push_back({a,w});
        union_(a,b);
    }
    dfs(1,1);
    if (owo.empty()||t!=n){ cout << -1 << '\n'; return 0; }
    int ans=INT_MAX;
    int temp=0;
    for (Test x:edges){
        if (up[0][x.a].anc==x.b||up[0][x.b].anc==x.a){
            if (anc(x.a,x.b)){
                temp=tcost-up[0][x.b].w+x.w;
            }
            else{
                temp=tcost-up[0][x.a].w+x.w;
            }
            if (temp!=tcost) ans=min(ans,temp);
            continue;
        }
        temp=tcost-query(x.a,x.b,x.w)+x.w;
        if (temp!=tcost) ans=min(ans,temp);
    }
    cout << (ans==INT_MAX?-1:ans) << '\n';
}