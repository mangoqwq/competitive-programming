#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=23;

map<char,int> id;
int cnt[MAXN][MAXN];
int dp[1<<MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string s; cin >> s;
    int n=s.size(); s="%"+s;
    int m=0;
    ms(dp,0x3f);
    for (int i=1;i<=n;++i){
        if (!id.count(s[i])) id[s[i]]=m++;
        s[i]=id[s[i]];
        if (s[i]!=s[i-1]&&s[i-1]!='%') cnt[s[i]][s[i-1]]++;
    }
    dp[0]=n;
    for (int mask=0;mask<(1<<m);++mask){
        for (int i=0;i<m;++i){
            if (1&(mask>>i)) continue;
            int curr=0;
            for (int j=0;j<m;++j) if (1&(mask>>j)) curr+=cnt[i][j];
            dp[mask+(1<<i)]=min(dp[mask+(1<<i)],dp[mask]-curr);
        }
    }
    cout << dp[(1<<m)-1] << '\n';
}