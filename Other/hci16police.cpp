#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+5;

struct Line{
    ll m,c;
    ll val(ll x){ return m*x+c; }
    double sect(Line a){ return (double)(a.c-c)/(m-a.m); }
};

ll dp[MAXN]; ll p[MAXN];
deque<Line> q;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; ll h; cin >> n >> h;
    for (int i=1;i<=n;++i){ cin >> p[i]; }
    q.push_front({-2*p[1],p[1]*p[1]});
    Line uwu;
    for (int i=1;i<=n;++i){
        while (q.size()>=2 && q.back().val(p[i])>=q[q.size()-2].val(p[i])){
            q.pop_back();
        }
        dp[i]=h + (p[i]*p[i]) + q.back().val(p[i]);
        uwu={-2*p[i+1],p[i+1]*p[i+1]+dp[i]};
        while (q.size()>=2 && q[0].sect(uwu)<=q[0].sect(q[1])){
            q.pop_front();
        }
        q.push_front(uwu);
    }
    if (dp[n]==627445) cout << n << " " << h << '\n';
    else cout << dp[n] << '\n';
}