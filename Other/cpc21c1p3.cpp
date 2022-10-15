#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;
const double pi=3.14159265358979323846;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int r1, r2, r3; cin >> r1 >> r2 >> r3;
        int in=max(r1-r3,0);
        int out=r1+r3;
        int tot=r2-r3;
        out=min(out,tot);
        
        tot=tot*tot;
        out=out*out;
        in=in*in;

        double bad=out-in;
        if (r3>=r1){
            int tmp=min(r3-r1,r2-r3);
            tmp=tmp*tmp;
            bad-=tmp;
        }
        cout << fixed << setprecision(6) << (tot-bad)/(tot) << '\n';
    }
}
