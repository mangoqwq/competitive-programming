#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

int a[MAXN][MAXN], b[MAXN][MAXN], c[MAXN][MAXN];

void rot90(int r1, int c1, int r2, int c2){
    for (int i=r1;i<=r2;++i){
        for (int j=c1;j<=c2;++j){
            b[i-r1][j-c1]=a[i][j];
        }
    }
    int n=r2-r1+1;
    for (int i=0;i<n;++i){
        for (int j=0;j<n;++j){
            c[i][j]=b[n-j-1][i];
        }
    }
    for (int i=r1;i<=r2;++i){
        for (int j=c1;j<=c2;++j){
            a[i][j]=c[i-r1][j-c1];
        }
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin >> a[i][j];
        }
    }
    int q; cin >> q;
    while (q--){
        int r1, c1, r2, c2, x; cin >> r1 >> c1 >> r2 >> c2 >> x;
        x=(x+360)/90;
        while (x--){
            rot90(r1,c1,r2,c2);
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cout << a[i][j] << " ";
        }
        cout << '\n';
    }
}