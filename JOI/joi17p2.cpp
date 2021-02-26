#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3005;

ll n, m, k, a, b, c, ans=-1, t, arr[MAXN];
struct Item{
    ll x, r, tl;
    ll val() const{
        if (x>r||tl<0) return 0;
        ll dest=min(x+tl/a,r);
        return dest-x+1;
    }
    Item go() const{
        ll dest=min(x+tl/a,r);
        return {dest+1,r,tl-(dest-x+1)*c};
    }
    bool operator<(const Item &a) const{
        return this->val()<a.val();
    }
} tmp;
priority_queue<Item> pq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> k >> a >> b >> c >> t; n--;
    arr[m+1]=n+1;
    k-=m;
    for (int i=1;i<=m;++i) cin >> arr[i], arr[i]--;
    for (int i=1;i<=m;++i){
        ll dest=min(arr[i]+(t-arr[i]*b)/a,arr[i+1]-1);
        if (arr[i]*b>t) continue;
        ans+=1+dest-arr[i];
        pq.push({dest+1,arr[i+1]-1,t-arr[i]*b-(dest-arr[i]+1)*c});
    }
    for (int i=1;i<=k;++i){
        if (pq.empty()) break;
        tmp=pq.top(); pq.pop();
        ans+=tmp.val();
        pq.push(tmp.go());
    }
    cout << ans << '\n';
}