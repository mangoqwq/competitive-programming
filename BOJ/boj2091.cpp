#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=10001;

int denom[]={1,5,10,25};
struct Item{
    int a, b, c, d;
    ll tot() const{ return 0LL+a+b+c+d; }
    bool operator<(const Item &x) const{
        return tot()<x.tot();
    }
    Item operator+(const Item &x) const{
        return {a+x.a,b+x.b,c+x.c,d+x.d};
    }
} dp[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int cost; cin >> cost;
    ms(dp,-0x3f); dp[0]={0,0,0,0};
    for (int i=0;i<4;++i){
        int c; cin >> c;
        vector<int> vec;
        for (int j=1;j<(1<<14);j<<=1){
            if (c>j) c-=j, vec.push_back(j);
        }
        vec.push_back(c);
        for (int cnt:vec){
            int w=cnt*denom[i];
            Item v={0,0,0,0};
            if (i==0) v.a=cnt;
            if (i==1) v.b=cnt;
            if (i==2) v.c=cnt;
            if (i==3) v.d=cnt;
            for (int j=cost;j>=w;--j) dp[j]=max(dp[j],dp[j-w]+v);
        }
    }
    Item ans=dp[cost];
    if (ans.tot()<=0) cout << "0 0 0 0" << '\n';
    else cout << ans.a << " " << ans.b << " " << ans.c << " " << ans.d << '\n';
}