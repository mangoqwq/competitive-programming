#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=3010;

ll bit[MAXN][MAXN];
ll arr[MAXN][MAXN];
int m, n; 

void Update(int r, int c, int x){
    for (int i=r;i<=m;i+=i&-i){
        for (int j=c;j<=n;j+=j&-j){
            bit[i][j]+=x;
        }
    }
}

ll Query(int r, int c){
    ll ret=0;
    for (int i=r;i>0;i-=i&-i){
        for (int j=c;j>0;j-=j&-j){
            ret+=bit[i][j];
        }
    }
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> m >> n;
    while (true){
        int cmd; cin >> cmd;
        if (cmd==0) break;
        if (cmd==1){
            int r, c, x; cin >> r >> c >> x;
            if ((r+c)%2) x=-x;
            Update(r,c,-arr[r][c]);
            Update(r,c,x); arr[r][c]=x;
        }
        if (cmd==2){
            int r1, c1, r2, c2; cin >> r1 >> c1 >> r2 >> c2;
            ll ans=Query(r2,c2)-Query(r1-1,c2)-Query(r2,c1-1)+Query(r1-1,c1-1);
            if ((r1+c1)%2) ans=-ans;
            cout << ans << '\n';
        }
    }
}