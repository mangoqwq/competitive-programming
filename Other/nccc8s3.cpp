#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, inf=0x3f3f3f3f, MAXN=2e5+1;

int a[MAXN], cnt[MAXN];
bool vis[MAXN], inq[MAXN];
vector<int> ans;
deque<int> dq;

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n, k; cin >> n >> k;
    for (int i=1;i<=n;++i) cin >> a[i], cnt[a[i]]++;
    for (int i=1;i<=n;++i){
        cnt[a[i]]--;
        if (vis[a[i]]) continue;
        while (!dq.empty()&&(!inq[a[i]])&&dq.back()>=a[i]) inq[dq.back()]=0, dq.pop_back();
        if (!inq[a[i]]) dq.push_back(a[i]);
        inq[a[i]]=1;
        if (cnt[a[i]]==0){
            while (true){
                int x=dq.front(); dq.pop_front(); inq[x]=0;
                ans.push_back(x); vis[x]=1;
                if (x==a[i]) break;
            }
        }
    }
    for (int i=0;i<k-1;++i) cout << ans[i] << " ";
    cout << ans.back() << '\n';
}