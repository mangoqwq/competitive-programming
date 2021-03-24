#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=1e5+5,mn=1e6+1,mm=1e6;

struct Line{
    ll m, b;
    ll eval(ll x){ return m*x+b; }
} t[4*mn];
ll h[MAXN], w[MAXN], tot, dp;

void Insert(int node, int start, int end, Line x){
    int mid=(start+end)>>1;
    bool l=x.eval(start)<t[node].eval(start);
    bool m=x.eval(mid)<t[node].eval(mid);
    if (m) swap(x,t[node]);
    if (start==end) return;
    if (l^m) Insert(node*2,start,mid,x);
    else Insert(node*2+1,mid+1,end,x);
}

ll Query(int node, int start, int end, int idx){
    int mid=(start+end)>>1;
    if (start==end) return t[node].eval(idx);
    if (idx<=mid) return min(t[node].eval(idx),Query(node*2,start,mid,idx));
    else return min(t[node].eval(idx),Query(node*2+1,mid+1,end,idx));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<4*mn;++i) t[i]={(ll)1e12,(ll)1e12};
    for (int i=1;i<=n;++i) cin >> h[i];
    for (int i=1;i<=n;++i) cin >> w[i];
    Insert(1,0,mm,{-2*h[1],h[1]*h[1]-w[1]}); tot=w[1];
    for (int i=2;i<=n;++i){
        dp=Query(1,0,mm,h[i])+h[i]*h[i]+tot;
        tot+=w[i];
        Insert(1,0,mm,{-2*h[i],dp-tot+h[i]*h[i]});
    }
    cout << dp << '\n';
}