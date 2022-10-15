#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=4e5+5;

ll n, k;
ll t[MAXN], x[MAXN], y[MAXN];

bool check(ll sz){
    ll lo=0, hi=1e9;
    int idx=1; ll last=0, curr;
    while (idx<=n){
        curr=t[idx];
        ll mn=x[idx]-sz, mx=x[idx];
        ll uwu1=x[idx], uwu2=x[idx];
        idx++;
        while (t[idx]==curr){
            mn=min(mn,x[idx]-sz);
            mx=max(mx,x[idx]);
            uwu1=min(uwu1,x[idx]);
            uwu2=max(uwu2,x[idx]);
            idx++;
        }
        if (uwu2-uwu1>sz) return 0;
        lo-=(curr-last)*k;
        hi+=(curr-last)*k;
        lo=max(lo,mn);
        hi=min(hi,mx);
        if (lo>hi) return 0;
        last=curr;
    }
    return 1;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> t[i] >> x[i] >> y[i];
    t[n+1]=-1;
    ll lo=0, hi=1e9, mid;
    while (lo<hi){
        mid=(lo+hi)>>1;
        bool can=1;
        can&=check(mid);
        swap(x,y);
        can&=check(mid);
        swap(x,y);
        if (can) hi=mid;
        else lo=mid+1;
    }
    cout << lo << '\n';
}
