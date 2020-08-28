#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int n,K; 
ll bit[3001][3001]; ll arr[3001][3001];

ll query(int x,int y){
    ll ans=-1;
    for (int i=x;i>0;i-=i&-i){
        for (int k=y;k>0;k-=k&-k){
            ans=max(ans,bit[i][k]);
        }
    }
    return ans;
}
void update(int x,int y,ll val){
    for (int i=x;i<=3000;i+=i&-i){
        for (int k=y;k<=3000;k+=k&-k){
            bit[i][k]=max(bit[i][k],val);
        }
    }
}


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> K;
    for (int i=1;i<=n;++i){
        for (int k=n-i+1;k<=n;++k){
            cin >> arr[i][k];
        }
    }
    ll ans=0;
    for (int i=0;i<n;++i){
        for (int k=0;k<=i;++k){
            
            update(n-i+k,n-k,arr[n-i+k][n-k]);
        }
        int temp=i-K+1;
        for (int k=0;k<=temp;++k){
            ans+=query(n-temp+k,n-k);
        }
    }
    cout << ans << '\n';
}