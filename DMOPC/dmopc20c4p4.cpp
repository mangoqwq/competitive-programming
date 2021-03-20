#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e6+1;

ll n, a, sum, p;
struct Item{ ll x, h, tot; } s[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> a;
    s[++p]={1,0,0};
    cout << s[p].tot << (1==n?'\n':' ');
    for (int i=2;i<=n;++i){
        cin >> a; sum+=a;
        a=max(a,s[p].h);
        while (a-s[p].h>i-s[p].x) p--;
        auto [x,h,tot]=s[p];
        ll e=a-h;
        s[++p]={i,a,tot+(i-x)*(h)+e*(e+1)/2};
        cout << s[p].tot-sum << (i==n?'\n':' ');
    }
}