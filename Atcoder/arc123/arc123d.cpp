#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int n;
ll a[MAXN];

ll calc(ll b){
    ll c=a[1]-b;
    ll ans=abs(b)+abs(c);
    for (int i=2;i<=n;++i){
        ll dif=a[i]-a[i-1];
        if (dif>=0) b+=dif;
        else c+=dif;
        ans+=abs(b)+abs(c);
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    ll lo=-1e15, hi=1e15;
    while (lo<hi){
        ll mid=lo+hi>>1;
        ll a=calc(mid), b=calc(mid+1);
        if (b<a) lo=mid+1;
        else hi=mid;
    }
    cout << calc(lo) << '\n';
}
