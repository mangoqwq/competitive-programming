#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int bit[MAXN], used[MAXN];

int Query(int idx){
    int ret=0;
    for (int i=idx;i>=1;i-=i&-i) ret+=bit[i];
    return ret;
}

void Update(int idx, int val){
    for (int i=idx;i<MAXN;i+=i&-i) bit[i]+=val;
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,l,r;i<=n;++i){
        cin >> l >> r;
        int ansl=Query(l)-used[l];
        int ansr=Query(r)-used[r];
        cout << ansl+ansr << '\n';
        used[l]+=ansl, used[r]+=ansr;
        Update(r,-1);
        Update(l+1,1);
    }
}