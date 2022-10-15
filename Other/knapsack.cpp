#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[5001];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int number, trucks; cin >> number >> trucks;
    for (int _=0,amount,value,cost;_<number;++_){
        cin >> amount >> cost >> value;
        for (int k=0;k<min(amount,5000/cost);++k){
            for (int i=5000;i>=cost;--i){
                dp[i]=max(dp[i],dp[i-cost]+value);
            }
        }
    }
    ll maxearnings=-0x3f3f3f3f3f3f3f;
    for (int i=0,capacity,fuel;i<trucks;++i){
        cin >> capacity >> fuel;
        maxearnings=max(maxearnings,dp[capacity]-fuel);
    }
    cout << maxearnings << '\n';

}