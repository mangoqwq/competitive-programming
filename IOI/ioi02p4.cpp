#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e4+1;

struct Line{
    int m,b;
    int val(int x){ return m*x+b; }
    double sect(Line x){
        return ((double)(b-x.b))/(x.m-m);
    }
} temp;
deque<Line> q;
int arr[MAXN],n,s,f[MAXN+1],dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> s;
    for (int i=1;i<=n;++i) cin >> arr[i] >> f[i];
    for (int i=n-1;i>=1;--i) f[i]+=f[i+1];
    int curr=0; q.push_back({f[1],s*f[1]});
    for (int i=1;i<=n;++i){
        curr+=arr[i];
        while (q.size()>=2 && q[0].val(curr)>=q[1].val(curr)) q.pop_front();
        dp[i]=q.front().val(curr);
        temp={f[i+1],-f[i+1]*curr+s*f[i+1]+dp[i]};
        while (q.size()>=2 && q[q.size()-1].sect(temp)<q[q.size()-1].sect(q[q.size()-2])) q.pop_back();
        q.push_back(temp);
        //cout << dp[i] << " ";
    }
    cout << dp[n] << '\n';

}