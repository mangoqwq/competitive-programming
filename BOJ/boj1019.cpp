#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=11;

int n; string s;
int dp[MAXN][2][2], cnt[MAXN], p10[MAXN+1];

int solve(int i, bool flag, bool zero, int c){
    int &curr=dp[i][flag][zero];
    if (curr!=-1) return curr;
    curr=0;
    if (i==n){
        if (flag&&zero) return curr=(c!=0&&c<=s[i]);
        if (flag) return curr=(c<=s[i]);
        if (zero) return curr=(c!=0);
        return curr=1;
    }
    int r=(flag?s[i]:9);
    for (int j=0;j<=r;++j){
        curr+=solve(i+1,flag&(j==s[i]),zero&(j==0),c);
        if (!(zero&&j==0)&&j==c){
            if (flag&(j==s[i])) curr+=cnt[i+1]+1;
            else curr+=p10[i+1];
        }
    }
    return curr;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> s; n=s.size(); s=" "+s;
    for (int i=1;i<=n;++i) cnt[i]=stoi(s.substr(i));
    p10[n+1]=1;
    for (int i=n;i>=2;--i) p10[i]=p10[i+1]*10;
    for (int i=1;i<=n;++i){ s[i]=s[i]-'0'; }
    for (int i=0;i<=9;++i){
        ms(dp,-1);
        cout << solve(1,1,1,i) << " ";
    }
}