#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define f first
#define s second
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1e6+1;

int arr[MAXN+1];
ll ans0[MAXN], ans[MAXN], uwu[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,q; cin >> n >> q;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
    }
    arr[n+1]=0;
    stack<pii> s;
    s.push({-0x3f3f3f3f,0});
    ll cnt;
    for (int i=1;i<=n+1;++i){
        while (arr[i]<s.top().f){
            cnt=i-s.top().s;
            //cout << s.top().s << " -> " << cnt << " * " << uwu[s.top().f] << '\n';
            ans0[s.top().f]+=cnt*(ll)uwu[s.top().f];
            s.pop();
        }
        if (arr[i]==s.top().f) continue;
        uwu[arr[i]]=i-s.top().s;
        s.push({arr[i],i});
    }
    for (int i=1;i<MAXN;++i){
        ans[i]=ans[i-1]+ans0[i];
    }
    for (int i=1;i<=n;++i){
        //cout << ans0[i] << '\n';
    }
    int l,r;
    while (q--){
        cin >> l >> r;
        cout << ans[r]-ans[l-1] << '\n';
    }
}