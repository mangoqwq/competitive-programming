#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=129601;

bool dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    dp[0]=1;
    int n, q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        for (int j=a;j<MAXN;++j) if (dp[j-a]) dp[j]=1;
        for (int j=MAXN-1-a;j;--j) if (dp[j+a]) dp[j]=1;
    }
    for (int i=1;i<=q;++i){
        int a; cin >> a;
        bool ans=0;
        for (int j=a;j<MAXN;j+=360) ans|=dp[j];
        cout << (ans?"YES":"NO") << '\n';
    }
}