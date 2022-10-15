#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
ll dp[100001];
ll p[100001];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0,a;i<n;++i){
        cin >> a; p[a]+=a;
    }
    dp[1]=p[1];
    ll a=dp[1];
    for (int i=2;i<=100000;++i){
        dp[i]=max(dp[i-2]+p[i],dp[i-1]);
        a=max(a,dp[i]);
    }
    cout << a << '\n';
}