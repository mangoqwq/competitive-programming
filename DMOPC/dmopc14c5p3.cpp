#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; cin >> n;
    vector<int> arr(n+1);
    for (int i=1;i<=n;++i) cin >> arr[i];
    arr.push_back(0x3f3f3f3f);
    int ans=1,cnt=1;
    for (int i=2;i<=n+1;++i){
        if (abs(arr[i]-arr[i-1])<=2) cnt++;
        else ans=max(ans,cnt),cnt=1;
    }
    cout << ans << '\n';
}