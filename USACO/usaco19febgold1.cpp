#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=100001;

int n,q;
vector<int> graph[MAXN];
int parent[MAXN],heavy[MAXN],head[MAXN],in[MAXN],out[MAXN],t;
int tree[4*MAXN];

void seg_update(int node, int start, int end, int index, int value){
    if (start==end){
        tree[node]=value;
        return;
    }
    int mid=(start+end)/2;
    if (index<=mid) seg_update(node*2,start,mid,index,value);
    else seg_update(node*2+1,mid+1,end,index,value);
    tree[node]=tree[node*2]^tree[node*2+1];
}
int seg_query(int node, int start, int end, int l, int r){
    if (l>end||r<start) return 0;
    if (start>=l&&end<=r) return tree[node];
    int mid=(start+end)/2;
    return seg_query(node*2,start,mid,l,r)^seg_query(node*2+1,mid+1,end,l,r);
}
bool is_ancestor(int a,int b){
    return in[a]<=in[b]&&out[a]>=out[b];
}
int dfs(int node){
    int size=1;
    int maxsize=0;
    for (int c:graph[node]){
        if (c==parent[node]) continue;
        parent[c]=node;
        int temp=dfs(c);
        size+=temp;
        if (temp>maxsize){
            maxsize=temp; heavy[node]=c;
        }
    }
    return size;
}
void decomp(int node,int h){
    in[node]=++t; head[node]=h;
    if (heavy[node]!=-1){
        decomp(heavy[node],h);
    }
    for (int c:graph[node]){
        if (c==parent[node]||c==heavy[node]) continue;
        decomp(c,c);
    }
    out[node]=t;
}
void update(int node,int v){
    seg_update(1,1,n,in[node],v);
}
int query(int a, int b){
    int ans=0;
    while (head[a]!=head[b]){
        if (is_ancestor(head[b],head[a])) swap(a,b);
        ans^=seg_query(1,1,n,in[head[b]],in[b]);
        b=parent[head[b]];
    }
    if (is_ancestor(b,a)) swap(a,b);
    ans^=seg_query(1,1,n,in[a],in[b]);
    return ans;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    vector<int> sad;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        sad.push_back(a);
    }
    for (int i=0,a,b;i<n-1;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    ms(heavy,-1);
    dfs(1);
    decomp(1,1);
    for (int i=1;i<=n;++i){
        update(i,sad[i-1]);
    }

    for (int i=0,op,a,b;i<q;++i){
        cin >> op >> a >> b;
        if (op==1){
            update(a,b);
        }
        else{
            cout << query(a,b) << '\n';
        }
    }
}