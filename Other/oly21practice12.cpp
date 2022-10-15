#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+2;

ll a[MAXN], ans[MAXN], curr;
map<ll,int> pos={{0,0}}, neg={{0,0}};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=q;++i){
        ll x; cin >> x;
        curr+=x;
        if (curr>0&&curr>(--pos.end())->first) pos[curr]=i; 
        if (curr<0&&-curr>(--neg.end())->first) neg[-curr]=i;
    }
    pos[LLONG_MAX]=neg[LLONG_MAX]=inf;
    for (int i=2;i<=n;++i){
        ll x=a[i]-a[i-1];
        ll lo=0, hi=x, mid;
        while (lo<hi){
            mid=lo+hi+1>>1;
            int tl=pos.lower_bound(mid)->second;
            int tr=neg.lower_bound(x-mid+1)->second;
            if (tl!=inf&&tl<tr) lo=mid;
            else hi=mid-1;
        }
        ans[i-1]+=lo;
        ans[i]+=min(x-lo,(--(--neg.end()))->first);
    }
    ans[1]+=(--(--neg.end()))->first;
    ans[n]+=(--(--pos.end()))->first;
    for (int i=1;i<=n;++i) cout << ans[i] << '\n';
}