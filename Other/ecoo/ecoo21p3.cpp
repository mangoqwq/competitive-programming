#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

struct Answer{ int id, c; } a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m, k; cin >> n >> m >> k;
    for (int i=1;i<=k;++i){
        int id, q, c; cin >> id >> q >> c;
        if (a[q].c==0||c>a[q].c) a[q]={id,c};
    }
    for (int i=1;i<=n;++i){
        if (a[i].c==0) cout << -1 << (i==n?'\n':' ');
        else cout << a[i].id << (i==n?'\n':' ');
    }
}