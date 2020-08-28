#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

int arr[MAXN], cnt[MAXN], best;
double ans, dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int k,n; cin >> k >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1;i<=n;++i){
        for (int j=i;j>0;--j){
            cnt[arr[j]]++;
            if (cnt[arr[j]]>cnt[best]) best=arr[j];
            dp[i]=max(dp[i],dp[j-1]+pow(sqrt(cnt[best]),k));
        }
        for (int j=i;j>0;--j) cnt[arr[j]]=0;
    }
    cout << setprecision(15) << dp[n] << '\n';
}