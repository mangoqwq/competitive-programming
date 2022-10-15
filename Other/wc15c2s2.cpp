#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=4e4+2, MAXQ=2e5+1;

struct Item{
    int r, c;
    bool operator<(const Item &x) const{
        if (r==x.r){
            if (r%2) return c<x.c;
            else return c>x.c;
        }
        return r<x.r;
    }
};
set<Item> s={{1,1}};
int ans, maxr;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int q; cin >> q;
    while (q--){
        int r, c; cin >> r >> c;
        maxr=max(maxr,r);
        s.insert({r,c});
        if (++s.find({r,c})==s.end()){
            int pl=(--s.find({r,c}))->c;
            ans+=abs(c-pl);
        }
        else{
            int pl=(--s.find({r,c}))->c;
            int pr=(++s.find({r,c}))->c;
            ans-=abs(pl-pr);
            ans+=abs(c-pr);
            ans+=abs(c-pl);
        }
        cout << ans+(maxr-1) << '\n';
    }
}