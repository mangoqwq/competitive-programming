#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=11;

int a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    sort(a+1,a+1+n);
    int ans=0;
    do{
        bool can=1;
        for (int i=2;i<=n;++i){
            can&=(a[i-1]>a[i])||(abs(__builtin_clz(a[i])-__builtin_clz(a[i-1]))==1);
        }
        ans+=can;
    } while(next_permutation(a+1,a+1+n));
    cout << ans << '\n';
}