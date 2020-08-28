#include <bits/stdc++.h>

using namespace std;
vector<pair<int,int>> graph[100001]; int locations[100001],width[100001];
int cows,edges;

bool check(int wormhole){
    int group[100001]={0};
    queue<int> q;
    for (int i=1;i<cows+1;++i){
        if (!group[i]){
            q.push(i); int uwu;
            while (!q.empty()){
                uwu=q.front(); q.pop();
                if (!group[uwu]){
                    group[uwu]=i;
                    for (auto&&x:graph[uwu]){
                        if (x.second>=wormhole){
                            q.push(x.first);
                        }
                    }
                }
            }
        }
    }
    for (int i=1;i<cows+1;++i){
        if (group[i]!=group[locations[i]]){
            return false;
        }
    }
    return true;

}

int main(){
    int a,b,c; cin >> cows >> edges;
    for (int i=1;i<cows+1;++i){
        cin >> a; locations[i]=a;
    }
    for (int i=0;i<edges;++i){
        cin>>a>>b>>c; graph[a].push_back({b,c}); graph[b].push_back({a,c}); width[i]=c;
    }
    sort(begin(width),end(width)); 
    int bot=0, top=100001,mid=(bot+top)/2;
    while (bot<=top){
        mid=(bot+top)/2;
        if (check(width[mid])){
            if (!check(width[mid+1])){
                break;
            }
            else{
                bot=mid+1;
            }
        }
        else{
            top=mid-1;
        }
    }
    if (check(1000000001)){
        cout << -1 << '\n';
    }
    else{
        cout << width[mid] << '\n';
    }
    
    

}