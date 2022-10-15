#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5;

struct Seg{
    ll l, r;
    bool operator<(const Seg &a) const{ return l<a.l; }
} arr[MAXN];

ll solve(){
    ll n, k; cin >> n >> k;
    for (int i=1;i<=n;++i){
        cin >> arr[i].l >> arr[i].r;
    }
    sort(arr+1,arr+1+n);
    ll curr=0, ans=0;
    for (int i=1;i<=n;++i){
        if (curr>=arr[i].r) continue;
        if (curr<arr[i].l) curr=arr[i].l;
        ll temp=(arr[i].r-curr+k-1)/k;
        curr+=temp*k; ans+=temp;
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int i=1;i<=t;++i){
        cout << "Case #" << i << ": " << solve() <<'\n';
    }
}