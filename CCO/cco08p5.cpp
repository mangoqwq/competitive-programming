#include <bits/stdc++.h>

using namespace std;
bool dp[5000001];
int visited[5000001];

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    dp[0]=1;
    int n; cin >> n;
    int sum=0;
    for (int k=0,a,b;k<n;++k){
        cin >> a >> b;
        sum+=(a*b);
        for (int i=b;i<5000001;++i){
            if (!dp[i]&&dp[i-b]&&visited[i-b]<a){
                dp[i]=1;
                visited[i]=visited[i-b]+1;
            }
            visited[i-b]=0;
        }
    }
    int minimum=0x3f3f3f3f;
    for (int i=0;i<=sum/2;++i){
        if (dp[i]){
            minimum=min(minimum,abs(sum-2*i));
        }
    }
    cout << minimum << '\n';
}