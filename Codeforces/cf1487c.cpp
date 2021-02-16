#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

int a[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n; cin >> n;
        for (int s=3*n;s>=0;--s){
            bool flag=1;
            for (int i=1;i<=n;++i) a[i]=0;
            for (int i=1;i<=n;++i){
                for (int j=i+1;j<=n;++j){
                    if (a[i]+3<=s) a[i]+=3;
                    else if (a[i]+1<=s) a[i]++, a[j]++;
                    else a[j]+=3;
                }
                if (a[i]!=s) flag=0;
            }
            if (flag){
                for (int i=1;i<=n;++i) a[i]=0;
                for (int i=1;i<=n;++i){
                    for (int j=i+1;j<=n;++j){
                        if (a[i]+3<=s) a[i]+=3, cout << 1 << " ";
                        else if (a[i]+1<=s) a[i]++, a[j]++, cout << 0 << " ";
                        else a[j]+=3, cout << -1 << " ";
                    }
                    if (a[i]!=s) flag=0;
                }
                cout << '\n';
                break;
            }
        }
    }
}