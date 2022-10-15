#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n+1);
    for (int i=1;i<=n;++i) cin >> a[i];
    int v=1;
    for (int i=1;i<=n;++i){
        if (a[i]==v) v++;
    }
    if (v==1) cout << -1 << '\n';
    else cout << n-v+1 << '\n';
}