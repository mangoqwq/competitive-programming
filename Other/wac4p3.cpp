#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define isset(x,idx) ((x)&(1<<(idx)))
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=16;

struct uwu{double x,y,vx,vy;int id;};
struct Solve{
    int node; double posx,posy,t; int vis;
    bool operator<(const Solve &a) const {
        return t>a.t;
    }
};
priority_queue<Solve> pq;
int n; double s;
vector<uwu> arr;
double dp[65537][MAXN];

bool cmp(uwu a, uwu b){
    return a.id<b.id;
}

double dist(double x,double y,double posx, double posy){
    return sqrt((x-posx)*(x-posx)+(y-posy)*(y-posy));
}

void solve(int node, double posx, double posy, double t, int vis){
    double lo,hi,mid,diff;
    for (int k=1;k<arr.size();++k){
        uwu &x=arr[k];
        if (isset(vis,k)){
            continue;
        }
        lo=0;hi=(1e15)+5;
        for (int i=0;i<=100;++i){
            mid=(lo+hi)/2;
            diff=dist(x.x+(t+mid)*x.vx,x.y+(t+mid)*x.vy,posx,posy)-s*mid;
            if (abs(diff)<0.00001){
                break;
            }
            else if (diff>0){
                lo=mid+0.000001;
            }
            else{
                hi=mid+0.000001;
            }
        }
        if(t+mid<dp[vis|(1<<k)][k]) pq.push({k,x.x+(t+mid)*x.vx,x.y+(t+mid)*x.vy,t+mid,vis|(1<<k)});
    }
    dp[vis][node]=min(dp[vis][node],t);
}

int main(){
    //cin.tie(0); cin.sync_with_stdio(0);
    for (int i=0;i<65537;++i){
        for (int k=0;k<MAXN;++k){
            dp[i][k]=1e16;
        }
    }
    cin >> n >> s;
    arr.push_back({0,0,0,0});
    double a,b,c,d;
    for (int i=0;i<n;++i){
        cin >> a >> b >> c >> d;
        arr.push_back({a,b,c,d,i});
    }
    
    pq.push({0,0,0,0,1}); Solve curr;
    while (!pq.empty()){
        curr=pq.top(); pq.pop();
        if (abs(dp[curr.vis][curr.node]-1e16)>0.1) continue;
        solve(curr.node,curr.posx,curr.posy,curr.t,curr.vis);
    }
    double ans=1e16;
    for (int i=1;i<=n;++i){
        ans=min(ans,dp[(1<<(n+1))-1][i]);
    }
    cout << setprecision(10) << ans << '\n';

}