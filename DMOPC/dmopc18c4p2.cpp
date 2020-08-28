#include <bits/stdc++.h>

using namespace std;
bool dp[490001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    dp[0]=1;
    int n; cin >> n;
    int sum=0;
    for (int _=0,a;_<n;++_){
        cin >> a;
        sum+=a;
        for (int i=490000;i>=a;--i){
            if (dp[i-a]){
                dp[i]=1;
            }
        }
    }
    int mininum=0x3f3f3f3f;
    for (int i=0;i<=sum;++i){
        if (dp[i] && dp[sum-i]){
            //cout << abs(sum-2*i) << " ";
            mininum=min(abs(sum-2*i),mininum);
        }
    }
    cout << mininum << '\n';
}