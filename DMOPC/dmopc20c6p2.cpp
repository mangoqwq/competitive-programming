#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=1e6+1;

struct Swap{ int a, b; };
vector<Swap> ans;
int a[MAXN], b[MAXN];
vector<int> zero;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> a[i];
    for (int i=1;i<=n;++i) cin >> b[i];
    bool can=1;
    int ca=0, cb=0;
    for (int i=1;i<=n;++i){
        ca+=a[i], cb+=b[i];
        if (cb>ca) can=0;
    }
    if (ca!=cb) can=0;
    if (!can){
        cout << -1 << '\n';
        return 0;
    }
    for (int i=n;i>=1;--i) if (!a[i]) zero.push_back(i);
    int last=1; bool diff=0;
    int paint=0;
    ca=cb=0;
    for (int i=1;i<=n;++i){
        if (!zero.empty()&&zero.back()==i) ca++, zero.pop_back();
        cb+=!b[i];
        if (i<=paint) a[i]=1;
        diff|=a[i]!=b[i];
        if ((b[i]&&!b[i+1])||i==n){
            int nxt=i;
            while (ca!=cb){
                ca++;
                nxt=zero.back(); zero.pop_back();
            }
            paint=nxt;
            if (diff) ans.push_back({last,nxt});
            ca=cb=diff=0; last=i+1;
        }
    }
    // for (int i=1;i<=n;++i){
    //     if (a[i]!=b[i]) assert(false);
    // }
    cout << ans.size() << '\n';
    for (auto [l,r]:ans) cout << l << " " << r << '\n';
}