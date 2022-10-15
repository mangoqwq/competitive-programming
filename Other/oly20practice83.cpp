#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=(1<<16);

int arr[16];
ll dp[MAXN][16];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,K; cin >> n >> K;
    for (int i=0;i<n;++i) cin >> arr[i];
    for (int i=0;i<n;++i){
        dp[(1<<i)][i]=1;
    }
    for (int curr=0;curr<(1<<n);++curr){
        for (int i=0;i<n;++i){
            if (!(1&(curr>>i))) continue;
            for (int k=0;k<n;++k){
                if (abs(arr[i]-arr[k])>K && (!(1&(curr>>k))) ){
                    dp[(curr)|(1<<k)][k]+=dp[curr][i];
                }
            }
        }
    }
    ll ans=0;
    for (int i=0;i<n;++i){
        //cout << i << " -> " << dp[(1<<n)-1][i] << '\n';
        ans+=dp[(1<<n)-1][i];
    }
    cout << ans << '\n';
}