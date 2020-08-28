#include <bits/stdc++.h>

using namespace std;
typedef pair<int,pair<int,int>> piii;
int disjoint[102];
priority_queue<piii,vector<piii>,greater<piii>> pq;
priority_queue<piii,vector<piii>,greater<piii>> pq2;
vector<pair<int,int>> dual[1001][1001];

void initdisjoint(){
    for (int i=0;i<102;++i){
        disjoint[i]=i;
    }
}
int findparent(int node){
    if (disjoint[node]==node){
        return node;
    }
    return disjoint[node]=findparent(disjoint[node]);
}

void unionsets(int a,int b){
    disjoint[findparent(b)]=findparent(a);
}

int kruskals(){
    piii uwu;
    int minweight=0;
    while (!pq.empty()){
        uwu=pq.top(); pq.pop();
        if (findparent(uwu.second.first)!=findparent(uwu.second.second)){
            unionsets(uwu.second.first,uwu.second.second);
            minweight+=uwu.first;
        }
    }
    return minweight;
}

int kruskals2(){
    piii uwu;
    int minweight=0;
    while (!pq2.empty()){
        uwu=pq2.top(); pq2.pop();
        if (findparent(uwu.second.first)!=findparent(uwu.second.second)){
            unionsets(uwu.second.first,uwu.second.second);
            minweight+=uwu.first;
        }
    }
    return minweight;
}

int main(){
    cin.tie(0);
    cin.sync_with_stdio(0);
    int animals; cin >> animals;
    int edges;
    for (int _=1;_<animals+1;++_){
        cin >> edges;
        int temp[edges]={0}; int temp2[edges]={0};
        for (int i=0;i<edges;++i){
            cin >> temp[i];
        }
        for (int i=0;i<edges;++i){
            cin >> temp2[i];
        }
        for (int i=0;i<edges-1;++i){
            dual[temp[i]][temp[i+1]].push_back({_,temp2[i]});
            dual[temp[i+1]][temp[i]].push_back({_,temp2[i]});
            if (dual[temp[i+1]][temp[i]].size()==2){
                pq.push({temp2[i],{dual[temp[i+1]][temp[i]][0].first,dual[temp[i+1]][temp[i]][1].first}});
                pq2.push({temp2[i],{dual[temp[i+1]][temp[i]][0].first,dual[temp[i+1]][temp[i]][1].first}});
            }
        }
        dual[temp[edges-1]][temp[0]].push_back({_,temp2[edges-1]});
        dual[temp[0]][temp[edges-1]].push_back({_,temp2[edges-1]});
        if (dual[temp[0]][temp[edges-1]].size()==2){
            pq.push({temp2[edges-1],{dual[temp[0]][temp[edges-1]][0].first,dual[temp[0]][temp[edges-1]][1].first}});
            pq2.push({temp2[edges-1],{dual[temp[0]][temp[edges-1]][0].first,dual[temp[0]][temp[edges-1]][1].first}});
        }
    }
    initdisjoint();
    int nooutside=kruskals();
    for (int i=0;i<1001;++i){
        for (int k=0;k<1001;++k){
            if (dual[i][k].size()==1){
                pq2.push({dual[i][k][0].second,{0,dual[i][k][0].first}});
            }
        }
    }
    initdisjoint();
    int outside=kruskals2();
    cout << min(nooutside,outside);
}