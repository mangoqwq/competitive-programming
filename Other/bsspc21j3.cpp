#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1001;

int ans[3];
set<int> c[]={{'R','O','P','B'},{'U','G','P','B'},{'Y','O','G','B'}};
bool is[3];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int m, n; cin >> m >> n;
    for (int i=1;i<=n;++i){
        ms(is,0);
        for (int j=1;j<=m;++j){
            char x; cin >> x;
            for (int k=0;k<3;++k){
                if (c[k].count(x)){
                    if (!is[k]) ans[k]++;
                    is[k]=1;
                }
                else is[k]=0;
            }
        }
    }
    cout << ans[0] << " " << ans[2] << " " << ans[1] << '\n';
}