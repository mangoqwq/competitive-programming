#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=2e5+1;

double x[MAXN], y[MAXN], w[MAXN], h[MAXN], X, ans[MAXN];
vector<double> eve;

double distsq(double x1, double y1, double x2, double y2){
    return (x2-x1)*(x2-x1)+(y2-y1)*(y2-y1);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n >> X;
    for (int i=1;i<=n;++i){
        cin >> x[i] >> y[i] >> w[i] >> h[i];
    }
    for (int i=1;i<=n;++i){
        for (int j=i+1;j<=n;++j){
            double lo=0, hi=X, mid;
            for (int _=1;_<=50;++_){
                mid=(lo+hi)/2;
                if ((distsq(x[i],y[i],mid,0)>distsq(x[j],y[j],mid,0))^(x[i]<x[j])) lo=mid;
                else hi=mid;
            }
            eve.push_back(mid-(1e-9));
        }
    }
    double last=0;
    eve.push_back(X);
    sort(eve.begin(),eve.end());
    for (auto pos:eve){
        int best=1;
        for (int i=2;i<=n;++i) if (distsq(x[i],y[i],pos,0)<distsq(x[best],y[best],pos,0)) best=i;
        ans[best]+=(pos-last)*100/X;
        last=pos;
    }
    double eps=1e-12;
    for (int i=n;i>=1;--i){
        for (int j=1;j<i;++j){
            if (abs(x[i]-x[j])<eps&&abs(y[i]-y[j])<eps){
                ans[j]+=ans[i];
                ans[i]=0;
                break;
            }
        }
    }
    for (int i=1;i<=n;++i){
        cout << fixed << setprecision(14) << ans[i] << '\n';
    }
}