#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=18;

int arr[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int r, c; cin >> r >> c;
    char a;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            cin >> a;
            if (a=='X') arr[i]+=(1<<j);
        }
    }
    int ans=0x3f3f3f3f;
    for (int mask=0;mask<(1<<c+1);mask+=2){
        int dist=0, curr=mask, last, nxt=arr[1];
        for (int i=1;i<=r;++i){    
            last=curr, curr=nxt, nxt=arr[i+1];
            for (int j=1;j<=c;++j){
                if (1&(last>>j)){
                    curr^=1<<j-1;
                    curr^=1<<j;
                    curr^=1<<j+1;
                    last^=1<<j;
                    nxt^=1<<j;
                    dist++;
                }
            }
        }
        
        if ((curr&((1<<c+1)-2))==0) ans=min(ans,dist);
    }
    if (ans==0x3f3f3f3f) cout << "Damaged billboard." << '\n';
    else cout << "You have to tap " << ans << " tiles." << '\n';

}