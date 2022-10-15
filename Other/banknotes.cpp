#include <bits/stdc++.h>

using namespace std;
int dp[20001];
int used[20001];
int val[201];

int main(){
    int n; cin >> n;
    for (int i=1,a;i<n+1;++i){
        cin >> a;
        val[i]=a;
    }
    memset(dp,0x3f,sizeof dp);
    dp[0]=1;
    for (int item=1,has;item<n+1;++item){
        cin >> has;
        memset(used,0,sizeof used);
        if (has==1){
            for (int i=20000;i>=val[item];--i){
                dp[i]=min(dp[i],dp[i-val[item]]+1);
            }
            continue;
        }
        for (int i=val[item];i<20001;++i){
            if (dp[i-val[item]]!=0x3f3f3f3f){
                if (used[i-val[item]]+1<=has && dp[i-val[item]]+1<=dp[i]){
                    dp[i]=dp[i-val[item]]+1;
                    used[i]=used[i-val[item]]+1;
                }
            }
        }
    }
    int k; cin >> k;
    cout << dp[k]-1 << '\n';
    
}