#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e5+1;

int n, ans=0;
int st[4*MAXN], lz[4*MAXN], arr[MAXN];

void upd(int val, int ql, int qr=n, int v=1, int l=1, int r=n){
    if (l!=r)
        st[v*2]+=lz[v], lz[v*2]+=lz[v],
        st[v*2+1]+=lz[v], lz[v*2+1]+=lz[v];
    lz[v]=0;
    if (l>qr||r<ql) return;
    if (l>=ql&&r<=qr){ lz[v]+=val, st[v]+=val; return; }
    int mid=l+r>>1;
    upd(val,ql,qr,v*2,l,mid), upd(val,ql,qr,v*2+1,mid+1,r);
    st[v]=min(st[v*2],st[v*2+1]);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        upd(1,arr[i]);
        if (i%2==1) continue;
        upd(-2,arr[i/2]);
        if (st[1]>=0) ans=i/2;
    }
    cout << ans << '\n';
}