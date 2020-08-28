#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1001;

bool fr[MAXN], fc[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r,c; cin >> r >> c; char a;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            cin >> a;
            if (a=='X') fr[i]=1, fc[j]=1;
        }
    }
    int q,x,y; cin >> q;
    while (q--){
        cin >> x >> y;
        cout << (fr[y]|fc[x]?'Y':'N') << '\n';
    }

}