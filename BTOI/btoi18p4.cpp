#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

struct Item{ int l,r; } arr[MAXN];
int pre[MAXN],tree[4*MAXN],lazy[MAXN];
bool ans[MAXN];

void push(int node, int start, int end){
    if (lazy[node]==0) return;
    tree[node]+=lazy[node];
    if (start!=end){
        lazy[node*2]+=lazy[node];
        lazy[node*2+1]+=lazy[node];
    }
    lazy[node]=0;
}

void update(int node, int start, int end, int l, int r, int val){
    if (start>r||end<l) return;
    push(node,start,end);
    if (start>=l&&end<=r){
        if (start!=end) lazy[node*2]+=val, lazy[node*2+1]+=val;
        tree[node]+=val;
    }
    else{
        int mid=(start+end)/2;
        update(node*2,start,mid,l,r,val);
        update(node*2+1,mid+1,end,l,r,val);
        tree[node]=min(tree[node*2],tree[node*2+1]);
    }
}

bool query(int node, int start, int end, int l, int r){
    if (start>r||end<l) return 0;
    push(node,start,end);
    if (start>=l&&end<=r) return tree[node]==0;
    int mid=(start+end)/2;
    return query(node*2,start,mid,l,r)|query(node*2+1,mid+1,end,l,r);
}

int print(int node, int start, int end, int l, int r){
    if (r>end||l<start) return 0;
    push(node,start,end);
    if (l>=start&&r<=end) return tree[node]==0;
    int mid=(start+end)/2;
    return query(node*2,start,mid,l,r)+query(node*2+1,mid+1,end,l,r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i=1,a,b;i<=m;++i){
        cin >> a >> b;
        arr[i]={a,b};
        if (b<a) pre[1]++, pre[b+1]--, pre[a]++;
        else pre[a]++, pre[b+1]--;
    }
    for (int i=1;i<=n;++i){
        pre[i]+=pre[i-1];
        update(1,1,n,i,i,pre[i]-1);
    }
    ms(pre,0); bool flag=0;
    for (int i=1,a,b;i<=m;++i){
        a=arr[i].l, b=arr[i].r; flag=0;
        if (b<a){
            if (query(1,1,n,1,b)|query(1,1,n,a,n)) ans[i]^=1, flag=1;
            else update(1,1,n,1,b,-1), update(1,1,n,a,n,-1);
        }
        else{
            if (query(1,1,n,a,b)) ans[i]^=1, flag=1;
            else update(1,1,n,a,b,-1);
        }
        if (!flag){
            if (b<a) pre[1]++, pre[b+1]--, pre[a]++;
            else pre[a]++, pre[b+1]--;
        }
    }
    for (int i=1;i<=n;++i){
        pre[i]+=pre[i-1];
        if (pre[i]==0){ cout << "impossible" << '\n'; return 0; }
    }
    for (int i=1;i<=m;++i) cout << ans[i];
    cout << '\n';

}