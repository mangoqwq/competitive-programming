#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+5;

int a[MAXN], nxt[MAXN], seen[MAXN];
ll ans;
struct Fenwick{
    int a[MAXN], ret;
    void ins(int i){ for (;i<MAXN;i+=i&-i) a[i]++; }
    int qry(int i){
        for (ret=0;i;i-=i&-i) ret+=a[i];
        return ret;
    }
    int qry(int l, int r){ return qry(r)-qry(l-1); }
} bit;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i) seen[i]=n+1;
    for (int i=n;i>=1;--i){
        nxt[i]=seen[a[i]];
        seen[a[i]]=i;
    }
    for (int i=1;i<=n;++i) if (seen[a[i]]==i) bit.ins(i);
    for (int i=1;i<=n;++i){
        ans+=bit.qry(i+1,nxt[i]-1);
        bit.ins(nxt[i]);
    }
    cout << ans << '\n';
}