#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1001;

int n; int arr[10];
string k;
ll dp[MAXN][(1<<10)][2];

ll solve(int pos, int mask, int zero, bool flag){
    ll &curr=dp[pos][mask][flag];
    if (curr!=-1) return curr;
    if (pos==k.size()){
        bool ans=1;
        for (int i=0;i<n;++i) ans&=(1&(mask>>arr[i]));
        return curr=ans;
    }
    int lim=(flag?k[pos]-'0':9);
    curr=0;
    for (int i=0;i<=lim;++i){
        curr+=solve(pos+1,(zero&&(i==0)?mask:mask|(1<<i)),zero&(i==0),flag&(i==lim));
        curr%=mod;
    }
    return curr;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=0;i<n;++i) cin >> arr[i];
    cin >> k; ms(dp,-1);
    cout << solve(0,0,1,1)+(n==1&&arr[0]==0) << '\n';
}