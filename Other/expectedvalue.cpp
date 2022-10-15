#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=998244353,seed=131,MAXN=1001;

ll x,t1,t2,frac;
ll ans[MAXN][MAXN], p[MAXN][MAXN][2]; // 0 is left, 1 is down

ll fpow(ll x, int expo){
    ll ans=1;
    while (expo>0){
        if (1&expo) ans*=x, ans%=mod;
        x*=x, x%=mod;
        expo>>=1;
    }
    return ans;
}

ll inv(ll x){
    return fpow(x,mod-2);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int a,b; cin >> a >> b;
    frac=a*inv(b); frac%=mod;
    p[1][1][0]=frac, p[1][1][1]=(1-frac+mod)%mod;
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin >> x;
            if (i==1&&j==1){ ans[i][j]=x; continue; }
            t1=inv((p[i-1][j][1]+p[i][j-1][0])%mod);
            ans[i][j]+=ans[i-1][j]*((p[i-1][j][1]*t1)%mod); ans[i][j]%=mod;
            ans[i][j]+=ans[i][j-1]*((p[i][j-1][0]*t1)%mod); ans[i][j]%=mod;
            t1=p[i][j][0]=p[i][j-1][0]; t2=p[i][j][1]=p[i-1][j][1];
            ans[i][j]+=x; ans[i][j]%=mod;
            t1*=(frac)%mod; t1%=mod; t2*=(frac)%mod; t2%=mod;
            p[i][j][0]+=t2-t1+mod; p[i][j][0]%=mod;
            p[i][j][1]+=t1-t2+mod; p[i][j][1]%=mod;
            if (i==n) p[i][j][0]+=p[i][j][1], p[i][j][0]%=mod;
            if (j==n) p[i][j][1]+=p[i][j][0], p[i][j][1]%=mod;
        }
    }
    cout << ans[n][n] << '\n';
}