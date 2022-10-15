#include <bits/stdc++.h>

// Li chao tree

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=1e6+5;

struct Line{
    ll m, b;
    ll eval(ll x){ return m*x+b; }
} tree[4*MAXN];
int n; 

void Insert(int node, int start, int end, Line x){
    int mid=(start+end)>>1;
    bool l=x.eval(start)>tree[node].eval(start);
    bool m=x.eval(mid)>tree[node].eval(mid);
    if (m) swap(tree[node],x);
    if (start==end) return;
    if (l^m) Insert(node*2,start,mid,x);
    else Insert(node*2+1,mid+1,end,x); 
}

ll Query(int node, int start, int end, int idx){
    if (start==end) return tree[node].eval(idx);
    int mid=(start+end)>>1;
    if (idx<=mid) return max(tree[node].eval(idx),Query(node*2,start,mid,idx));
    else return max(tree[node].eval(idx),Query(node*2+1,mid+1,end,idx));
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (ll i=1,a,h;i<=n;++i){
        cin >> a >> h;
        ll dp=Query(1,1,n+1,i);
        Insert(1,1,n+1,{-h,dp+a+h*i});
    }
    cout << Query(1,1,n+1,n+1) << '\n';
}