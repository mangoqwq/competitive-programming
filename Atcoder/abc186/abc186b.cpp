#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101;

int arr[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int h, w; cin >> h >> w;
    int mn=100;
    for (int i=1;i<=h;++i){
        for (int j=1;j<=w;++j){
            cin >> arr[i][j];
            mn=min(arr[i][j],mn);
        }
    }
    int ans=0;
    for (int i=1;i<=h;++i){
        for (int j=1;j<=w;++j){
            ans+=arr[i][j]-mn;
        }
    }
    cout << ans << '\n';
}