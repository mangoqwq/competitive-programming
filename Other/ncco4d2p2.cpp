#include <bits/stdc++.h>

using namespace std;
int value[100];
int has[100];
int dp[12001];
int visited[12001];

int main(){
    int n,t; cin >> n >> t;
    for (int i=0;i<n;++i){
        cin >> value[i];
    }
    for (int i=0;i<n;++i){
        cin >> has[i];
    }
    dp[0]=1;
    for (int k=0;k<n;++k){
        for (int i=value[k];i<12000;++i){
            if (dp[i-value[k]]){
                if (dp[i]==0&&visited[i-value[k]]<has[k]){
                    visited[i]=visited[i-value[k]]+1;
                    dp[i]=dp[i-value[k]]+1;
                }
                else if (dp[i-value[k]]+1<dp[i]&&visited[i-value[k]]<has[k]){
                    dp[i]=dp[i-value[k]]+1;
                }
                visited[i-value[k]]=0;
            }
        }
        
    }
    for (int k=0;k<n;++k){
        for (int i=12000-value[k];i>0;--i){
            if (dp[i+value[k]]){
                if (!dp[i]){
                    dp[i]=dp[i+value[k]]+1;
                }
                else{
                    dp[i]=min(dp[i],dp[i+value[k]]+1);
                }
            }
        }
    }
    /*
    for (int i=0;i<126;++i){
        if (dp[i]){
            cout << i << "-" << dp[i]-1 << " ";
        } 
    }
    cout << '\n';
    */
    cout << dp[t]-1 << '\n';
}