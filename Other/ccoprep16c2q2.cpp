#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define is(n,pos) (n&(1<<pos))
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=100'001;
int dp[MAXN+1];
int arr[32];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    int ans=-1;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        for (int k=0;k<=31;++k){
            if(is(a,k)){
                dp[i]=max(dp[i],dp[arr[k]]+1);
            }
        }
        for (int k=0;k<=31;++k){
            if(is(a,k)){
                if (dp[i]>=dp[arr[k]]) arr[k]=i;
            }
        }
        ans=max(ans,dp[i]);
    }
    cout << ans << '\n';
}