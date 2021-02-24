#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=2*0x3f3f3f3f, MAXN=0;

int n, m, q;

int guess(int r, int c){
    if (r>n||c>m) return inf;
    cout << "? " << r << " " << c << '\n';
    cout.flush();
    int ret; cin >> ret;
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> m >> q;
    int lr=1, rr=n, lc=1, rc=m, mr, mc;
    while (lr<rr||lc<rc){
        mr=lr+rr>>1, mc=lc+rc>>1;
        int a=guess(mr,mc), b=guess(mr+1,mc), c=guess(mr,mc+1);
        if (a<b) rr=mr;
        else lr=mr+1;
        if (a<c) rc=mc;
        else lc=mc+1;
    }
    int ans=guess(lr,lc);
    cout << "! " << ans << '\n';
    cout.flush();
}