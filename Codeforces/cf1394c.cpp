#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=3e5+1,inf=0x3f3f3f3f;

int x[MAXN],y[MAXN],minb=inf,minn=inf,maxb,maxn,ansb,ansn,n;
int best=0;

int check(int cntb, int cntn){
    int ans=0;
    for (int i=1;i<=n;++i){
        ans=max(ans,max(abs(x[i]-cntb),abs(y[i]-cntn)));
    }
    return ans;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    for (int i=1;i<=n;++i){
        string uwu; cin >> uwu;
        for (char umu:uwu){
            if (umu=='B') x[i]++;
            if (umu=='N') y[i]++;
        }
    }
    cout << best << '\n';
    for (int i=1;i<=ansb;++i) cout << 'B';
    for (int i=1;i<=ansn;++i) cout << 'N';
    cout << '\n';
}