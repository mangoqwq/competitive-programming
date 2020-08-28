#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
int x[1001],y[1001];
int dp[1005][1005];
int n;
string a,b;
bool rivalry(int i,int k){
    if (a[i-1]=='W'&&b[k-1]=='L'&&x[i]>y[k]) return true;
    if (a[i-1]=='L'&&b[k-1]=='W'&&x[i]<y[k]) return true;
    return false;
}

int main(){
    cin >> n;
    cin >> a;
    for (int i=1;i<=n;++i){
        cin >> x[i];
    }
    cin >> b;
    for (int i=1;i<=n;++i){
        cin >> y[i];
    }
    int temp=0;
    for (int i=1;i<=n;++i){
        for (int k=1;k<=n;++k){
            if (rivalry(i,k)){
                dp[i][k]=max(max(dp[i-1][k-1]+x[i]+y[k],dp[i-1][k]),dp[i][k-1]);
            }
            else{
                dp[i][k]=max(max(dp[i-1][k],dp[i][k-1]),dp[i-1][k-1]);
            }
            temp=max(temp,dp[i][k]);
        }
    }
    cout << temp << '\n';

}