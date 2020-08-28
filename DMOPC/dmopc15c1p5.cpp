#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=251;

int arr[MAXN][MAXN],w,h,n;

int query(int x1,int y1,int ww, int hh){
    int x2=min(w,x1+ww-1), y2=min(h,y1+hh-1);
    return arr[x2][y2]-arr[x1-1][y2]-arr[x2][y1-1]+arr[x1-1][y1-1];
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> w >> h >> n;
    for (int j=1,a;j<=h;++j){
        for (int i=1;i<=w;++i){
            cin >> a; 
            arr[i][j]=a+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    int ans=0;
    for (int j=1;j<=h;++j){
        for (int i=1;i<=w;++i){
            for (int len=1;len<=min(n,w);++len){
                ans=max(ans,query(i,j,len,n/len));
            }
        }
    }
    cout << ans << '\n';
}