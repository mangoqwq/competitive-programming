#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

int arr[MAXN], ans[MAXN]; 

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i) cin >> arr[i];
    sort(arr+1,arr+1+n,greater<int>()); 
    queue<int> q;
    int p=2, cnt=0; ans[1]=arr[1];
    for (int i=2;i<=n;++i){
        if (!q.empty() && ans[p-1]>arr[i] && q.front()>arr[i]){
            ans[p++]=arr[i], ans[p++]=q.front(), q.pop();
            cnt++;
        }
        else q.push(arr[i]);
    }
    while (!q.empty()) ans[p++]=q.front(), q.pop();
    cout << cnt << '\n';
    for (int i=1;i<=n;++i) cout << ans[i] << " ";
}