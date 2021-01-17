#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
ll dp[200002];
int heights[200002];
ll value[200002];
ll uwu[200002];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    heights[200001]=200001;
    int n; cin >> n;
    for (int i=1;i<n+1;++i){
        cin >> heights[i];
    }
    for (int i=1;i<n+1;++i){
        cin >> value[i];
    }
    for (int i=n;i>0;--i){
        dp[i]=value[i]+uwu[heights[i]];
        for (int idx=heights[i];idx>0;--idx){
            if (uwu[idx]<dp[i]){
                uwu[idx]=dp[i];
            }
            else{
                break;
            }
        }
        
    }
    ll uwu=-1;
    for (auto&&x:dp){
        //cout << x << " ";
        uwu=max(uwu,x);
    }
    cout << uwu << '\n';
}