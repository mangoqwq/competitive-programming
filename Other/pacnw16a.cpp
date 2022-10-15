#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast,unroll-loops")

//Longest common subsequence

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=51;
int dp[51][51];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    string uwu; cin >> uwu;
    string owo="abcdefghijklmnopqrstuvwxyz";
    for (int i=1;i<=uwu.size();++i){
        for (int k=1;k<=owo.size();++k){
            if (uwu[i-1]==owo[k-1]){
                dp[i][k]=dp[i-1][k-1]+1;
            }
            else{
                dp[i][k]=max(dp[i-1][k],dp[i][k-1]);
            }
        }
    }
    cout << 26-dp[uwu.size()][owo.size()] << '\n';
}