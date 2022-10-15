#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5e5+1,MAXQ=4e6+1;

int dp[MAXN],ans[MAXQ];
struct Query{
    int q,x,id;
    bool operator<(Query a){
        return q+x<a.q+a.x;
    }
};
vector<Query> qs;

void Insert(int x, int d){
    if (dp[x]!=-1) return;
    dp[x]=d;
    for (int i=0,mask;(1<<i)<=x;++i){
        mask=((x>>1)&~((1<<i)-1))|(((1<<i)-1)&(x));
        Insert(mask,d+1);
    }
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int q,l,r; cin >> q >> l >> r;
    for (int i=1,a,b;i<=q;++i){
        cin >> a >> b;
        qs.push_back({a,b,i});
    }
    sort(qs.begin(),qs.end());
    int p=l; ms(dp,-1);
    for (Query x:qs){
        while (p<=min(x.q+x.x,r)) Insert(p++,0);
        ans[x.id]=dp[x.q];
    }
    for (int i=1;i<=q;++i){
        cout << ans[i] << '\n';
    }
}