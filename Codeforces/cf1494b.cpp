#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

bool solve(int n, int u, int r, int d, int l){
    for (int i=0;i<(1<<4);++i){
        int cu=0, cr=0, cd=0, cl=0;
        if (1&i) cu++, cl++;
        if (2&i) cu++, cr++;
        if (4&i) cd++, cr++;
        if (8&i) cd++, cl++;
        bool ans=1;
        if (cu>u||cr>r||cd>d||cl>l) ans=0;
        if (r-cr>n-2) ans=0;
        if (l-cl>n-2) ans=0;
        if (u-cu>n-2) ans=0;
        if (d-cd>n-2) ans=0;
        if (ans) return 1;
    }
    return 0;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, u, r, d, l; cin >> n >> u >> r >> d >> l;
        cout << (solve(n, u, r, d, l)?"YES":"NO") << '\n';
    }
}