#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
int a[100001];
int pre[100001];
map<int,int> m;


int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,k; cin >> n >> k;
    int index;
    for (int i=1;i<=n;++i){
        cin >> a[i];
        if (a[i]==k){
            index=i;
            pre[i]=pre[i-1];
            continue;
        }
        pre[i]=pre[i-1]+((a[i]>k)*2-1);
    }
    for (int i=0;i<index;++i){
        m[pre[i]]++;
    }
    ll ans=0;
    for (int i=index;i<=n;++i){
        ans+=m[pre[i]];
    }
    cout << ans << '\n';
}