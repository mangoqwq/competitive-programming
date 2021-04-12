#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, inf=0x3f3f3f3f, MAXN=3e5+1;

ll p2[MAXN], skip[MAXN], even[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    p2[0]=skip[0]=1; skip[1]=p2[1]=2;
    for (int i=2;i<=n*m;++i){
        p2[i]=p2[i-1]*2%mod;
        skip[i]=(skip[i-2]+p2[i])%mod;
    }
    bool g[n+2][m+2]; ms(g,0);
    int hori[n+2][m+2], veri[n+2][m+2]; ms(hori,0); ms(veri,0);
    ll cnt=0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            char a; cin >> a;
            if (a=='o') cnt++, g[i][j]=1;
        }
    }
    ll ans=0, curr;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            if (!g[i][j]) continue;
            hori[i][j]=hori[i][j-1]+1;
            veri[i][j]=veri[i-1][j]+1;
            if (g[i][j]&&g[i][j-1]){
                ll b=hori[i][j];
                if (b%2==0){
                    curr=skip[cnt-3];
                    if (cnt>=b+1) curr=(curr-skip[cnt-(b+1)]+mod)%mod;
                    curr=(curr+p2[cnt-b]);
                }
                if (b%2==1){
                    curr=skip[cnt-3];
                    if (cnt>=b+2) curr=(curr-skip[cnt-(b+2)]+mod)%mod;
                }
                ans=(ans+(curr%mod+mod))%mod;
            }
            if (g[i][j]&&g[i-1][j]){
                ll b=veri[i][j];
                if (b%2==0){
                    curr=skip[cnt-3];
                    if (cnt>=b+1) curr=(curr-skip[cnt-(b+1)]+mod)%mod;
                    curr=(curr+p2[cnt-b]);
                }
                if (b%2==1){
                    curr=skip[cnt-3];
                    if (cnt>=b+2) curr=(curr-skip[cnt-(b+2)]+mod)%mod;
                }
                ans=(ans+(curr%mod+mod))%mod;
            }
        }
    }
    cout << ans << '\n';
}