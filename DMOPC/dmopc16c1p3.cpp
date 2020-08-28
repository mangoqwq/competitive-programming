#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
double a[10001];
double dp[10001];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i];
    }
    dp[1]=a[1];
    dp[2]=min(a[1],a[2])*0.5+max(a[1],a[2]);
    for (int i=3;i<=n;++i){
        double temp1=dp[i-3]+a[i]+a[i-1]+a[i-2]-min({a[i],a[i-1],a[i-2]});
        double temp2=dp[i-2]+a[i]+a[i-1]-min(a[i],a[i-1])*0.5;
        double temp3=dp[i-1]+a[i];
        dp[i]=min({temp1,temp2,temp3});
    }
    printf("%.1f",dp[n]);
    
    
}