#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e3+1;

bool a[MAXN][MAXN], can=1;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin >> a[i][j];
            if (a[i][j]^a[1][j]!=a[i][1]^a[1][1]) can=0;
        }
    }
    if (!can) cout << -1 << '\n';
    else{
        vector<pair<char,int>> v;
        for (int i=1;i<=n;++i) if (a[i][1]^a[1][1]) v.push_back({'R',i});
        for (int i=1;i<=n;++i) if (a[1][i]) v.push_back({'C',i});
        cout << v.size() << '\n';
        for (auto [a,b]:v) cout << a << " " << b << '\n';
    }
}