#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=5e5+1;

map<int,int> graph[MAXN];

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int n,m; cin >> n >> m;
    for (int i=0,a,b,w;i<m;++i){
        cin >> a >> b >> w;
        graph[a][b]=w;
        graph[b][a]=w; 
    }
    int ans=0x3f3f3f3f;
    int temp=0;
    vector<int> arr;
    int factorial=1;
    for (int i=1;i<=n;++i) arr.push_back(n-1),factorial*=i;
    for (int i=0;i<factorial;++i){
        next_permutation(arr.begin(),arr.end());
        temp=0;
        for (int i=1;i<n;++i){
            if (graph[arr[i]].count(arr[i-1])) temp+=graph[arr[i]][arr[i-1]];
            else {temp=0x3f3f3f3f; break;}
        }
        if (temp!=0x3f3f3f3f) cout << temp << " ";
        ans=min(ans,temp);
    }
    cout << ans << '\n';
}