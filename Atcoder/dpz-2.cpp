#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

ll h[MAXN], dp[MAXN];
deque<int> q;

double f(int j, int k){ // k is better than j when <= ret
    return (double)(h[k]*h[k]+dp[k]-h[j]*h[j]-dp[j])/(2.0*(h[k]-h[j]));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; ll c; cin >> n >> c;
    for (int i=1;i<=n;++i) cin >> h[i];y
    dp[1]=0; q.push_back(1);
    for (int i=2;i<=n;++i){
        while (q.size()>=2 && f(q[0],q[1])<=h[i]) q.pop_front();
        dp[i]=dp[q[0]]+(h[q[0]]-h[i])*(h[q[0]]-h[i])+c;
        while (q.size()>=2 && f(q[q.size()-2],q.back())>=f(q.back(),i)) q.pop_back();
        q.push_back(i);
    }
    cout << dp[n] << '\n';
}