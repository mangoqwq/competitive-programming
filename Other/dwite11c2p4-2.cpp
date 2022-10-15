#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast,unroll-loops")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1001;

vector<int> graph[MAXN];

int solve(int node, int prev){
    vector<int> c;
    for (int x:graph[node]){
        if (x!=prev) c.push_back(solve(x,node));
    }
    sort(c.begin(),c.end());
    int ans=c.size();
    for (int i=0;i<c.size();++i){
        ans=max(ans,(int)c.size()-i-1+c[i]);
    }
    return ans;

}

int main(){
    cin.tie(0); cin.sync_with_stdio(0);
    int t=2;
    while (t--){
        int n; cin >> n;
        for (int i=0;i<n;++i) graph[i].clear();
        for (int i=0,a,b;i<n-1;++i){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        cout << solve(0,0) << '\n';
    }
}