#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

char _0, _1, _2;
struct Item{
    ll x; int c;
    bool operator<(Item a){
        return make_pair(x,c)<make_pair(a.x,a.c);
    }
}; vector<Item> eve;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, m; cin >> n >> m;
    for (int i=1;i<=n;++i){
        ll a, b, c, d, l, r;
        cin >> a >> _0 >> b >> _1 >> c >> _2 >> d;
        l=a*256*256*256+b*256*256+c*256+d;
        cin >> _0;
        cin >> a >> _0 >> b >> _1 >> c >> _2 >> d;
        r=a*256*256*256+b*256*256+c*256+d;
        eve.push_back({min(l,r),0});
        eve.push_back({max(l,r),2});
    }
    for (int i=1;i<=m;++i){
        ll a, b, c, d, x;
        cin >> a >> _0 >> b >> _1 >> c >> _2 >> d;
        x=a*256*256*256+b*256*256+c*256+d;
        eve.push_back({x,1});
    }
    sort(eve.begin(),eve.end());
    int ans=0, in=0;
    for (Item x:eve){
        if (x.c==1) ans+=in>0;
        if (x.c==0) in++;
        if (x.c==2) in--;
    }
    cout << ans << '\n';
}