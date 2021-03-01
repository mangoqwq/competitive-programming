#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    int ans=inf;
    for (int i=1;i<=n;++i){
        int a, p, x; cin >> a >> p >> x;
        if (a<x) ans=min(ans,p);
    }
    cout << (ans==inf?-1:ans) << '\n';
}