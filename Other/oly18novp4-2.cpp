#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// sparse table with O(log(n)) query

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=100'001,K=18;

int sparse[MAXN][K],n,q;

void build(){
    for (int i=1;i<=K;++i){
        for (int k=1;k+(1<<i)<=n+1;++k){
            sparse[k][i]=max(sparse[k][i-1],sparse[k+(1<<(i-1))][i-1]);
        }
    }
}

int query(int l, int r){
    int ans=INT_MIN;
    for (int i=K;i>=0;--i){
        if (1<<i<=r-l+1){
            ans=max(ans,sparse[l][i]);
            l+=1<<i;
        }
    }
    return ans;
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n;++i){ cin >> sparse[i][0]; }
    build();
    int l,r;
    while (q--){
        cin >> l >> r;
        cout << query(l,r) << '\n';
    }
}