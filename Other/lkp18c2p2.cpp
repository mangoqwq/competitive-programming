#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int seed=131,MAXN=2e5+1;

ll pre[MAXN];
ll cnt[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    ll ans=0,n,mod; cin >> n >> mod;
    ll a;
    cnt[0]++;
    for (int i=1;i<=n;++i){
        cin >> a; pre[i]=(pre[i-1]+a)%mod; ans+=cnt[pre[i]]; cnt[pre[i]]++;
    }
    cout << ans << '\n';
}