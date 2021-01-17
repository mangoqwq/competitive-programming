#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define is_set(x,idx) 1&(x>>idx)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=21,L=1<<21;

int dp[L];
bool yes[MAXN][MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;++i){
        for (int k=0;k<n;++k){
            cin >> yes[i][k];
        }
    }
    dp[0]=1;
    int cnt;
    for (int curr=0;curr<(1<<n);++curr){
        cnt=__builtin_popcount(curr);
        for (int i=0;i<n;++i){
            if (!(is_set(curr,i))&&yes[cnt][i]){
                dp[curr+(1<<i)]+=dp[curr];
                dp[curr+(1<<i)]%=mod;
            }
        }
    }
    cout << dp[(1<<n)-1] << '\n';
}