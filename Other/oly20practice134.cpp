#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int a[MAXN], last, curr, ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        if (a[i]<=a[i-1]) curr=last+1;
        else curr=1;
        ans=max(ans,curr);
        last=curr;
    }
    cout << ans << '\n';
}