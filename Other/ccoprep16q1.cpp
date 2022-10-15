#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1001;

int last[MAXN];
struct Item{ int x,idx; } s[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    while (t--){
        int r,c; cin >> r >> c;
        for (int i=1;i<=r;++i) last[i]=0;
        int ans=0; char a;
        for (int row=1,d;row<=r;++row){
            int p=1,old;
            for (int i=1;i<=c;++i){
                cin >> a;
                if (a=='R') last[i]=row;
                d=row-last[i];
                old=i;
                while (p!=1&&s[p-1].x>d) ans=max((i-s[p-1].idx)*s[p-1].x,ans), old=s[p-1].idx, p--;
                s[p]={d,old}; p++;
            }
            d=0;
            while (p!=1&&s[p-1].x>d) ans=max(((c+1)-s[p-1].idx)*s[p-1].x,ans), p--;
        }
        cout << ans*3 << '\n';
    }
}