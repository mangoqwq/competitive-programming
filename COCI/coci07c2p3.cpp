#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

int r,c;
string uwu,ans;
char arr[22][22];

void solve(int i, int j, int dir){
    if (arr[i][j]=='#'){
        if (uwu.size()>=2 && uwu<=ans) ans=uwu;
        return;
    }
    uwu+=arr[i][j];
    if (dir==0) solve(i+1,j,0);
    if (dir==1) solve(i,j+1,1);
}


int main(){
    cin.tie(0)->sync_with_stdio(0);
    ans="zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
    for (int i=0;i<=21;++i){
        for (int j=0;j<=21;++j){
            arr[i][j]='#';
        }
    }
    cin >> r >> c;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            cin >> arr[i][j];
        }
    }
    for (int i=0;i<=r;++i){
        for (int j=0;j<=c;++j){
            if (arr[i][j]=='#'){
                uwu=""; solve(i+1,j,0);
                uwu=""; solve(i,j+1,1);
            }
        }
    }
    cout << ans << '\n';
}