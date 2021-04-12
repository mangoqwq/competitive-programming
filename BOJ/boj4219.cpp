#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
const int MAXN=1005;

int n, m, k, q; 
int arr[3*MAXN][MAXN], a[3*MAXN][MAXN], d1[3*MAXN][MAXN], d2[3*MAXN][MAXN];

int get(int id, int x, int y){
    if (y<=0){
        x-=(1-y), y+=(1-y);
        if (id==2) return 0;
    }
    if (y>=m+1){
        x-=(y-m), y-=(y-m);
        if (id==3) return 0;
    }
    if (x<=0) return 0;
    if (id==0) return arr[x][y];
    if (id==1) return a[x][y];
    if (id==2) return d1[x][y];
    if (id==3) return d2[x][y];
    assert(false);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int ___=0;
    while (true){
        ms(arr,0), ms(a,0), ms(d1,0), ms(d2,0);
        cin >> n >> m >> k >> q;
        if (n==0) break;
        ___++;
        cout << "Case " << ___ << ":" << '\n';
        for (int i=1;i<=k;++i){
            int r, c; cin >> r >> c;
            arr[r][c]++;
        }
        for (int j=1;j<=m;++j) a[1][j]=d1[1][j]=d2[1][j]=arr[1][j];
        for (int i=2;i<=n+n+m;++i){
            for (int j=1;j<=m;++j){
                a[i][j]=arr[i][j]+arr[i-1][j]+get(1,i-1,j-1)+get(1,i-1,j+1)-get(1,i-2,j);
                d1[i][j]=arr[i][j]+get(2,i-1,j-1);
                d2[i][j]=arr[i][j]+get(3,i-1,j+1);
            }
        }
        while (q--){
            int d; cin >> d; d=min(d,n+m);
            int ax=1, ay=1, ans=0;
            for (int j=1;j<=m;++j){
                for (int i=1;i<=n;++i){
                    int curr=get(1,i+d,j)-get(1,i-1,j-d)-get(1,i-1,j+d)+get(1,i-d-1,j)-get(2,i-1,j-d-1)-get(3,i-1,j+d+1);
                    if (curr>ans) ans=curr, ax=i, ay=j;
                }
            }
            cout << ans << " " << "(" << ax << "," << ay << ")" << '\n';
        }
    }
}