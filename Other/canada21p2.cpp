#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=101;

struct Item{ int c[3], id; };
queue<Item> q;
int ans[MAXN][MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i=1;i<=n;++i){
        int a, b, c; cin >> a >> b >> c;
        q.push({{a,b,c},i});
        ans[a][b][c]=i;
    }
    while (!q.empty()){
        auto [arr,id]=q.front(); q.pop();
        auto [a,b,c]=arr;
        for (int i=0;i<=2;++i){
            for (int j=-1;j<=1;++j){
                if (j==0) continue;
                if (arr[i]+j<0||arr[i]+j>100) continue;
                arr[i]+=j;
                if (!ans[arr[0]][arr[1]][arr[2]]){
                    ans[arr[0]][arr[1]][arr[2]]=id;
                    q.push({{arr[0],arr[1],arr[2]},id});
                }
                arr[i]-=j;
            }
        }
    }
    while (k--){
        int a, b, c; cin >> a >> b >> c;
        cout << ans[a][b][c] << '\n';
    }
}