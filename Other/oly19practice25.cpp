#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5001;

ll arr[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n,m,k; cin >> n >> m >> k;
    for (int i=0,a,b,c,d;i<k;++i){
        cin >> a >> b >> c >> d;
        arr[a][b]++; arr[c+1][d+1]++;
        arr[a][d+1]--; arr[c+1][b]--;
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            arr[i][j]=arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
    }
    for (int i=1;i<=n;++i){
        for (int j=1;j<=m;++j){
            arr[i][j]=arr[i][j]+arr[i-1][j]+arr[i][j-1]-arr[i-1][j-1];
        }
        //cout << '\n';
    }
    int q; cin >> q;
    for (int i=0,a,b,c,d;i<q;++i){
        cin >> a >> b >> c >> d;
        cout << arr[c][d]-arr[c][b-1]-arr[a-1][d]+arr[a-1][b-1] << '\n';
    }
}