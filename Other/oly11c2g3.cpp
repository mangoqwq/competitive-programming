#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// Heavy light decomposition

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=100'001;

int n,q;
vector<int> graph[MAXN];
int in[MAXN],out[MAXN],t;
int parent[MAXN],heavy[MAXN],head[MAXN];
int tree[MAXN*4],lazy[MAXN*4];

void push_down(int node, int start, int end){
    if (!lazy[node]) return;
    tree[node]+=lazy[node];
    if (start!=end){
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;
}

void seg_update(int node, int start, int end, int l, int r,int val){
    if (l>end||r<start) return;
    if (start>=l&&end<=r){
        lazy[node]+=val;
        return;
    }
    int mid=(start+end)/2;
    seg_update(node*2,start,mid,l,r,val);
    seg_update(node*2+1,mid+1,end,l,r,val);
}

int seg_query(int node, int start, int end, int index){
    push_down(node,start,end);
    if (start==end) return tree[node];
    int mid=(start+end)/2;
    if (index<=mid) return seg_query(node*2,start,mid,index);
    else return seg_query(node*2+1,mid+1,end,index);
}

bool is_ancestor(int a, int b){
    return in[a]<=in[b]&&out[a]>=out[b];
}

int dfs(int node){
    int size=1;
    int maximum=0;
    for (int c:graph[node]){
        if (c==parent[node]) continue;
        parent[c]=node;
        int temp=dfs(c);
        size+=temp;
        if (temp>maximum){
            heavy[node]=c; maximum=temp;
        }
    }
    return size;
}

void decomp(int node, int h){
    in[node]=++t;
    head[node]=h;
    if (heavy[node]!=-1){
        decomp(heavy[node],h);
    }
    for (int c:graph[node]){
        if (c==parent[node]||c==heavy[node]) continue;
        decomp(c,c);
    }
    out[node]=t;
}

void update(int a,int b){
    while(head[a]!=head[b]){
        if (is_ancestor(head[b],head[a])) swap(a,b);
        seg_update(1,1,n,in[head[b]],in[b],1);
        b=parent[head[b]];
    }
    if (is_ancestor(b,a)) swap(a,b);
    seg_update(1,1,n,in[a],in[b],1);
    seg_update(1,1,n,in[a],in[a],-1);
}

int query(int a,int b){
    if (is_ancestor(b,a)) swap(a,b);
    return seg_query(1,1,n,in[b]);
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i=0,a,b;i<n-1;++i){
        cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    ms(heavy,-1);
    dfs(1);
    decomp(1,1);

    char op;
    for (int _=0,a,b;_<q;++_){
        cin >> op >> a >> b;
        if (op=='P'){
            update(a,b);
        }
        if (op=='Q'){
            cout << query(a,b) << '\n';
        }
    }
}