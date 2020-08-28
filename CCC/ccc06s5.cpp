#include <bits/stdc++.h>
//#pragma GCC optimize ("Ofast")

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
typedef pair<int,int> pii;
const int mod=1e9+7,seed=131,MAXN=1<<20;

int r,c,a,b,d;
vector<int> graph[MAXN];
bool curr[6][7], vis[MAXN];

void solve(int mask){
    ms(curr,0);
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            if (1&(mask>>(r*c-1-(i-1)*c-(j-1)))) curr[i][j]=1;
        }
    }
    int cnt, uwu=0;
    for (int i=1;i<=r;++i){
        for (int j=1;j<=c;++j){
            uwu*=2;
            cnt=-curr[i][j];
            for (int x=-1;x<=1;++x){
                for (int y=-1;y<=1;++y){
                    cnt+=curr[i+x][j+y];
                }
            }
            if (curr[i][j] && cnt>=a && cnt<=b) uwu++;
            else if (!curr[i][j]&&cnt>d) uwu++; 
        }
    }
    graph[uwu].push_back(mask);
}

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> r >> c >> a >> b >> d;
    int src=0; char x;
    for (int i=1;i<=r;++i) for (int j=1;j<=c;++j) { cin >> x; src*=2; src+=x=='*'; }
    for (int i=0;i<(1<<r*c);++i) solve(i);
    queue<int> q; q.push(src); int cnt=0,uwu;
    while (!q.empty()){
        int qsize=q.size();
        for (int i=0;i<qsize;++i){
            uwu=q.front(); q.pop();
            if (vis[uwu]) continue;
            vis[uwu]=1;
            if (graph[uwu].size()==0){ cout << cnt << '\n'; return 0; }
            for (int x:graph[uwu]) q.push(x);
        }
        cnt++;
    }
    cout << -1 << '\n';
}
