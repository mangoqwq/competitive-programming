#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=998244353, seed=131, MAXN=2e5+1;

ll w[MAXN], wa[MAXN], wac[MAXN], cw, ca, cc, cwa, cac, cwac;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    string s; cin >> s; s=" "+s;
    for (int i=1;i<=n;++i){
        if (s[i]=='W') cw++, cw%=mod;
        if (s[i]=='A') ca++, ca%=mod, cwa+=cw, cwa%=mod;
        if (s[i]=='C') cc++, cc%=mod, cac+=ca, cac%=mod, cwac+=cwa, cwac%=mod;
    }
    for (int i=1;i<=k;++i){
        w[i]=w[i-1]+cw; w[i]%=mod;
        wa[i]=wa[i-1]+ca*w[i-1]+cwa; wa[i]%=mod;
        wac[i]=wac[i-1]+cc*wa[i-1]+cac*w[i-1]+cwac; wac[i]%=mod;
    }
    cout << wac[k] << '\n';
}