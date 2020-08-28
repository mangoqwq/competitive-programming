#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=31,MAXN=0;

map<ll,ll> last,curr;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    string uwu; ll h1,h2,cnt;
    last[0]=1;
    for (int len=1;len<=n;++len){
        curr.clear();
        for (int j=1;j<=k;++j){
            cin >> uwu;
            h1=h2=cnt=0;
            for (int i=1;i<len;++i) h1=h1*seed+uwu[i];
            for (int i=0;i<len-1;++i) h2=h2*seed+uwu[i];
            if (last.count(h1)&&h1!=h2) cnt+=last[h1];
            if (last.count(h2)) cnt+=last[h2];
            h2=h2*seed+uwu[len-1];
            curr[h2]+=cnt;
            curr[h2]%=mod;
        }
        swap(last,curr);
    }
    ll ans=0;
    for (auto x:last) ans+=x.second, ans%=mod;
    cout << ans << '\n';
}