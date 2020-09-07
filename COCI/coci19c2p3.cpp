#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7,seed=131,MAXN=2e5+1;

map<int,int> graph[MAXN];

int main(){
    cin.tie(0)->sync_with_stdio(0);
    int t; cin >> t;
    int n; cin >> n;
    char x;
    for (int i=1;i<n;++i){
        cin >> x;
        graph[i+1][i]=x-'0';
        graph[i][i+1]=x-'0';
    }
    cin >> x;
    graph[n][1]=x-'0'; graph[1][n]=x-'0';
    
    for (int i=1,a,b,c;i<=n-3;++i){
        cin >> a >> b >> c;
        graph[a][b]=c;
        graph[b][a]=c;
    }
    queue<int> q;
    for (int i=1;i<=n;++i) if (graph[i].size()==2) q.push(i);
    int cnt=n,curr,a,b,tot;
    while (!q.empty()&&cnt>2){
        curr=q.front(); q.pop(); cnt--;
        tot=(*graph[curr].begin()).second;
        a=(*graph[curr].begin()).first;
        graph[curr].erase(a);
        tot+=(*graph[curr].begin()).second;
        b=(*graph[curr].begin()).first;
        graph[curr].erase(b);
        //cout << curr << " " << a << " " << b << '\n';
        if (!graph[a].count(b)){ cout << "neispravna triangulacija" << '\n'; return 0; }
        tot+=graph[a][b];
        if (tot!=6){ cout << "neispravno bojenje" << '\n'; return 0; }
        graph[a].erase(curr);
        graph[b].erase(curr);
        if (graph[a].size()==2) q.push(a);
        if (graph[b].size()==2) q.push(b);
    }
    cout << "tocno" << '\n';

}