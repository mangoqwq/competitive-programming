#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

// The full solution: 1≤n≤100,000, 1≤m≤1,000,000.
// Optimize O(n^2k) solution from subtask 3 to with cht to get O(nk)
// Use wqs to knockout dimension k to get O(nlogn)
// :(( transition is so long :notlikeblob:

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
template <class T>
constexpr T sq(T x){return x*x;}
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+5,MAXM=1e6+5;
const ll inf=0x3f3f3f3f3f3f3f3f;

struct Line{
    ll m,b; int cnt;
    ll val(ll x){ return m*x+b; }
    long double sect(Line x){
        return (((long double)(b-x.b))/(x.m-m));
    }
} curr;
struct Point{
    ll r,c;
    bool operator<(Point &a) const{
        return make_pair(c,MAXM-r)<make_pair(a.c,MAXM-a.r);
    }
} a[MAXN];
ll dp[MAXN]; int n, cnt[MAXN];

int solve(ll lambda){
    deque<Line> q; // steeper lines in front
    q.push_back({-2*a[1].r, /*intersection*/ sq(a[1].r) - (2*a[1].r) + lambda, 0});
    ll c;
    for (int i=1;i<=n;++i){
        c=a[i].c;
        while (q.size()>=2 && q[q.size()-2].val(c) < q[q.size()-1].val(c) ) q.pop_back();

        dp[i]=q.back().val(c)+(c*c)+(2*c)+1; 
        cnt[i]=q.back().cnt+1;
        curr={-2*a[i+1].r, (dp[i]) - sq(max(a[i].c-a[i+1].r+1,(ll)0)) + sq(a[i+1].r) - (2*a[i+1].r) + lambda, cnt[i]};

        while (q.size()>=2 && q[0].sect(curr) <= q[0].sect(q[1]) ) q.pop_front();
        q.push_front(curr);
    }
    return cnt[n];
}

ll take_photos(int nn, int m, int k, int* r, int* c){
    vector<Point> arr;
    for (int i=0;i<nn;++i){ // reflect all points above diagonal
        if (r[i]>c[i]) arr.push_back({c[i]+1,r[i]+1});
        else arr.push_back({r[i]+1,c[i]+1}); 
    }
    sort(arr.begin(),arr.end()); int idx=0;
    for (int i=0;i<nn;++i){
        // remove neglectable points
        while (idx!=0 && a[idx].r>=arr[i].r && a[idx].c<=arr[i].c){
            idx--;
        }
        a[++idx]=arr[i];
    }
    n=idx;
    ll low=0, high=1e12, mid, ans=inf;
    while (low<high){
        mid=(low+high)>>1;
        int tmp=solve(mid);
        if (tmp<=k) high=mid;
        else low=mid+1;
    }
    solve(low);
    return dp[n]-k*low;
}