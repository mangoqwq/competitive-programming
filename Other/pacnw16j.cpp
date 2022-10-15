#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

// Sqrt decomposition with monotonic queue

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=200'001,len=500;

ll arr[MAXN]; vector<ll> s[len+1];
int n,q;

void init(){
    for (int i=0;i<=len;++i){ s[i].push_back(LLONG_MAX);}
    for (int i=1;i<=n;++i){
        if (s[i/len].back()>arr[i]) s[i/len].push_back(arr[i]);
    }
}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    cin >> n >> q;
    for (int i=1;i<=n;++i){ cin >> arr[i]; }
    init();
    ll v; int l,r,idx;
    while (q--){
        cin >> v >> l >> r;
        while (l<=r){
            if (l%len==0&&r>=l+len){
                idx=1;
                while (v>=s[l/len].back()){
                    v%=s[l/len][idx];
                    idx++;
                }
                l+=len;
            }
            else{
                v%=arr[l];
                ++l;
            }
        }
        cout << v << '\n';
    }
}