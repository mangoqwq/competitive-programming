#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll tree1[4000000];
ll tree2[4000000];
ll lazy1[4000000];
ll lazy2[4000000];

ll f(int y,int x){
    return ((x*(x+1))/2)-(((y-1)*y)/2);
}

void update1(int node, int start, int end, int l, int r, int val){
    if (lazy1[node]!=0){
        tree1[node]+=(start-end+1)*lazy1[node];
        if (start!=end){
            lazy1[node*2]+=lazy1[node];
            lazy1[node*2+1]+=lazy1[node];
        }
        lazy1[node]=0;
    }
    if (start>r||end<l){
        return;
    }
    if (start>=l&&end<=r){
        tree1[node]+=(start-end+1)*val;
        if (start!=end){
            lazy1[node*2]+=val;
            lazy1[node*2+1]+=val;
        }
        return;
    }
    int mid=(start+end)/2;
    update1(node*2,start,mid,l,r,val);
    update1(node*2+1,mid+1,end,l,r,val);
    tree1[node]=tree1[node*2]+tree1[node*2+1];
}
void update2(int node, int start, int end, int l, int r, int val){
    if (lazy2[node]!=0){
        tree2[node]+=(f(start,end))*lazy2[node];
        if (start!=end){
            lazy2[node*2]+=lazy2[node];
            lazy2[node*2+1]+=lazy2[node];
        }
        lazy2[node]=0;
    }
    if (start>r||end<l){
        return;
    }
    if (start>=l&&end<=r){
        tree2[node]+=(f(start,end))*val;
        if (start!=end){
            lazy2[node*2]+=val;
            lazy2[node*2+1]+=val;
        }
        return;
    }
    int mid=(start+end)/2;
    update2(node*2,start,mid,l,r,val);
    update2(node*2+1,mid+1,end,l,r,val);
    tree2[node]=tree2[node*2]+tree2[node*2+1];
}
ll query1(int node, int start, int end, int l, int r){
    if (start>r||end<l){
        return 0;
    }
    if (lazy1[node]!=0){
        tree1[node]+=(start-end+1)*lazy1[node];
        if (start!=end){
            lazy1[node*2]+=lazy1[node];
            lazy1[node*2+1]+=lazy1[node];
        }
        lazy1[node]=0;
    }
    if (start>=l&&end<=r){
        return tree1[node];
    }
    int mid=(start+end)/2;
    return query1(node*2,start,mid,l,r)+query1(node*2+1,mid+1,end,l,r);

}
ll query2(int node, int start, int end, int l, int r){
    if (start>r||end<l){
        return 0;
    }
    if (lazy2[node]!=0){
        tree2[node]+=(f(start,end))*lazy2[node];
        if (start!=end){
            lazy2[node*2]+=lazy2[node];
            lazy2[node*2+1]+=lazy2[node];
        }
        lazy2[node]=0;
    }
    if (start>=l&&end<=r){
        return tree2[node];
    }
    int mid=(start+end)/2;
    return query2(node*2,start,mid,l,r)+query2(node*2+1,mid+1,end,l,r);
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=0,a,b,c,d;i<q;++i){
        cin >> a;
        if (a==1){
            cin >> b >> c >> d;
            update1(1,1,n,b,c,(1-b)*d);
            update2(1,1,n,b,c,d);
        }
        else if (a==2){
            cin >> b >> c;
            cout << query1(1,1,n,b,c) + query2(1,1,n,b,c) << '\n';
        }
    }
}