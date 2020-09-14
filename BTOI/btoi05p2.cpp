#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    int cnt=0, uwu, cm=0; char a;
    bool can=1;
    for (int i=1;i<=n;++i){
        cin >> a;
        if (a=='(') cnt++;
        else if (a==')') cnt--;
        else{
            if (cm+1==m) uwu=cnt;
            else cnt--, cm++;
        }
        if (cnt<0) can=0;
    }
    if (uwu<cnt) can=0;
    cout << can << '\n';
    if (can){
        for (int i=1;i<m;++i) cout << 1 << '\n';
        cout << cnt << '\n';
    }
}