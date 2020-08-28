#include <bits/stdc++.h>

using namespace std;
double dp[3000];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int N; cin >> N;
    double coin; dp[0]=1;
    for (int _=0;_<N;++_){
        cin >> coin;
        for (int i=2999;i>0;--i){
            dp[i]=(dp[i]*(1-coin))+(dp[i-1]*coin);
        }
        dp[0]=dp[0]*(1-coin);
    }
    double result=0;
    for (int i=(N+1)/2;i<3000;++i){
        result+=dp[i];
    }
    printf("%.9f\n", result);
}