#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    ll h, m, s; cin >> h >> m >> s;
    ll t=-60*60*h-60*m-s;
    t=(t+(43200*(ll)1e12))%43200;
    h=t/3600;
    m=t%3600/60;
    s=t%60;
    printf("%02lld:%02lld:%02lld\n",h,m,s);
}