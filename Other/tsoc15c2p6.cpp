#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;

struct Node{
    ll v,lazy;
    int l,r;
}tree[120000];
ll arr[30000];
void build(int node, int start, int end){
    tree[node].l=start; tree[node].r=end;
    if (start==end){
        tree[node].v=arr[start];
        return;
    }
    int mid=(start+end)/2;
    build(node*2,start,mid);
    build(node*2+1,mid+1,end);
    tree[node].v=min(tree[node*2].v,tree[node*2+1].v);
}   
void push(int node){
    if (!tree[node].lazy) return;
    tree[node].v-=tree[node].lazy;
    if (tree[node].l==tree[node].r){
        tree[node].lazy=0;
        return;
    }
    tree[node*2].lazy+=tree[node].lazy;
    tree[node*2+1].lazy+=tree[node].lazy;
    tree[node].lazy=0;
}

void update(int node, int l, int r, ll val){
    push(node);
    if (tree[node].l>r||tree[node].r<l) return;
    if (tree[node].l>=l&&tree[node].r<=r){
        tree[node].lazy+=val;
        push(node);
        return;
    }
    update(node*2,l,r,val); update(node*2+1,l,r,val);
    tree[node].v=min(tree[node*2].v,tree[node*2+1].v);
}

ll query(int node, int l, int r){
    push(node);
    if (tree[node].l>r||tree[node].r<l) return 0x3f3f3f3f3f3f3f;
    if (tree[node].l>=l&&tree[node].r<=r){
        return tree[node].v;
    }
    return min(query(node*2,l,r),query(node*2+1,l,r));
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    int a,b,c;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
    }
    build(1,1,n);
    for (int i=0;i<q;++i){
        cin >> a >> b >> c;
        update(1,a,b,c);
        cout << max((ll)0,query(1,a,b)) << " " << max((ll)0,query(1,1,n)) << '\n';
    }
}