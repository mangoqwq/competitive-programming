#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int t[100001], dp[100001];


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m,j; cin >> n >> m >> j;
    memset(t,0x3f,sizeof t); t[0]=0;
    for (int i=0,a,b;i<m;++i){
        cin >> a >> b;
        t[a]=b;
    }
    deque<pii> q;
    q.push_front({0,n+1});
   
    for (int i=n;i>=0;--i){
        if (!q.empty()){
            if (q.front().second-i>j){
                q.pop_front();
            }
        }
        dp[i]=max(t[i],q.front().first);
        while (!q.empty()){
            if (q.back().first>=dp[i]){
                q.pop_back();
            }else{break;}
        }
        q.push_back({dp[i],i});
    }
    if (dp[0]==0x3f3f3f3f) cout << -1 << '\n';
    else cout << dp[0] << '\n';


}