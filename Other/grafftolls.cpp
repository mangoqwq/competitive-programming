#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int head[MAXN], depth[MAXN], p[MAXN], heavy[MAXN], n;
int pos[MAXN], T;
ll val[MAXN], tree[4*MAXN];
vector<int> graph[MAXN];

int dfs(int curr){
    int sz=1, best=0;
    for (int x:graph[curr]){
        if (x==p[curr]) continue;
        p[x]=curr, depth[x]=depth[curr]+1;
        int temp=dfs(x); sz+=temp;
        if (temp>best) best=temp, heavy[curr]=x;
    }
    return sz;
}

void decomp(int curr, int h){
    head[curr]=h; pos[curr]=++T;
    if (heavy[curr]!=-1) decomp(heavy[curr],h);
    for (int x:graph[curr]){
        if (x!=p[curr]&&x!=heavy[curr]) decomp(x,x);
    }
}

ll seg_query(int node, int start, int end, int l, int r){
    if (r<start||l>end) return 0;
    if (start>=l&&end<=r) return tree[node];
    int mid=(start+end)>>1;
    return seg_query(2*node,start,mid,l,r)+seg_query(2*node+1,mid+1,end,l,r);
}

void seg_update(int node, int start, int end, int idx, ll val){
    if (start==end) return void(tree[node]=val);
    int mid=(start+end)>>1;
    if (idx<=mid) seg_update(node*2,start,mid,idx,val);
    else seg_update(node*2+1,mid+1,end,idx,val);
    tree[node]=tree[node*2]+tree[node*2+1];
}

ll query(int a, int b){
    ll ans=0;
    while (head[a]!=head[b]){
        if (depth[head[a]]>depth[head[b]]) swap(a,b);
        ans+=seg_query(1,1,n,pos[head[b]],pos[b]);
        b=p[head[b]];
    }
    if (depth[a]>depth[b]) swap(a,b);
    ans+=seg_query(1,1,n,pos[a],pos[b]);
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ms(heavy,-1);
    depth[1]=1, dfs(1);
    decomp(1,1);
    int q; cin >> q; char cmd;
    for (int i=1,a,b;i<=q;++i){
        cin >> cmd >> a >> b;
        if (cmd=='Q') cout << query(a,b)-val[a]-val[b] << '\n';;
        if (cmd=='T') seg_update(1,1,n,pos[a],b), val[a]=b;
    }
}