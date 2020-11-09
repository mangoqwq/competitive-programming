#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1e5+1;

vector<int> adj[MAXN];
int k;

bool check(const vector<int> &arr, int mid){
    for (int l=0, r=arr.size()-1;;l++,r--){
        if (l==mid) l++;
        if (r==mid) r--;
        if (r<0) break;
        if (arr[l]+arr[r]<k) return 0;
    }
    return 1;
}

int dfs(int v, int p){
    vector<int> arr, arr1;
    for (int to:adj[v]){
        if (to!=p) arr.push_back(dfs(to,v)+1);
    }
    arr1=arr;
    if (arr.size()%2) arr1.push_back(0);
    sort(arr1.begin(),arr1.end());
    if (arr.size()%2==0) arr.push_back(0);
    sort(arr.begin(),arr.end());
    if (!arr.empty()) if (arr[0]==-0x3f3f3f3f) return -0x3f3f3f3f;
    int lo=-1, hi=arr.size()-1, mid;
    bool flag=0;
    while (lo<hi){
        mid=lo+hi+1>>1;
        if (check(arr,mid)) lo=mid, flag=1;
        else hi=mid-1;
    }
    flag|=check(arr,lo);
    if (flag&&v!=1) return arr[lo];
    else if (check(arr1,-1)) return 0;
    else return -0x3f3f3f3f;
}

int main(){
    // cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1,a,b;i<=n-1;++i){
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int lo=1, hi=n-1;
    // lo=6, hi=7;
    while (lo<hi){
        k=lo+hi+1>>1;
        // cout << k << " ";
        if (dfs(1,1)>=0) lo=k;
        else hi=k-1;
    }
    cout << lo << '\n';
}