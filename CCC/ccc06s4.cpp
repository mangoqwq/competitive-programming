#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101;

int a[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    while (true){
        int n; cin >> n;
        if (n==0) break;
        for (int i=1;i<=n;++i) for (int j=1;j<=n;++j) cin >> a[i][j];
        bool as=1;
        for (int i=1;i<=n;++i)
            for (int j=1;j<=n;++j)
                for (int k=1;k<=n;++k)
                    as&=a[i][a[j][k]]==a[a[i][j]][k];
        bool ans=0;
        for (int i=1;i<=n;++i){
            bool id=1, in=1;
            for (int j=1;j<=n;++j) id&=a[j][i]==j&&a[i][j]==j;
            for (int j=1;j<=n;++j){
                bool can=0;
                for (int k=1;k<=n;++k) can|=a[k][j]==i&&a[j][k]==i;
                in&=can;
            }
            ans|=id&in;
        }
        cout << (ans&&as?"yes":"no") << '\n';
    }
}