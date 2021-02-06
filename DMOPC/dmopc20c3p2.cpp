#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

map<ll,int> mp;
int a[MAXN][21];

ll hsh(ll a, ll b){
    return a*1e9+b;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int m, n, k; cin >> m >> n >> k;
    for (int i=1;i<=m;++i){
        for (int j=1;j<=n;++j){
            cin >> a[i][j];
        }
    }
    ll ans=0;
    for (int i=2;i<=n;++i){
        mp.clear();
        for (int j=1;j<=m;++j){
            if (mp.find(hsh(a[j][i]-k,a[j][i-1]-k))!=mp.end()){
                ans+=mp[hsh(a[j][i]-k,a[j][i-1]-k)];
            }
            if (mp.find(hsh(a[j][i]+k,a[j][i-1]+k))!=mp.end()){
                ans+=mp[hsh(a[j][i]+k,a[j][i-1]+k)];
            }
            mp[hsh(a[j][i],a[j][i-1])]++;
        }
    }
    cout << ans << '\n';
}