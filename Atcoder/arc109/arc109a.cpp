#include <bits/stdc++.h>

using namespace std;
#define ms(x,a) memset(x,a,sizeof x)
typedef long long ll;
const int mod=1e9+7, seed=131, MAXN=101;

int dist[MAXN][2], s, e, x, y;
struct Pos{
    int d, f, b;
    bool operator<(const Pos x) const{ return d>x.d; }
};

int main(){
    cin.tie(0)->sync_with_stdio(0);
    cin >> s >> e >> x >> y;
    ms(dist,0x3f), dist[s][0]=0;
    priority_queue<Pos> pq;
    pq.push({0,s,0});
    while (!pq.empty()){
        auto [d,f,b]=pq.top(); pq.pop();
        if (b==0){
            if (dist[f][1]>d+x){
                dist[f][1]=d+x;
                pq.push({d+x,f,1});
            }
            if (f!=1){
                if (dist[f-1][1]>d+x){
                    dist[f-1][1]=d+x;
                    pq.push({d+x,f-1,1});
                }
                if (dist[f-1][0]>d+y){
                    dist[f-1][0]=d+y;
                    pq.push({d+y,f-1,0});
                }
            }
            if (f!=100){
                if (dist[f+1][0]>d+y){
                    dist[f+1][0]=d+y;
                    pq.push({d+y,f+1,0});
                }
            }
        }
        if (b==1){
            if (dist[f][0]>d+x){
                dist[f][0]=d+x;
                pq.push({d+x,f,0});
            }
            if (f!=1){
                if (dist[f-1][1]>d+y){
                    dist[f-1][1]=d+y;
                    pq.push({d+y,f-1,1});
                }
            }
            if (f!=100){
                if (dist[f+1][0]>d+x){
                    dist[f+1][0]=d+x;
                    pq.push({d+x,f+1,0});
                }
                if (dist[f+1][1]>d+y){
                    dist[f+1][1]=d+y;
                    pq.push({d+y,f+1,1});
                }
            }
        }
    }
    cout << dist[e][1] << '\n';
}