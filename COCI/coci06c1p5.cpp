#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=(1<<20);

double p[20][20];
double dp[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;++i){
        for (int k=0;k<n;++k){
            cin >> p[i][k]; p[i][k]/=100;
        }
    }
    dp[0]=100;
    for (int curr=0;curr<(1<<n);++curr){
        int cnt=__builtin_popcount(curr);
        for (int i=0;i<n;++i){
            if (!(1&(curr>>i))) dp[curr+(1<<i)]=max(dp[curr+(1<<i)],dp[curr]*p[i][cnt]);
        }
    }
    cout << fixed << setprecision(9) << dp[(1<<n)-1] << '\n';
}