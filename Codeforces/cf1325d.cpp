#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define isset(x,idx) ((x)&((ll)1<<idx))!=0
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=63;

int bx[MAXN],ba[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    ll x,a; cin >> x >> a;
    for (int i=0;i<MAXN;++i){
        bx[i]=isset(x,i);
        ba[i]=isset(a,i);
    }
    for (int i=MAXN-1;i>0;--i){
        if ((bx[i]+ba[i])%2==0){
            continue;
        }
        if (ba[i]==0){
            cout << bx[i] << " ";
            cout << -1 << '\n';
            return 0;
        }
        ba[i]--; ba[i-1]+=2;
        cout << ba[i];
    }
    if ((bx[0]+ba[0])%2!=0){
        cout << -1 << '\n';
        return 0;
    }
    int cnt=0,len=-1;
    for (int i=0;i<MAXN;++i){
        cnt+=ba[i];
        len=max(len,ba[i]);
    }
    cout << len << '\n';
    ll temp;
    while (cnt!=0){
        temp=0;
        for (int i=0;i<MAXN;++i){
            if (ba[i]==0) continue;
            ba[i]--; cnt--;
            temp+=((ll)1<<i);
        }
        cout << temp << " ";
    }
}