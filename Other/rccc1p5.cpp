#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=5e5+1;

int a[MAXN];

void ins(int x){ for (int i=x;i<MAXN&&i!=0;i+=i&-i) a[i]^=x; }
int qry(int i){
    int ret=0;
    for (;i>0;i-=i&-i) ret^=a[i];
    return ret;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, q; cin >> n >> q;
    if (n<=2000&&q<=2000){
        for (int i=1,x;i<=n;++i) cin >> x, a[x]^=1;
        while (q--){
            int op, l, r, x;
            cin >> op;
            if (op==1){
                cin >> x;
                a[x]^=1;
            }
            if (op==2){
                cin >> l >> r >> x;
                vector<int> v;
                for (int i=l;i<=r;++i) if (a[i]) v.push_back(i^x), a[i]=0;
                for (int aa:v) a[aa]^=1;
            }
            if (op==3){
                cin >> l >> r;
                int ret=0;
                for (int i=l;i<=r;++i) if (a[i]) ret^=i;
                cout << ret << '\n';
            }
        }
        return 0;
    }
    for (int i=1,x;i<=n;++i) cin >> x, ins(x);
    while (q--){
        int op, l, r, x;
        cin >> op;
        if (op==1){
            cin >> x;
            ins(x);
        }
        if (op==2){
            cin >> l >> r >> x;
        }
        if (op==3){
            cin >> l >> r;
            cout << (qry(r)^qry(l-1)) << '\n';
        }
    }
}