#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1,MAXM=1e4+1;

bool seen[MAXN];
int n,m,cnt,ans;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m;
    ms(seen,1); cnt=m;
    for (int i=1,a;i<=n;++i){
        cin >> a;
        if (seen[a]) cnt--, seen[a]=0;
        if (cnt==0) ans++, ms(seen,1), cnt=m;
    }
    cout << ans+1 << '\n';
}