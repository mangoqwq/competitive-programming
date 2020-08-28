#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=30'001;

int arr[MAXN];
struct Circle{
    int x,y,r,b;
    void upd(int pos){
        int rhs=r*r-(pos-x)*(pos-x);
        if (rhs<0) return;
        if (rhs==0){
            arr[y]+=b;
            arr[y+1]-=b;
        }
        else{
            int l=ceil((-sqrt(rhs)+(double)y));
            int r=ceil((sqrt(rhs)+(double)y+0.000001));
            if (l<=0) l=0;
            arr[l]+=b;
            if (r<MAXN) arr[r]-=b;
        }
    }
};
vector<Circle> shops;

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int m,n,k; cin >> m >> n >> k;
    for (int i=0,a,b,c,d;i<k;++i){
        cin >> a >> b >> c >> d;
        shops.push_back({a,b,c,d});
    }
    pii ans={0,0};
    for (int c=1;c<=n;++c){
        ms(arr,0);
        for (Circle x:shops) x.upd(c);
        int val=arr[0];
        for (int i=1;i<=m;++i){
            val+=arr[i];
            if (val>ans.first) ans={val,1};
            else if (val==ans.first) ans.second++;
        }
    }
    cout << ans.first << '\n' << ans.second << '\n';
}