#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9,seed=131,MAXN=21;

vector<int> arr[MAXN];
ll dp[MAXN][MAXN]; // count number of pairs that lie between l and r
ll power[401];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    power[0]=1;
    for (int i=1;i<=400;++i){
        power[i]=power[i-1]*2;
        power[i]%=mod;
    }
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        for (int k=i+1;k<=n;++k){
            for (int l=i;l<=k;++l){
                for (int r=l+1;r<=k;++r){
                    if (__gcd(l,r)==1) dp[i][k]++;
                }
            }
        }
    }
    ll ans=0,temp;
    int pl;
    for (int curr=0;curr<(1<<(n));++curr){
        if (1&curr) continue;
        pl=1; temp=1;
        for (int pr=1;pr<n;++pr){
            if (1&(curr>>(pr))) temp*=power[dp[pl][pr]],temp%=mod,pl=pr+1;
        }
        temp*=power[dp[pl][n]], temp%=mod;
        ans+=(__builtin_popcount(curr)%2==0?temp:-temp)+mod, ans%=mod;
    }
    cout << ans << '\n';
}