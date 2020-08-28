#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

//Longest common subsequence

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5001;
int dp[MAXN],last[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    string uwu; cin >> uwu;
    string owo=uwu;
    reverse(owo.begin(),owo.end());
    for (int i=1;i<=n;++i){
        for (int k=1;k<=n;++k){
            if (uwu[i-1]==owo[k-1]){
                dp[k]=last[k-1]+1;
            }
            else{
                dp[k]=max(last[k],dp[k-1]);
            }
        }
        swap(dp,last);
    }
    cout << n-last[n] << '\n';
}