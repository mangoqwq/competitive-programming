#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
#define scan(x) do{while((x=getchar())<'0'); for(x-='0'; '0'<=(_=getchar()); x=(x<<3)+(x<<1)+_-'0');}while(0)
char _;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN=1501;
vector<short> graph[MAXN]; short dist[MAXN];

int main(){
    int m;
    short n, k; scan(n); scan(m); scan(k);
    short a,b;
    for (int i=0;i<min(m,23250);++i){
        scan(a); scan(b);
        graph[a].push_back(b); graph[b].push_back(a);
    }
    short uwu;
    queue<short> q;
    for (short curr=1;curr<=n;++curr){
        ms(dist,0); q.push(curr);
        int ans=1; dist[curr]=1;
        while (!q.empty()){
            uwu=q.front(); q.pop();
            if (dist[uwu]<=k){
                for (short x:graph[uwu]){
                    if (!dist[x]){
                        dist[x]=dist[uwu]+1;
                        q.push(x);
                        ans++;
                    }
                }
            }
        }
        printf("%d\n",ans);
    }
}