#include <bits/stdc++.h>

using namespace std;
int tree[800000],lazy[800000];
int mod,N,queries;


void update(int node, int start, int end, int l, int r, int value){
    if (lazy[node]!=0){
        tree[node]+=(end-start+1)*lazy[node];
        tree[node]%=mod;
        if (start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2]%=mod;
            lazy[node*2+1]+=lazy[node];
            lazy[node*2+1]%=mod;
        }
        lazy[node]=0;
    }
    if (start > end || start > r || end < l){
        return;
    }
    if (start>=l && end<=r){
        tree[node]+=(end-start+1)*value;
        tree[node]%=mod;
        if (start!=end){
            lazy[node*2]+=value;
            lazy[node*2]%=mod;
            lazy[node*2+1]+=value;
            lazy[node*2+1]%=mod;
        }
        return;
    }
    int mid = (start+end)/2;
    update(node*2,start,mid,l,r,value); update(node*2+1,mid+1,end,l,r,value);
    tree[node]=tree[node*2]+tree[node*2+1];
    tree[node]%=mod;

}

int getsum(int node, int start, int end, int l, int r){
    if (start > end || start > r || end < l){
        return 0;
    }
    if (lazy[node]!=0){
        tree[node]+=(end-start+1)*lazy[node];
        tree[node]%=mod;
        if (start!=end){
            lazy[node*2]+=lazy[node];
            lazy[node*2]%=mod;
            lazy[node*2+1]+=lazy[node];
            lazy[node*2+1]%=mod;
        }
        lazy[node]=0;
    }
    if (start>=l&&end<=r){
        tree[node]%=mod;
        return tree[node];
    }
    int mid=(start+end)/2;
    int leftnode=getsum(node*2,start,mid,l,r)%mod;
    int rightnode=getsum(node*2+1,mid+1,end,l,r)%mod;
    return (leftnode+rightnode)%mod;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    cin >> mod >> N >> queries;
    int operation,l,r,x,temp;
    for (int i=1;i<N+1;++i){
        cin >> temp;
        update(1,1,N,i,i,temp%mod);
    }
    
    for (int _=0;_<queries;++_){
        cin >> operation;
        //for (int i=0;i<20;++i){cout<<tree[i] << " ";} cout << '\n';
        //for (int i=0;i<20;++i){cout<<lazy[i] << " ";} cout << '\n';
        if (operation==1){
            cin>>l>>r>>x;
            update(1,1,N,l,r,x%mod);
            
        }
        if (operation==2){
            cin>>l>>r;
            cout<<getsum(1,1,N,l,r) << '\n';
        }
        
    }
}