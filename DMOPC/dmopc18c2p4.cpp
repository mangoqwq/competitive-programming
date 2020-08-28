#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

queue<ll> q;
int n,pl=0,ans=0x3f3f3f3f;
ll m,tot,a;

int main(){
    cin.tie(0)->sync_with_stdio(0);
     cin >> n >> m;
    for (int i=1;i<=n;++i){
        cin >> a;
        tot+=a; q.push(a);
        while (tot>=m){
            ans=min(ans,i-pl);
            pl++; tot-=q.front(); q.pop();
        }
    }
    cout << (ans==0x3f3f3f3f?-1:ans) << '\n';
}