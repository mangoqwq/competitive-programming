#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e5+1;

int n,k;
struct Line{
    double m,b; int cnt;
    double eval(double x){
        return m*x+b;
    }
    double sect(Line x){
        return (x.b-b)/(m-x.m);
    }
} curr;
deque<Line> q;

pair<int,double> check(double c){
    q.clear();
    q.push_back({0,1-c,0});
    int val=0; double ans=0;
    for (int i=1;i<=n;++i){
        while (q.size()>=2&&q[q.size()-1].eval(1.0/i)<=q[q.size()-2].eval(1.0/i)) q.pop_back();
        val=q.back().cnt+1; ans=q.back().eval(1.0/i);
        curr={-(double)i,q.back().eval(1.0/i)+1-c,val};
        while (q.size()>=2&&q[0].sect(curr)>=q[0].sect(q[1])) q.pop_front();
        q.push_front(curr);
    }
    return {val,ans};
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> n >> k;
    double l=0,r=1;
    while (abs(r-l)>0.00000000001){
        double mid=(l+r)/2;
        pair<int,double> temp=check(mid);
        //cout << setprecision(9) << mid << " " << check(mid).first << " " << check(mid).second << '\n';
        if (temp.first>=k) l=mid;
        else if (temp.first<k) r=mid;
    }
    cout << setprecision(13) << check(l).second+l*k << '\n';
}