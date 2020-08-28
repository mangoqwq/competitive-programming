#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=501;

int arr[MAXN],val[MAXN],dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k; cin >> n >> m >> k;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=0;i<=m;++i) cin >> val[i];
    for (int idx=1;idx<=n;++idx){
        int a=arr[idx];
        for (int i=500;i>=0;--i){
            for (int j=a;j<=m&&j-a<=i;++j){
                dp[i]=max(dp[i],dp[i-(j-a)]+val[j]);
            }
        }
    }
    cout << dp[k] << '\n';
}