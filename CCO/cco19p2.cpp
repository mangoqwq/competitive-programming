#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
vector<vector<pair<char,int>>> graph;
int visited[500005];
vector<pii> blocks[500005];
int lowest[1000001];

void bfs(int x, int y, int group){
    if (!graph[x][y].second){
        graph[x][y].second=group;
        blocks[group].push_back({x,y});
        if (graph[x+1][y].first=='#'){
            bfs(x+1,y,group);
        }
        if (graph[x-1][y].first=='#'){
            bfs(x-1,y,group);
        }
        if (graph[x][y+1].first=='#'){
            bfs(x,y+1,group);
        }
        if (graph[x][y-1].first=='#'){
            bfs(x,y-1,group);
        }
    }
}

int main(){
    int rows,columns;
    cin >> rows >> columns;
    graph.resize(rows+2);
    for (int i=0;i<rows+2;++i){
        graph[i].resize(columns+2);
    }
    for (int x=1;x<rows+1;++x){
        for (int y=1;y<columns+1;++y){
            cin >> graph[x][y].first;
        }
    }
    reverse(graph.begin(),graph.end());
    int group=1;
    for (int x=1;x<rows+1;++x){
        for (int y=1;y<columns+1;++y){
            if (graph[x][y].first=='#'&&!graph[x][y].second){
                bfs(x,y,group);
                group++;
            }
        }
    }
    //first is height, second is channel
    visited[0]=1;
    int falldist=0x3f3f3f3f,block,temp,tempheight;
    for (int x=1;x<rows+1;++x){
        for (int y=1;y<columns+1;++y){
            if (graph[x][y].first=='#'&&!visited[graph[x][y].second]){
                falldist=0x3f3f3f3f;
                block=graph[x][y].second;
                visited[block]=1;
                for (auto&&uwu:blocks[block]){
                    if (uwu.first-lowest[uwu.second]>=1&&false){
                        falldist=min(falldist,uwu.first-lowest[uwu.second]);
                    }
                    else{
                        tempheight=uwu.first-1;
                        while (tempheight>0&&graph[tempheight][uwu.second].first!='#'&&graph[tempheight][uwu.second].second!=block){
                            tempheight--;
                        }
                        if (uwu.first-tempheight>=1){
                            falldist=min(falldist,uwu.first-tempheight);
                        }
                        
                    }
                }
                falldist--;
                cout << "~" << falldist << "~"<<block << " ";
                //if (falldist<0){
                //    continue;
                //}
                for (int i=0;i<blocks[block].size();++i){
                    graph[blocks[block][i].first][blocks[block][i].second]={'.',0};
                    blocks[block][i].first-=falldist;
                    lowest[blocks[block][i].second]=max(lowest[blocks[block][i].second],blocks[block][i].first);
                    graph[blocks[block][i].first][blocks[block][i].second]={'#',group};
                    //cout << blocks[block][i].first << " " << blocks[block][i].second << "|";
                }
                //cout << '\n';
                
            }
        }
    }
    cout << '\n';
    char uwu[rows+1][columns+1];
    for (int x=0;x<rows+1;++x){
        for (int y=0;y<columns+1;++y){
            uwu[x][y]='.';
        }
    }
    for (auto&&x:blocks){
        for (auto&&owo:x){
            uwu[owo.first][owo.second]='#';
        }
    }
    for (int x=rows;x>0;--x){
        for (int y=1;y<columns+1;++y){
            cout << uwu[x][y];
        }
        cout << '\n';
    }

    


}