#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll lazy[800000];
ll tree[800000];

void update(int node, int start, int end, int l, int r, int val){
    if (lazy[node]){
        tree[node]+=lazy[node];
        if (start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if (start>r || end<l || start>end){
        return;
    }
    if (start>=l && end<=r){
        tree[node]+=val;
        if (start!=end){
            lazy[node*2]+=val;
            lazy[node*2+1]+=val;
        }
        return;
    }
    int mid=(start+end)/2;
    update(node*2,start,mid,l,r,val);
    update(node*2+1,mid+1,end,l,r,val);
    tree[node]=max(tree[node*2],tree[node*2+1]);
}

ll query(int node, int start, int end, int l, int r){
    if (start>r || end<l || start>end){
        return -1;
    }
    if (lazy[node]){
        tree[node]+=lazy[node];
        if (start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if (start>=l && end<=r){
        return tree[node];
    }
    int mid=(start+end)/2;
    return max(query(node*2,start,mid,l,r),query(node*2+1,mid+1,end,l,r));
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,k,q; cin >> n >> k >> q;
    int a,b,c;
    for (int _=0;_<q;++_){
        cin >> a >> b >> c;
        if (a==0){
            update(1,0,n-1,max(0,b-k+1),b,c);
        }
        else if (a==1){
            cout << query(1,0,n-1,b,c) << '\n';
        }
    }
}