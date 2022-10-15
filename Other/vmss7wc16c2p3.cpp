#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int pos[1000001];
int arr[1000001];
int dp[1000001];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        pos[a]=i;
    }
    int m; cin >> m;
    for (int i=1,a;i<=m;++i){
        cin >> a;
        arr[i]=pos[a];
    }
    int index=1; dp[1]=arr[1];
    for (int i=2;i<=m;++i){
        if (arr[i]==0) continue;
        if (arr[i]>dp[index]){
            dp[index++]=arr[i];
            continue;
        }
        dp[lower_bound(dp,dp+index,arr[i])-dp]=arr[i];
    }
    cout << index << '\n';

    
}