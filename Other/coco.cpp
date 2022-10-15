#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

int col[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=0;i<n;++i) cin >> col[i];
    for (int i=0;i<n;++i){
        for (int j=1;j<=100;++j){
            int a=(i-j+n)%n, b=i, c=(i+j+n)%n;
            if (a==b||b==c||a==c) continue;
            if (col[a]==col[b]&&col[b]==col[c]){
                cout << a+1 << " " << b+1 << " " << c+1 << '\n';
                return 0;
            }
        }
    }
    cout << 0 << " " << 0 << " " << 0 << '\n';
}