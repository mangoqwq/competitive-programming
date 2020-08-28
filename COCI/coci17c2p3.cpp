#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5e5+5;

int arr[MAXN], cnt[MAXN], tot;
vector<int> piv1[MAXN],piv2[MAXN];


int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        cin >> arr[i];
        if (arr[i]==i) tot++, cnt[i]++;
        int x=(i+arr[i]);
        if (x%2==0) piv1[x/2].push_back(abs((x/2)-i));
        if (x%2==1) piv2[x/2].push_back(max(i,arr[i])-(x/2));
    }
    for (int i=1;i<=n;++i) cnt[i]+=cnt[i-1];
    int best=tot; pii ans={1,1};
    for (int i=1,x,curr;i<=n;++i){
        sort(piv1[i].begin(),piv1[i].end());
        while (!piv1[i].empty()){
            x=piv1[i].back();
            curr=tot+piv1[i].size()-cnt[i+x]+cnt[i-x-1];
            
            if (curr>best) ans={arr[i-x],arr[i+x]}, best=curr;
            piv1[i].pop_back();
        }
        sort(piv2[i].begin(),piv2[i].end());
        while (!piv2[i].empty()){
            x=piv2[i].back();
            curr=tot+piv2[i].size()-cnt[i+x]+cnt[i-x];
            if (curr>best) ans={arr[i-x+1],arr[i+x]}, best=curr;
            piv2[i].pop_back();
        }
    }
    cout << ans.first << " " << ans.second << '\n';
}