#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1,MAXM=5e5+1;

int arr[MAXN]; double dp[MAXM], tot; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    for (int i=1;i<MAXM;++i) dp[i]=-1;
    if (arr[1]==arr[n]){ cout << 1 << '\n'; return 0; }
    dp[arr[1]]=1; dp[arr[n]]=0;
    for (int i=n-1;i>=2;--i){
        double &curr=dp[arr[i]];
        if (!(curr<0)){ tot+=curr; continue; }
        curr=(tot+1)*(1.0/(n-i+1));
        tot+=curr;
    }
    cout << setprecision(9) << (1.0/n)*(tot+1) << '\n';

}