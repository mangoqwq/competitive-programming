#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const ll mod=1e9+7;
ll dp[5][100001];
ll dp2[100001];
ll a(int x);
ll b(int x);
ll c1(int x);
ll c2(int x);
ll d(int x);
ll f(int x){
    if (dp2[x]!=-1) return dp2[x];
    return dp2[x]=(f(x-1)+f(x-3))%mod;
}
ll a(int x){
    if (x<=0) return 0;
    if (dp[0][x]!=-1) return dp[0][x];
    return dp[0][x]=(a(x-1)+b(x-2)+c1(x-3))%mod;
}
ll b(int x){
    if (x<=0) return 0;
    if (dp[1][x]!=-1) return dp[1][x];
    return dp[1][x]=(a(x-2)+c2(x-3)+d(x-1)+d(x-3))%mod;
}
ll c1(int x){
    if (x<=0) return 0;
    if (dp[2][x]!=-1) return dp[2][x];
    return dp[2][x]=(a(x-2)+c2(x))%mod;
}
ll c2(int x){
    if (x<=0) return 0;
    if (dp[3][x]!=-1) return dp[3][x];
    return dp[3][x]=(a(x-1)+a(x-2)+c2(x-3)+d(x-1)+d(x-3))%mod;
}
ll d(int x){
    if (x<=0) return 0;
    if (dp[4][x]!=-1) return dp[4][x];
    return dp[4][x]=(a(x)+b(x-1))%mod;
}


int main(){
    memset(dp,-1,sizeof dp);
    dp[0][1]=1;
    memset(dp2,-1,sizeof dp2);
    dp2[0]=0; dp2[1]=1;
    int n,k; cin >> n >> k;
    if (k==1){
        cout << 1 << '\n';
    } 
    if (k==2){
        cout << f(n) << '\n';
    }
    if (k==3){
        cout << a(n) << '\n';
    }
}