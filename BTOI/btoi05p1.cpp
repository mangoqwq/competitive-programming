#include <bits/stdc++.h>

#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
using namespace std;
#define ms(x,a) memset(x, a, sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1001;

int arr[MAXN][MAXN], val[MAXN][MAXN];
struct Query{
    int x, y, r, c, a, b; 
} q[MAXN];

int get(int x1, int y1, int x2, int y2){
    return arr[x2][y2]-arr[x2][y1-1]-arr[x1-1][y2]+arr[x1-1][y1-1];
}

int main(){
    int r, c; scan(r); scan(c);
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            scan(arr[i][j]);
            arr[i][j]+=arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    int l, w; scan(l); scan(w);
    int h; scan(h);
    int best=0; pair<int,int> ans={1,1};
    for (int i=1,x,y,dx,dy,sx,sy,a,b;i<=h;++i){
        scan(x); scan(y); scan(dx); scan(dy); scan(a); scan(b);
        if (a) sx=dx, sy=0; 
        else sy=dy, sx=0;
        for (int i=1;i+l-1<=r;++i){
            for (int j=1;j+w-1<=c;++j){
                val[i][j]+=(get(i+x-1, j+y-1, i+x+dx-2, j+y+dy-2) < get(i+x-1+sx, j+y-1+sy, i+x+dx-2+sx, j+y+dy-2+sy))^b;
            }   
        }
    }
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            if (val[i][j]>best) ans={i,j}, best=val[i][j];
        }
    }
    cout << ans.first << " " << ans.second << '\n';
}