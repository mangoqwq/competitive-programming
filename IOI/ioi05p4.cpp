#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7, seed=131, MAXN=1e6+1;

int a[MAXN], n, ans;
int arr[MAXN];

void solve(){
    int p=0;
    for (int i=1;i<=n;++i){
        if (abs(i-a[i])<=n/2) arr[++p]=(i-a[i]);
        else if (i-a[i]>=0) arr[++p]=(-(n-i+a[i]));
        else arr[++p]=(n+i-a[i]);
    }
    sort(arr+1,arr+1+p);
    int mn=arr[1];
    for (int t=0;t<=n;++t){
        ans=min(ans,max(abs(mn+t),arr[p]+t));
        while (arr[p]+t==n/2) mn=arr[p--]-n;
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n; ans=n/2;
    for (int i=1;i<=n;++i) cin >> a[i];
    solve(); reverse(a+1,a+1+n); solve();
    cout << ans << '\n';
}