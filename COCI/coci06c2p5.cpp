#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=401;

int arr[MAXN][MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r,c; cin >> r >> c;
    char a;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            cin >> a;
            arr[i][j]=(a=='X')+arr[i][j-1];
        }
    }
    int ans=0,bot;
    for (int pl=1;pl<=c;++pl){
        for (int pr=pl;pr<=c;++pr){
            bot=-1;
            for (int row=1;row<=r;++row){
                if (arr[row][pr]-arr[row][pl-1]==0){
                    if (bot==-1) bot=row;
                    ans=max(ans,(row-bot+1+pr-pl+1)*2);
                }
                else bot=-1;
            }
        }
    }
    cout << ans-1 << '\n';
}