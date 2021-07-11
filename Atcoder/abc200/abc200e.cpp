#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e6+10;

ll n, dp[MAXN];
ll cnt3(ll tot){
    return dp[tot];
}
ll cnt2(ll a, ll tot){
    tot-=a;
    ll l=max(1LL,tot-n), r=min(tot-1,n);
    return max(r-l+1,0LL);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll k, tot, a, b, c;
    cin >> n >> k;
    dp[0]=1;
    for (int i=1;i<=3;++i){
        for (int j=1;j<=i*n;++j){
            dp[j]+=dp[j-1];    
        }
        for (int j=i*n;j>=0;--j){
            ll l=j-n-1<0?0:dp[j-n-1];
            ll r=j-1<0?0:dp[j-1];
            dp[j]=r-l;
        }
    }
    for (tot=3;;++tot){
        ll cnt=cnt3(tot);
        if (k<=cnt) break;
        k-=cnt;
    }
    for (a=1;;++a){
        ll cnt=cnt2(a,tot);
        if (k<=cnt) break;
        k-=cnt;
    }
    b=max(1LL,tot-n-a)+k-1; c=tot-a-b;
    cout << a << " " << b << " " << c << '\n';
}