#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii> piii;
int visited[10][10]; pii dist[10][10];
int rows,columns;

bool in(int r,int c){
    if (r>=0&&c>=0&&r<rows&&c<columns){
        return true;
    }
    return false;
}


int main(){
    cin >> rows >> columns;
    int startrow,startcolumn;
    int forest[rows][columns];
    int forest1[rows][columns];
    int maximum=-1; vector<pii> locations; char temp;

    for (int i=0;i<rows;++i){
        for (int k=0;k<columns;++k){
            cin >> temp;
            if (temp=='.'){
                forest[i][k]=0;
                forest1[i][k]=0;
            }
            else if (temp=='X'){
                forest[i][k]=0;
                forest1[i][k]=1;
                startrow=i; startcolumn=k;
            }
            else{
                forest[i][k]=(int)temp-'0';
                forest1[i][k]=1;
                if ((int)(temp-'0')>maximum){
                    locations.clear();
                    locations.push_back({i,k});
                    maximum=(int)temp-'0';
                }
                else if ((int)(temp-'0')==maximum){
                    locations.push_back({i,k});
                }
            }
        }
    }

    priority_queue<piii,vector<piii>,greater<piii>> pq; int uwu,r,c;
    pq.push({0,{startrow,startcolumn}});
    memset(dist,0x3f,sizeof dist);
    dist[startrow][startcolumn]={0,0};
    while (!pq.empty()){
        uwu=pq.top().first; r=pq.top().second.first; c=pq.top().second.second; pq.pop();
        //cout << r << ":" << c << " ";
        if (!visited[r][c]){
            visited[r][c]=1;
            if (in(r+1,c)&&dist[r+1][c].first>dist[r][c].first+forest[r+1][c]){
                dist[r+1][c].first=dist[r][c].first+forest[r+1][c];
                dist[r+1][c].second=dist[r][c].second+forest1[r+1][c];
                pq.push({dist[r+1][c].first,{r+1,c}});
            }
            if (in(r-1,c)&&dist[r-1][c].first>dist[r][c].first+forest[r-1][c]){
                dist[r-1][c].first=dist[r][c].first+forest[r-1][c];
                dist[r-1][c].second=dist[r][c].second+forest1[r-1][c];
                pq.push({dist[r-1][c].first,{r-1,c}});
            }
            if (in(r,c+1)&&dist[r][c+1].first>dist[r][c].first+forest[r][c+1]){
                dist[r][c+1].first=dist[r][c].first+forest[r][c+1];
                dist[r][c+1].second=dist[r][c].second+forest1[r][c+1];
                pq.push({dist[r][c+1].first,{r,c+1}});
            }
            if (in(r,c-1)&&dist[r][c-1].first>dist[r][c].first+forest[r][c-1]){
                dist[r][c-1].first=dist[r][c].first+forest[r][c-1];
                dist[r][c-1].second=dist[r][c].second+forest1[r][c-1];
                pq.push({dist[r][c-1].first,{r,c-1}});
            }
        }
    }
    double mininum=100000.0;
    pii closest;
    for (auto&&x:locations){
        if (sqrt(pow(abs(startrow-x.first),2)+pow(abs(startcolumn-x.second),2))<mininum){
            closest=x;
            mininum=sqrt(pow(abs(startrow-x.first),2)+pow(abs(startcolumn-x.second),2));
        }
    }
    cout << dist[closest.first][closest.second].second-1 << '\n';
}