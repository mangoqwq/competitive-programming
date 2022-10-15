#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int arr[MAXN], n;

void solve(vector<int> &ans){
    int best=0;
    for (int i=1;i<=n;++i){
        for (int j=0;j*j+1<i;++j) best=max(best,arr[i-j*j-1]+j+1);
        ans[i]=best-arr[i];
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    vector<int> ans1(n+1), ans2(n+1);
    solve(ans1);
    reverse(arr+1,arr+1+n); solve(ans2);
    for (int i=1;i<=n;++i) cout << max({ans1[i],ans2[n-i+1],0}) << '\n';
}