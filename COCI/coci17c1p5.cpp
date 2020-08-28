#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

int tree[MAXN*4];

void update(int node, int start, int end, int index, int val){
    if (start==end){ tree[node]=val; return; }
    int mid=(start+end)/2;
    if (index<=mid) update(node*2,start,mid,index,val);
    if (index>mid) update(node*2+1,mid+1,end,index,val);
    tree[node]=min(tree[node*2],tree[node*2+1]);
}

int query(int node, int start, int end, int stop, int l, int r){
    if (tree[node]>stop||end<l||start>r) return 0x3f3f3f3f;
    if (start>=l&&end<=r){
        while (start!=end){
            if (tree[node*2]<=stop) end=(start+end)/2, node=node*2;
            else start=(start+end)/2+1, node=node*2+1;
        }
        return start;
    }
    else{
        int mid=(start+end)/2;
        return min(query(node*2,start,mid,stop,l,r),query(node*2+1,mid+1,end,stop,l,r));
    }

}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q; ms(tree,0x3f);
    char op; int a,b,ans;
    for (int qq=0;qq<q;++qq){
        cin >> op >> a >> b;
        if (op=='M') update(1,1,n,b,a); 
        if (op=='D') ans=query(1,1,n,a,b,n), cout << ((ans==0x3f3f3f3f)?-1:ans) << '\n'; 
    }
}