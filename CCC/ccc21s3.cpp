#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, iinf=0x3f3f3f3f, MAXN=2e5+1;
const ll inf=0x3f3f3f3f3f3f3f3f;

struct Event{
    ll x, val;
    bool operator<(const Event&other) const{ return x<other.x; }
};
vector<Event> eve;
ll pos, curr, ans, l, r;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    pos=-iinf;
    for (int i=1;i<=n;++i){
        ll x, w, d; cin >> x >> w >> d;
        curr+=(x-d-pos)*w;
        eve.push_back({x-d,-w});
        eve.push_back({x+d,w});
        r+=w;
    }
    ans=curr;
    sort(eve.begin(),eve.end());
    for (auto a:eve){
        curr+=(a.x-pos)*(l-r);
        ans=min(ans,curr);
        pos=a.x;
        if (a.val<0) r+=a.val;
        else l+=a.val;
    }
    cout << ans << '\n';
}