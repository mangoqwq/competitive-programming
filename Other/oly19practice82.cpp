#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

bool a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i){
        cin >> a[i];
    }
    for (int i=1;i<=n;++i){
        int tmp=a[i];
        for (int j=1;j<=m;++j){
            int k=(i+j-1)%n+1;
            tmp^=a[k];
        }
        cout << tmp << '\n';
    }
}