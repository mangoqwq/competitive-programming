#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=3e3+5;

double eps=1e-7;
double x[MAXN], y[MAXN];
double dist(int i, int j){
    return sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j]));
}
double angle(int i, int j){
    return atan2(y[j]-y[i],x[j]-x[i]);
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    for (int _=1;_<=t;++_){
        cin >> x[0] >> y[0];
        int n, d; cin >> d >> n;
        for (int i=1;i<=n;++i) cin >> x[i] >> y[i];
        int ans=0;
        vector<double> vec;
        for (int i=1;i<=n;++i){
            int a=0, b=1;
            vec.clear();
            for (int j=1;j<=n;++j){
                if ((abs(angle(0,i)-angle(0,j))<=eps)&&dist(0,j)<=d+eps) a++;
            }
            double ang=angle(0,i);
            x[n+1]=x[0]+cos(ang)*d;
            y[n+1]=y[0]+sin(ang)*d;
            bool on=abs(dist(0,i)-d)<=eps;
            for (int j=1;j<=n;++j){
                if (on&&j==i) continue;
                vec.push_back(angle(n+1,j));
            }
            int curr=1;
            sort(vec.begin(),vec.end());
            for (int j=1;j<vec.size();++j){
                if (abs(vec[j]-vec[j-1])<=eps) curr++;
                else curr=1;
                b=max(b,curr);
            }
            b+=on;
            ans=max(ans,a*b);
            // cout << a << " " << b << '\n';
        }
        cout << "Case #" << _ << ": " << ans << '\n';
    }
}