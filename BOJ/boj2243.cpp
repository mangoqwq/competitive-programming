#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define mid ((l+r)>>1)
#define lc (v+1)
#define rc (v+2*(mid-l+1))
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

struct Query{ int a, b, c; } q[MAXN];
map<int,int> m; int n, p;
int unm[MAXN];
int st[2*MAXN];

void upd(int idx, int val, int v=1, int l=1, int r=n){
    if (l==r) return void(st[v]+=val);
    if (idx<=mid) upd(idx,val,lc,l,mid);
    else upd(idx,val,rc,mid+1,r);
    st[v]=st[lc]+st[rc];
}

int qry(int idx, int v=1, int l=1, int r=n){
    if (l==r) return l;
    if (idx<=st[lc]) return qry(idx,lc,l,mid);
    else return qry(idx-st[lc],rc,mid+1,r);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i){
        int a, b, c; cin >> a;;
        if (a==1) cin >> b;
        if (a==2) cin >> b >> c;
        if (a==2) m[b]=0;
        q[i]={a,b,c};
    }
    for (auto &x:m) x.second=++p, unm[p]=x.first;
    for (int i=1;i<=n;++i){
        if (q[i].a==2) q[i].b=m[q[i].b];
    }
    for (int i=1;i<=n;++i){
        auto [a,b,c]=q[i];
        if (a==1){
            int ans=qry(b);
            cout << unm[ans] << '\n';
            upd(ans,-1);
        }
        if (a==2){
            upd(b,c);
        }
    }
}