#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1, MAXK=2e5+1;

int a[MAXK], b[MAXK];
int arr[MAXN];
set<int> vis[MAXN];
int ans[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    ll n, k, m; cin >> n >> k;
    m=LLONG_MAX;
    for (int i=0;i<k;++i){
        cin >> a[i] >> b[i];
    }
    if (n<=100&&k<=200){
        for (int i=1;i<=n;++i){
            set<int> s;
            ll t=m, idx=0, pos=i;
            s.insert(pos);
            while (t){
                t--;
                if (pos==a[idx]) pos=b[idx];
                else if (pos==b[idx]) pos=a[idx];
                s.insert(pos);
                idx++; idx%=k;
                if (idx==0&&i==pos) break;
            }
            cout << s.size() << '\n';
        }
        return 0;
    }
    for (int i=1;i<=n;++i){
        vis[i].insert(i);
        arr[i]=i;
    }
    for (int i=0;i<k;++i){
        vis[arr[a[i]]].insert(b[i]);
        vis[arr[b[i]]].insert(a[i]);
        swap(arr[a[i]],arr[b[i]]);
    }
    set<int> s;
    for (int i=1;i<=n;++i){
        if (ans[i]) continue;
        s.clear();
        for (int j=i;;){
            if (vis[j].size()>s.size()) swap(vis[j],s);
            for (int x:vis[j]) s.insert(x);
            j=arr[j];
            if (j==i) break;
        }
        for (int j=i;;){
            ans[j]=s.size();
            j=arr[j];
            if (j==i) break;
        }
    }
    for (int i=1;i<=n;++i) cout << ans[i] << '\n';   
}