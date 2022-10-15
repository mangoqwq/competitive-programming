#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=2e6+1;

// dp[i]=min(dp[j-1]+(pre[i]-pre[j-1]-L)^2);
// dp[i]= ((-2*pre[i]*L) + I**2 + L**2) + min(-2pre[j-1](pre[i]) + 2pre[j-1]*L + pre[j-1]**2 + dp[j-1])

struct Line{
    ll m,c;
    ll val(ll x){ return m*x+c; }
    ll sect(Line a){ return (a.c-c)/(m-a.m); }
};

ll arr[MAXN],pre[MAXN],dp[MAXN];
deque<Line> q;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n; ll L; cin >> n >> L; L++;
    for (int i=1;i<=n;++i){ cin >> arr[i]; arr[i]++; pre[i]=pre[i-1]+arr[i]; }
    q.push_front({0,0});
    Line uwu;
    for (int i=1;i<=n;++i){
        while (q.size()>=2&&q.back().val(pre[i])>=q[q.size()-2].val(pre[i])){
            q.pop_back();
        }
        dp[i] = min(((-2*pre[i]*L) + pre[i]*pre[i] + L*L) + q.back().val(pre[i]),(arr[i]-L)*(arr[i]-L)+dp[i-1]);
        uwu = {-2*pre[i-1],2*pre[i-1]*L + pre[i-1]*pre[i-1] + dp[i-1]};
        while (q.size()>=2&&q[0].sect(uwu)<=q[0].sect(q[1])){
            q.pop_front();
        }
        q.push_front(uwu);
        //cout << dp[i] << " " << q.back().m << " " << q.back().c << " | ";
    }
    cout << dp[n] << '\n';

}
