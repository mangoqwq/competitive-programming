#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;
const double eps=1e-2;

struct Event{
    int x, c, l, r;
    bool operator<(const Event &a) const{
        if (x==a.x) return c>a.c;
        return x<a.x;
    }
};
vector<Event> eve;
multiset<Event> curr;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        double fx, fy, fw, fh; cin >> fx >> fy >> fw >> fh;
        int x=10*fx+eps, y=10*fy+eps, w=10*fw+eps, h=10*fh+eps;
        eve.push_back({x,1,y,y+h});
        eve.push_back({x+w,0,y,y+h});
    }
    eve.push_back({-inf});
    sort(eve.begin(),eve.end());
    ll ans=0;
    for (int i=1;i<=2*n;++i){
        auto [x,c,l,r]=eve[i];
        if (x!=eve[i-1].x){
            int cnt=0, bot;
            for (auto [y,cc,_,__]:curr){
                if (cnt==0) bot=y;
                cnt+=2*cc-1;
                if (cnt==0) ans+=1LL*(x-eve[i-1].x)*(y-bot); 
            }
        }
        if (c){
            curr.insert({l,1});
            curr.insert({r,0});
        }
        else {
            curr.erase(curr.lower_bound({l,1}));
            curr.erase(curr.lower_bound({r,0}));
        }
    }
    if (ans%100==0) cout << ans/100 << '\n';
    else cout << fixed << setprecision(2) << (double)ans/100 << '\n';
}