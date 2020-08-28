#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int mod=1000000007;
ll dp[100001];
ll pre[100001];

void generate(){
    ll sum=0;
    for (int i=0;i<100001;++i){
        sum+=dp[i];
        pre[i]=sum;
    }
    return;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    dp[0]=1;
    int kids, candies; cin >> kids >> candies;
    for (int _=0,a;_<kids;++_){
        cin >> a;
        generate();
        for (int i=candies;i>a;--i){
            dp[i]=(pre[i]-pre[i-a-1])%mod;
        }
        for (int i=a;i>=0;--i){
            dp[i]=pre[i]%mod;
        }
        /*
        for (int i=0;i<candies+1;++i){
            cout << dp[i] << " ";
        }
        cout << '\n';
        */
    }
    cout << dp[candies]%mod << '\n';
}