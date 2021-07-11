#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int n;
ll h[MAXN], dp[MAXN], c;
deque<int> q;
double slope(int k, int j){
    return (h[j]*h[j]-h[k]*h[k]+dp[j]-dp[k])/(2.0*(h[j]-h[k]));
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> c;
    cin >> h[1]; q.push_front(1);
    for (int i=2;i<=n;++i){
        cin >> h[i];
        while (q.size()>=2&&slope(q[q.size()-1],q[q.size()-2])<h[i]) q.pop_back();
        int j=q.back();
        dp[i]=(h[i]-h[j])*(h[i]-h[j])+dp[j]+c;
        while (q.size()>=2&&slope(q[1],q[0])>slope(q[0],i)) q.pop_front();
        q.push_front(i);
    }
    cout << dp[n] << '\n';
}