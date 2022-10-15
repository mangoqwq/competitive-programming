#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int ans=0;
    for (int i=1;i<=n;++i){
        int a; cin >> a;
        bool flag=a!=1;
        for (int i=2;i*i<=a;++i) flag&=(a%i!=0);
        ans+=flag;
    }
    cout << ans << '\n';
}