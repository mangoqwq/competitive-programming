#include <iostream>
#include <queue>

using namespace std;
int columns,rows;
bool in(int x, int y){
    if (x<0 || y<0 || x>=rows || y>=columns){
        return false;
    }
    return true;
}

int main(){
    cin >> columns >> rows;
    char graph[rows][columns],temp;
    int visited[rows][columns],x,y;
    priority_queue<int,vector<int>,greater<int>> pq;
    pq.push(1);
    for (int i=0;i<rows;++i){
        for (int k=0;k<columns;++k){
            cin >> temp;
            if (temp=='1'){
                x=i;
                y=k;
            }
            graph[i][k] = temp;
            visited[i][k]=0;
        }
    }
    queue<pair<int,int>> q;
    q.push(make_pair(x,y));
    visited[x][y]=1;
    while (!q.empty()){
        int x1=q.front().first,y1=q.front().second;
        q.pop();
        x1++;
        if (graph[x1][y1]=='O' && !visited[x1][y1] && in(x1,y1)){
            visited[x1][y1]=1;
            q.push(make_pair(x1,y1));
        }
        else if (graph[x1][y1]=='#' && !visited[x1][y1] && in(x1,y1)){}
        else if (!visited[x1][y1] && in(x1,y1)){
            visited[x1][y1]=1;
            pq.push((int)(graph[x1][y1]-'0'));
        }
        x1--;
        x1--;
        if (graph[x1][y1]=='O' && !visited[x1][y1] && in(x1,y1)){
            visited[x1][y1]=1;
            q.push(make_pair(x1,y1));
        }
        else if (graph[x1][y1]=='#' && !visited[x1][y1] && in(x1,y1)){}
        else if (!visited[x1][y1] && in(x1,y1)){
            visited[x1][y1]=1;
            pq.push((int)(graph[x1][y1]-'0'));
        }
        x1++;
        y1++;
        if (graph[x1][y1]=='O' && !visited[x1][y1] && in(x1,y1)){
            visited[x1][y1]=1;
            q.push(make_pair(x1,y1));
        }
        else if (graph[x1][y1]=='#' && !visited[x1][y1] && in(x1,y1)){}
        else if (!visited[x1][y1] && in(x1,y1)){
            visited[x1][y1]=1;
            pq.push((int)(graph[x1][y1]-'0'));
        }
        y1--;
        y1--;
        if (graph[x1][y1]=='O' && !visited[x1][y1] && in(x1,y1)){
            visited[x1][y1]=1;
            q.push(make_pair(x1,y1));
        }
        else if (graph[x1][y1]=='#' && !visited[x1][y1] && in(x1,y1)){}
        else if (!visited[x1][y1] && in(x1,y1)){
            visited[x1][y1]=1;
            pq.push((int)(graph[x1][y1]-'0'));
        }
        y1++;
        visited[x1][y1]=1;
    }
    int temp1=pq.size();
    for (int i=0;i<temp1;++i){
        cout << pq.top() << " ";
        pq.pop();
    }
    cout << '\n';



}