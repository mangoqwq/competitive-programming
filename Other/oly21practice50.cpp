#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int a[MAXN], cnt[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        int x; cin >> x;
        a[i]=x;
        cnt[x]++;
    }
    for (int i=1;i<=n;++i){
        int ans=0;
        for (int j=1;j*j<=a[i];++j){
            if (a[i]%j) continue;
            ans+=cnt[j];
            if (j*j!=a[i]) ans+=cnt[a[i]/j];
        }
        cout << ans-1 << '\n';
    }
}