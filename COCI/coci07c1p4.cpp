#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define is(idx) (uwu[idx]=='?')
#define isfront(idx) (uwu[idx]=='('||uwu[idx]=='{'||uwu[idx]=='[')
#define isback(idx) (uwu[idx]==')'||uwu[idx]=='}'||uwu[idx]==']')
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e5,seed=131,MAXN=205;

int n; string uwu;
ll dp[MAXN][MAXN];

bool valid(int l, int r){
    return (uwu[l]=='{'&&uwu[r]=='}') || (uwu[l]=='('&&uwu[r]==')') || (uwu[l]=='['&&uwu[r]==']');
}

bool ree=false;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> uwu;
    for (int i=1;i<=n+3;++i) dp[i][i-1]=1;
    for (int len=1;len<n;len+=2){
        for (int l=0,r=len;r<n;++l,++r){
            for (int i=l+1;i<=r;i+=2){
                if (is(l)&&is(i)) dp[l][r]+=(ll)3*dp[l+1][i-1]*dp[i+1][r];
                else if (valid(l,i)||(isfront(l)&&is(i))||(is(l)&&isback(i))) dp[l][r]+=dp[l+1][i-1]*dp[i+1][r];
            }
            dp[l][r]%=1'000'000;
        }
    }
    if (dp[0][n-1]>mod) cout << setw(5) << setfill('0') << dp[0][n-1]%mod << '\n';
    else cout << dp[0][n-1]%mod << '\n';
}