#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e4+1;

bool arr[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i=0,a,b,c,d;i<m;++i){
        cin >> a >> b >> c >> d;
        c+=a; d+=b;
        a++; b++;
        arr[a][b]^=1; arr[a][d+1]^=1;
        arr[c+1][b]^=1; arr[c+1][d+1]^=1;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            arr[i][j]^=arr[i-1][j];
        }
    }
    ll ans=0;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            arr[i][j]^=arr[i][j-1];
            ans+=arr[i][j];
        }
    }
    cout << ans << '\n';
}