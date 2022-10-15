#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5001;

bool dp[MAXN][MAXN][3];
int n; string s;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> s; 
    n=s.size(); s=" "+s;
    dp[0][0][0]=1;
    for (int idx=1;idx<s.size();++idx){
        bool left=s[idx]=='(';
        for (int i=0;i<=idx;++i){
            if (i-(left*2-1)>=0) dp[idx][i][0]=dp[idx-1][i-(left*2-1)][0];
            if (i+(left*2-1)>=0) dp[idx][i][1]=dp[idx-1][i+(left*2-1)][0]||dp[idx-1][i+(left*2-1)][1];
            if (i-(left*2-1)>=0) dp[idx][i][2]=dp[idx-1][i-(left*2-1)][1]||dp[idx-1][i-(left*2-1)][2];
        }
    }
    cout << (dp[n][0][0]||dp[n][0][1]||dp[n][0][2]?"possible":"impossible") << '\n';
}