#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=21;

int l[MAXN], r[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> l[i] >> r[i];
    int m; cin >> m;
    for (int i=1;i<=m;++i){
        int x, y; cin >> x >> y;
        bool bad=0;
        for (int j=1;j<=n;++j){
            if (!(x>r[j]||y<l[j])) bad=1;
        }
        cout << (bad?"Break is Over! Stop playing games! Stop watching Youtube!":":eyy:") << '\n';
    }
}