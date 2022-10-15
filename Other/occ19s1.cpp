#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=0;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int x1, y1, x2, y2, x3, y3, x4, y4;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    x1=min(a,c), x2=max(a,c), y1=min(b,d), y2=max(b,d);
    cin >> a >> b >> c >> d;
    x3=min(a,c), x4=max(a,c), y3=min(b,d), y4=max(b,d);
    x2--, y2--, x4--, y4--;
    int ans=0;
    for (int i=1;i<=1000;++i){
        for (int j=1;j<=1000;++j){
            if ((x1<=i&&i<=x2&&y1<=j&&j<=y2)||(x3<=i&&i<=x4&&y3<=j&&j<=y4))
                ans++;
        }
    }
    cout << ans << '\n';
}