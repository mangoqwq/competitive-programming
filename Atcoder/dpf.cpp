#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")

using namespace std;
int dp[3001][3001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    string a,b; cin >> a >> b;
    for (int i=1;i<a.size()+1;++i){
        for (int k=1;k<b.size()+1;++k){
            if (a[i-1]==b[k-1]){
                dp[i][k]=dp[i-1][k-1]+1;
            }
            else{
                dp[i][k]=max(dp[i][k-1],dp[i-1][k]);
            }
        }
    }
    int index=dp[a.size()][b.size()];
    char lcs[index+1];
    lcs[index] = '\0';
    int i=a.size(),k=b.size();
    while (i>0&&k>0){
        if (a[i-1]==b[k-1]){
            lcs[--index]=a[i-1];
            i--; k--;
        }
        else if (dp[i-1][k]>dp[i][k-1]){
            i--;
        }
        else{
            k--;
        }
    }
    cout << lcs << '\n';

}