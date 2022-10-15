#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+5;

ll a[MAXN], b[MAXN], cnt[MAXN];
map<ll,int> m;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i], b[i]=a[i];
    sort(b+1,b+1+n);
    for (int i=1;i<=n;++i) m[b[i]]=i;
    ll worst=0;
    for (int i=1;i<=n;++i){
        int mn=min(m[a[i]],m[b[i]])+1, mx=max(m[a[i]],m[b[i]])+1;
        cnt[mn]++, cnt[mx]--;
    }
    for (int i=1;i<=n;++i){
        cnt[i]+=cnt[i-1];
        if (cnt[i]) worst=max(worst,b[i]-b[i-1]);
    }
    cout << worst << '\n';
}