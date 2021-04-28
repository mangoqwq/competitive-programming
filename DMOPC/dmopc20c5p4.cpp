#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int seed=131, mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

unordered_map<ll,int> mp;
ll pows[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int g[max(n,m)+1][min(n,m)+1]={0};
    if (m>n){
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                char a; cin >> a;
                g[j][i]=a=='B';
            }
        }
        swap(n,m);
    }
    else{
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                char a; cin >> a;
                g[i][j]=a=='B';
            }
        }
    }
    pows[0]=1;
    for (int i=1;i<=m;++i) pows[i]=pows[i-1]*seed%mod;

    ll hr[n+1][m+1]={0};
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            hr[i][j]=(hr[i][j-1]*seed+g[i][j])%mod;
        }
    }
    ll ans=0;
    for (int l=1;l<=m;++l){
        for (int r=l+1;r<=m;++r){
            mp.clear();
            for (int i=1;i<=n;++i){
                if (g[i][l]!=g[i][r]) mp.clear();
                else{
                    ll hsh=(hr[i][r]-hr[i][l-1]*pows[r-l+1]%mod+mod)%mod;
                    ans+=mp[hsh];
                    mp[hsh]++;
                }
            }
        }
    }
    cout << ans << '\n';
}