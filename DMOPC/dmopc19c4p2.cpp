#include <bits/stdc++.h>
#include <queue>

using namespace std;
int visited[16][16][16][16]; //empty row, empty column, marble row, marble column
int N,rs,cs,re,ce,rempty,cempty;
bool in(int row,int column){if (row<0 || row>N || column<0 || column>N){return false;}else{return true;}}

int main(){
    cin >> N >> rs >> cs >> re >> ce >> rempty >> cempty;
    if (rempty==rs&&cempty==cs){cin>>rempty>>cempty;}else{int _,__; cin >> _ >> __;}
    queue<pair<pair<int,int>,pair<int,int>>> q; q.push({{rempty,cempty},{rs,cs}});pair<pair<int,int>,pair<int,int>> uwu;
    int count=0,qsize;
    while (!q.empty()){
        qsize=q.size();
        for (int i=0;i<qsize;++i){
            uwu=q.front(); q.pop();
            if (uwu.second.first==re && uwu.second.second==ce){cout<<count<<'\n';return 0;} // if puzzle is completed
            if (!visited[uwu.first.first][uwu.first.second][uwu.second.first][uwu.second.second]&&uwu.first!=uwu.second){
                visited[uwu.first.first][uwu.first.second][uwu.second.first][uwu.second.second]=1;
                if (in(uwu.first.first+1,uwu.first.second)){
                    q.push({{uwu.first.first+1,uwu.first.second},{uwu.second.first,uwu.second.second}});
                }
                if (in(uwu.first.first-1,uwu.first.second)){
                    q.push({{uwu.first.first-1,uwu.first.second},{uwu.second.first,uwu.second.second}});
                }
                if (in(uwu.first.first,uwu.first.second+1)){
                    q.push({{uwu.first.first,uwu.first.second+1},{uwu.second.first,uwu.second.second}});
                }
                if (in(uwu.first.first,uwu.first.second-1)){
                    q.push({{uwu.first.first,uwu.first.second-1},{uwu.second.first,uwu.second.second}});
                }
                if (uwu.first.first+1==uwu.second.first&&uwu.first.second==uwu.second.second){
                    q.push({{uwu.second.first,uwu.second.second},{uwu.first.first,uwu.first.second}});
                }
                if (uwu.first.first-1==uwu.second.first&&uwu.first.second==uwu.second.second){
                    q.push({{uwu.second.first,uwu.second.second},{uwu.first.first,uwu.first.second}});
                }
                if (uwu.first.first==uwu.second.first&&uwu.first.second+1==uwu.second.second){
                    q.push({{uwu.second.first,uwu.second.second},{uwu.first.first,uwu.first.second}});
                }
                if (uwu.first.first==uwu.second.first&&uwu.first.second-1==uwu.second.second){
                    q.push({{uwu.second.first,uwu.second.second},{uwu.first.first,uwu.first.second}});
                }
                //empty row, empty column, marble row, marble column
            }
        }
        count++;
    }
}