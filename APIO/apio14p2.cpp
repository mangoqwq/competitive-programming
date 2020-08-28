#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1,MAXK=201;

struct Line{
    ll m,b; int idx;
    ll eval(const ll &x){ return m*x+b; }
    double sect(const Line &x){ return ((double)(b-x.b))/((double)(x.m-m)); }
}temp;
deque<Line> q[MAXK];
ll arr[MAXN], ans, best=-1, tot, curr, dp;
int back[MAXN][MAXK];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,k; cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> arr[i], tot+=arr[i];
    q[0].push_back({0,0,0});
    for (int i=1;i<n;++i){
        curr+=arr[i];
        for (int j=k;j>=1;--j){
            deque<Line> &dq=q[j-1];
            if (dq.empty()) continue;
            while (dq.size()>=2 && dq[0].eval(curr)<=dq[1].eval(curr)) dq.pop_front();
            dp=dq[0].eval(curr)+curr*tot-curr*curr;
            if (j==k && dp>=best){ best=dp, ans=i; } 
            back[i][j]=dq[0].idx;
            temp={curr,-curr*tot+dp,i};
            while (q[j].size()>=2 && q[j][q[j].size()-2].sect(temp)<=q[j][q[j].size()-1].sect(q[j][q[j].size()-2])) q[j].pop_back();
            q[j].push_back(temp);
        }
    }
    cout << best << '\n';
    for (int i=ans,j=k;j>0;i=back[i][j],--j) cout << i << " ";
    cout << '\n';

}