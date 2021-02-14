#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1, MAXM=20;

ll p2[MAXN], cnt[(1<<MAXM)], ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    p2[0]=1;
    for (int i=1;i<=n;++i) p2[i]=p2[i-1]*2%mod;
    for (int i=1;i<=n;++i){
        int tmp=0, k; cin >> k;
        for (int j=1,a;j<=k;++j) cin >> a, tmp+=p2[a-1];
        cnt[tmp]++;
    }
    for (int i=0;i<m;++i)
        for (int j=(1<<m)-1;j;j--)
            if ((j>>i)&1) cnt[j]+=cnt[j-p2[i]];
    for (int i=0;i<(1<<m);++i)
        ans+=((m-__builtin_popcount(i))%2?-1:1)*p2[cnt[i]];
    
    cout << (ans%mod+mod)%mod << '\n';
}