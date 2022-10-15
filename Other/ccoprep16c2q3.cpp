#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1, SZ=500;

int n, q;
int val[MAXN], nxt[MAXN], cnt[MAXN];

void upd(int i, int v){
    val[i]=v;
    for (int x=i;x>=i/SZ*SZ;--x){
        if (x+val[x]>=x/SZ*SZ+SZ||x+val[x]>=n) cnt[x]=1, nxt[x]=x+val[x];
        else cnt[x]=cnt[x+val[x]]+1, nxt[x]=nxt[x+val[x]];
    }
}

int qry(int x){
    int ret=0;
    while (x<n) ret+=cnt[x], x=nxt[x];
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0;i<n;++i) cnt[i]=SZ-i/SZ, nxt[i]=i+cnt[i], val[i]=1;
    for (int i=n-1;i>=(n-1)/SZ*SZ;--i) cnt[i]=n-i, nxt[i]=n; 
    for (int i=0,a;i<n;++i) cin >> a, upd(i,a);
    cin >> q;
    while (q--){
        int op, x, v;
        cin >> op;
        if (op==1) cin >> x, cout << qry(x) << '\n';
        if (op==2) cin >> x >> v, upd(x,v);
    }
}