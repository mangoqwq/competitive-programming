#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// Convex Hull Trick

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

struct Line{
    ll m,c;
    ll val(ll x){ return m*x+c; }
    double sect(Line a){
        return (double) (c-a.c)/(a.m-m);
    }

};

ll dp[MAXN]; deque<Line> q; ll h[MAXN];
// front of queue will have lines with greater slope

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; ll c; cin >> n >> c;
    for (int i=1;i<=n;++i){ cin >> h[i]; }
    dp[1]=0; q.push_front({2*h[1],-h[1]*h[1]});
    Line temp;
    for (int i=2;i<=n;++i){
        while (q.size()>=2 && q.back().val(h[i]) <= q[q.size()-2].val(h[i])){
            q.pop_back();
        }
        //cout << q.back().val(h[i]) << " ";
        dp[i]=h[i]*h[i]+c-(q.back().val(h[i]));
        temp = {2*h[i],-h[i]*h[i]-dp[i]};
        while (q.size()>=2 && temp.sect(q.front())<=q.front().sect(q[1])){
            q.pop_front();
        }
        q.push_front(temp);
    }
    for (int i=1;i<=n;++i){
        //cout << dp[i] << " ";
    }
    cout << dp[n] << '\n';
}