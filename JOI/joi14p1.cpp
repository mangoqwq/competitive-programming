#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5e5+1,L=20;

struct Edge{int n; ll w;};
vector<Edge> graph[MAXN];
int marked[MAXN],sz[MAXN],p[MAXN];
int euler[2*MAXN],first[MAXN],key[MAXN],sparse[2*MAXN][L],lg2[2*MAXN],T,Index;
ll Dist[MAXN],arr[MAXN],inf=0x3f3f3f3f3f3f3f3f;
ll dist[L][MAXN];

int get_sz(int node, int prev){
    sz[node]=1;
    for (Edge x:graph[node]){
        if (marked[x.n]||x.n==prev) continue;
        sz[node]+=get_sz(x.n,node);
    }
    return sz[node];
}

int find_centroid(int node, int prev, int size){
    for (Edge x:graph[node]){
        if (marked[x.n]||x.n==prev) continue;
        if (sz[x.n]*2>size) return find_centroid(x.n,node,size);
    }
    return node;
}

int get_centroid(int node){
    get_sz(node,node);
    int centroid=find_centroid(node,node,sz[node]);
    marked[centroid]=1;
    return centroid;
}

void build(int node, int prev){
    node=get_centroid(node);
    p[node]=prev;
    for (Edge x:graph[node]){
        if (marked[x.n]||x.n==prev) continue;
        build(x.n,node);
    }
}

void dfs(int node, int prev, ll d){
    int temp=T;
    first[node]=Index;
    euler[Index]=T;
    key[T]=node;
    Index++; T++;
    Dist[node]=d;
    for (Edge x:graph[node]){
        if (x.n==prev) continue;
        dfs(x.n,node,d+x.w);
        euler[Index++]=temp;
    }
}

void build_sparse(int n){
    for (int i=0;i<2*n;++i) sparse[i][0]=euler[i];
    for (int len=1;len<=L;++len){
        for (int i=0;i+(1<<len)<=2*n;++i){
            sparse[i][len]=min(sparse[i][len-1],sparse[i+(1<<(len-1))][len-1]);
        }
    }
    lg2[1]=0;
    for (int i=2;i<=2*n;++i){ lg2[i]=lg2[i/2]+1; }
}

void Init(int n, int a[], int b[], int d[]){
    for (int i=0;i<n-1;++i){
        graph[a[i]].push_back({b[i],d[i]});
        graph[b[i]].push_back({a[i],d[i]});
    }
    dfs(0,0,0);
    build_sparse(n);
    ms(arr,0x3f);
    int start=get_centroid(0);
    p[start]=-1;
    int l,r,lg,lca;
    for (Edge x:graph[start]){ build(x.n,start); }
    for (int i=0;i<n;++i){
        for (int k=0,curr=i;curr!=-1;curr=p[curr],++k){
            l=first[i],r=first[curr];
            if (l>r) swap(l,r);
            lg=lg2[r-l+1];
            lca=key[min(sparse[l][lg],sparse[r-(1<<lg)+1][lg])];
            dist[k][i]=Dist[i]+Dist[curr]-2*Dist[lca];
        }
    }
}


ll Query(int s, int x[], int t, int y[]){
    ll ans=inf;
    for (int i=0;i<s;++i){ for (int k=0,curr=x[i];curr!=-1;curr=p[curr],++k) arr[curr]=min(arr[curr],dist[k][x[i]]); }
    for (int i=0;i<t;++i){ for (int k=0,curr=y[i];curr!=-1;curr=p[curr],++k) ans=min(ans,arr[curr]+dist[k][y[i]]); }
    for (int i=0;i<s;++i){ for (int curr=x[i];curr!=-1;curr=p[curr]) arr[curr]=inf; }
    return ans;
}

int main(){
    // cin.tie(0); cin.sync_with_stdio(0);
    // int n,q; cin >> n >> q;
    // int a[n-1],b[n-1],d[n-1];
    // for (int i=0;i<n-1;++i){
    //     cin >> a[i] >> b[i] >> d[i];
    // }
    // Init(n,a,b,d);
    // for (int i=0;i<q;++i){
    //     int s,t; cin >> s >> t;
    //     int x[s],y[t];
    //     for (int k=0;k<s;++k) cin >> x[k];
    //     for (int k=0;k<t;++k) cin >> y[k];
    //     cout << Query(s,x,t,y) << '\n';
    // }
}