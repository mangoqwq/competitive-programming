#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

bool arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,t,k,v; cin >> n >> t >> k >> v;
    for (int i=1,a;i<=v;++i) cin >> a, arr[a]=1;
    int cnt=0,pl,pr=t,ans=0;
    for (int i=1;i<=t;++i) cnt+=arr[i];
    while (cnt<k){
        if (!arr[pr]) cnt++, ans++, arr[pr]=1;
        pr--;
    }
    for (pl=2,pr=t+1;pr<=n;++pl,++pr){
        cnt-=arr[pl-1];
        cnt+=arr[pr];
        if (cnt<k) ans++, cnt++, arr[pr]=1;
    }
    cout << ans << '\n';
}