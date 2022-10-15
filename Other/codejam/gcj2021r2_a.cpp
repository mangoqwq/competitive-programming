#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

ll cost;
int qmin(int l, int r){
    cout << 'M' << " " << l << " " << r << '\n';
    cout.flush();
    cost+=((int)1e8+r-l)/(r-l+1);
    int ret; cin >> ret;
    if (ret==-1) exit(0);
    return ret;
}

void qswap(int l, int r){
    cout << 'S' << " " << l << " " << r << '\n';
    cout.flush();
    int ret; cin >> ret;
    if (ret==-1) exit(0);
}

void qdone(){
    cout << 'D' << '\n';
    cout.flush();
    int ret; cin >> ret;
    if (ret==-1) exit(0);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t, n; cin >> t >> n;
    while (t--){
        cost=0;
        for (int i=1;i<n;++i){
            int x=qmin(i,n);
            if (x!=i) qswap(i,x);
        }
        qdone();
    }
}