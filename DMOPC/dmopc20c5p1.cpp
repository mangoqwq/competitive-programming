#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    string a, b; cin >> a >> b;
    int n, m; n=a.size(), m=b.size();
    a=" "+a; b=" "+b;
    int i;
    for (i=1;i<=n&&i<=m;++i){
        if (a[i]!=b[i]) break;
    }
    i--;
    cout << (n+m)-2*i << '\n';
}