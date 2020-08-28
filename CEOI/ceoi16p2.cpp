#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2001;

ll last[MAXN],dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,s,f; cin >> n >> s >> f;
    dp[0]=1;
    for (int i=1;i<=n-1;++i){
        swap(dp,last);
        for (ll j=0;j<=i;++j){
            dp[j]=0;
            if (i==s||i==f){
                dp[j]+=last[j]+last[j+1]*(j+1);
                dp[j]%=mod;
            }
            else{
                if (j!=0) dp[j]+=last[j-1];
                dp[j]+=last[j+1]*(j+1)*(j+(i>s)+(i>f));
                dp[j]%=mod;
            }
        }
    }
    cout << dp[0] << '\n';
}