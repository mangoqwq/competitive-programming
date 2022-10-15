#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

ll arr[MAXN];
int n;

ll f(int l, int r){
    ll a1=arr[l-1];
    ll a2=arr[r]-a1;
    ll a3=arr[n]-arr[r];
    return max({a1,a2,a3})-min({a1,a2,a3});
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i], arr[i]+=arr[i-1];
    ll ans=LLONG_MAX;
    for (int i=2;i<n;++i){
        int l=2, r=i;
        while(l<r){
            int mid=l+r+1>>1;
            if (arr[i]<2*arr[mid-1]) r=mid-1;
            else l=mid;
        }
        ans=min(ans,f(l,i));
        ans=min(ans,f(l+1,i));
    }
    cout << ans << '\n';
}