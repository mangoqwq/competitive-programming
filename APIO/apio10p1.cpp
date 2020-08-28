#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

ll arr[MAXN], dp[MAXN], tot;

struct Line{
    ll m,b;
    ll eval(const ll &x){ return m*x+b; }
    double sect(const Line &x){ return ((double)(x.b-b))/(m-x.m); }
}curr;
deque<Line> q; 
// front of q has steeper lines

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    ll a,b,c; cin >> a >> b >> c;
    for (int i=1;i<=n;++i) cin >> arr[i];
    q.push_back({0,0});
    for (int i=1;i<=n;++i){
        tot+=arr[i];
        while (q.size()>=2 && q[q.size()-1].eval(tot) <= q[q.size()-2].eval(tot)) q.pop_back();
        dp[i]=q.back().eval(tot)+a*tot*tot+b*tot+c;
        curr={-2*tot*a,a*tot*tot-b*tot+dp[i]};
        while (q.size()>=2 && q[0].sect(curr) <= q[0].sect(q[1])) q.pop_front();
        q.push_front(curr);
        //cout << dp[i] << " ";
    }
    cout << dp[n] << '\n';
}