#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    int step=0;
    for (int i=1;i<=min(k,n-k);++i){
        if ((n-k)%i) continue;
        if (((n-k)/i)%2==0||(i==k)) step=i;
    }
    if (step==0){
        cout << -1 << '\n';
        cout.flush();
        return 0;
    }
    int rem=k-step, ans=0;
    for (int i=rem+1;i<=n;i+=step){
        cout << "? ";
        for (int j=1;j<=rem;++j) cout << j << " ";
        for (int j=i;j<=i+step-1;++j) cout << j << " ";
        cout << '\n';
        cout.flush();
        int curr; cin >> curr;
        ans^=curr;
    }
    cout << "! ";
    cout << ans << '\n';
}