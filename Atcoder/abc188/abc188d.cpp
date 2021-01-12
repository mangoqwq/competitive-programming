#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=0;

struct Item{
    ll x, c, t;
    bool operator<(const Item &other) const{
        return x<other.x;
    }
};
vector<Item> eve;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, c; cin >> n >> c;
    for (int i=1;i<=n;++i){
        int a, b, x; cin >> a >> b >> x;
        eve.push_back({a,x,1});
        eve.push_back({b+1,x,2});
    }
    sort(eve.begin(),eve.end());
    ll curr=0, tot=0, last=0;
    for (Item x:eve){
        if (x.x!=last){
            tot+=min(curr,c)*(x.x-last);
            last=x.x;
        }
        if (x.t==1) curr+=x.c;
        else curr-=x.c;
    }
    cout << tot << '\n';
}