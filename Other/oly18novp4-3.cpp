#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// sparse table with O(1) query

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=100'001,K=18;

int sparse[MAXN][K],n,q;
int logs[MAXN];

void build(){
    for (int k=1;k<K;++k){
        for (int i=1;i+(1<<k)<=n+1;++i){
            sparse[i][k]=max(sparse[i][k-1],sparse[i+(1<<(k-1))][k-1]);
        }
    }
    for (int i=0;i<=n;++i){
        logs[i]=log2(i);
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n;++i){ cin >> sparse[i][0]; }
    build();
    int l,r,temp;
    while (q--){
        cin >> l >> r;
        temp=logs[r-l+1];
        cout << max(sparse[l][temp],sparse[r-(1<<temp)+1][temp])<< '\n';
    }
}