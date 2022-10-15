#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e4+1;

struct Query{int l,r,t;};
int n,q,t[MAXN],val[MAXN];
ll ans;
int l[MAXN][101],r[MAXN][101];

void solve(int start, int end, vector<Query> &queries){
    if (start>end||queries.empty()) return;
    int mid=(start+end)/2;
    vector<Query> qleft,qright,arr;
    for (Query x:queries){
        if (x.r<mid) qleft.push_back(x);
        else if (x.l>mid) qright.push_back(x);
        else arr.push_back(x);
    }
    ms(l[0],0); ms(r[0],0); for (int i=t[mid];i<=100;++i) l[0][i]=val[mid];
    for (int i=1,idx=mid-1;idx>=start;--idx,++i){
        for (int k=100;k>=t[idx];--k) l[i][k]=max(l[i-1][k],l[i-1][k-t[idx]]+val[idx]);
        for (int k=t[idx]-1;k>=0;--k) l[i][k]=l[i-1][k];
    }
    for (int i=1,idx=mid+1;idx<=end;++idx,++i){
        for (int k=100;k>=t[idx];--k) r[i][k]=max(r[i-1][k],r[i-1][k-t[idx]]+val[idx]);
        for (int k=t[idx]-1;k>=0;--k) r[i][k]=r[i-1][k];
    }
    for (Query x:arr){
        int uwu=0;
        for (int i=0;i<=x.t;++i){ uwu=max(uwu,l[mid-x.l][i]+r[x.r-mid][x.t-i]);}
        ans+=uwu;
    }
    solve(start,mid-1,qleft);
    solve(mid+1,end,qright);
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n; 
    for (int i=1;i<=n;++i) cin >> t[i] >> val[i]; 
    vector<Query> queries;
    cin >> q;
    for (int i=0,a,b,c;i<q;++i){
        cin >> a >> b >> c;
        queries.push_back({a,b,c});
    }
    solve(1,n,queries);
    cout << ans << '\n';
}