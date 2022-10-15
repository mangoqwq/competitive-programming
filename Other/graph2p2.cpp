#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=1001;

bool graph[MAXN][MAXN];
queue<int> q;
int cnt=0, deg[MAXN];



int main(){
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    for (int i=1;i<=n;++i){
        for (int j=1;j<=n;++j){
            cin >> graph[i][j];
            if (graph[i][j]) deg[j]++;
        }
    }
    for (int i=1;i<=n;++i){
        if (deg[i]==0) cnt++, q.push(i);
    }
    while (!q.empty()){
        int curr=q.front(); q.pop();
        for (int i=1;i<=n;++i){
            if (!graph[curr][i]) continue;
            deg[i]--;
            if (deg[i]==0) q.push(i), cnt++;
        }
    }
    cout << (cnt==n?"YES":"NO") << '\n';
}