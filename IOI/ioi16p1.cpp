#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=0;

struct Item{ int val, idx; };

int find_subset(int l, int u, int w[], int n, int result[]){
    int arr[n]; iota(arr,arr+n,0);
    sort(arr,arr+n,[&](int a, int b)->bool { return w[a]<w[b]; });
    bool used[n]={0};
    ll tot=0,up=0;
    stack<Item> s;
    bool flag=0;
    for (int i=0;i<n;++i){
        tot+=w[arr[i]]; up+=w[arr[n-i-1]]-w[arr[i]];
        used[arr[i]]=1;
        if (i==n-i-1) ;
        else if (i>=n/2) s.pop();
        else s.push({w[arr[n-i-1]]-w[arr[i]],n-i-1});
        if (tot>=l&&tot<=u){
            flag=1;
            break;
        }
        if (tot<l&&tot+up>=l){
            while (tot<l){
                tot+=s.top().val, up-=s.top().val;
                used[arr[s.top().idx]]=1, used[arr[n-s.top().idx-1]]=0;
                s.pop();
            }
            flag=1;
            break;
        }
    }
    if (!flag) return 0;
    int ans=0;
    for (int i=0;i<n;++i) if (used[i]) result[ans++]=i;
    return ans;
}

// int main(){
//     cin.tie(0)->sync_with_stdio(0);
//     int l=20;
//     int u=23;
//     int w[]={8,8,8,11,11};
//     int n=5;
//     int result[n];
//     int ans=find_subset(l,u,w,n,result);
//     //for (int i=0;i<ans;++i) cout << result[i] << " ";
// }