#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5001;

int pre[MAXN*MAXN];
int ans[MAXN*MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int r,c,q; cin >> r >> c >> q;
    int start,end;
    for (int x=1;x<=r;++x){
        for (int y=1;y<=c;++y){
            start=x*y;
            end=r*c-(r-x+1)*(c-y+1)+1;
            pre[start]++; pre[end+1]--;
        }
    }
    int curr=0;
    for (int i=1;i<=r*c;++i) curr+=pre[i], ans[i]=curr;
    for (int _=0,x;_<q;++_){
        cin >> x;
        cout << ans[x] << '\n';
    }
}