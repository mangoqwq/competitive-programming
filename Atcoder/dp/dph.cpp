#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef long long ll;
const ll mod=1e9+7;
char room[1001][1001];
int visited[1001][1001];
ll dist[1001][1001];

int h,w;

bool in(int x,int y){
    if (x>=0 && y>=0 && x<=h && y<=w){
        return true;
    }
    return false;
}

int main(){
    cin >> h >> w;
    char temp;
    for (int i=1;i<h+1;++i){
        for (int k=1;k<w+1;++k){
            cin >> temp;
            room[i][k]=temp;
        }
    }
    queue<pii> q; q.push({1,1}); int x,y; dist[1][1]=1;
    while (!q.empty()){
        x = q.front().first; y=q.front().second; q.pop();
        if (!visited[x][y] && room[x][y]=='.'){
            visited[x][y]=1;
            dist[x+1][y]+=dist[x][y];
            dist[x+1][y]%=mod;
            q.push({x+1,y});
            dist[x][y+1]+=dist[x][y];
            dist[x][y+1]%=mod;
            q.push({x,y+1});
        }
    }
    cout << (dist[h][w]+mod)%mod << '\n';
}