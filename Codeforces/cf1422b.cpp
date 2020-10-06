#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101;

ll arr[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int n, m; cin >> n >> m;
        ll ans=0;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                cin >> arr[i][j];
            }
        }
        vector<int> ree;
        for (int i=1;i<=n;++i){
            for (int j=1;j<=m;++j){
                ree.clear();
                ree.push_back(arr[i][j]);
                ree.push_back(arr[n-i+1][j]);
                ree.push_back(arr[i][m-j+1]);
                ree.push_back(arr[n-i+1][m-j+1]);
                sort(ree.begin(),ree.end());
                ll mid=ree[2];
                ans+=abs(arr[i][j]-mid); arr[i][j]=mid;
                ans+=abs(arr[n-i+1][j]-mid); arr[n-i+1][j]=mid;
                ans+=abs(arr[i][m-j+1]-mid); arr[i][m-j+1]=mid;
                ans+=abs(arr[n-i+1][m-j+1]-mid); arr[n-i+1][m-j+1]=mid;
                //cout << arr[i][j] << " ";
            }
            //cout << '\n';
        }
        cout << ans << '\n';
    }
}