#include <bits/stdc++.h>

using namespace std;
vector<int> candytype[100001];
int dist[100001];
typedef pair<int,int> pii;
priority_queue<pii,vector<pii>,greater<pii>> closest[101];

int main(){
    cin.tie(0); cin.sync_with_stdio(0); cout.sync_with_stdio(0); cout.tie(0);
    int stalls, candysellingstalls; cin >> stalls >> candysellingstalls;
    for (int i=1,a;i<stalls+1;++i){
        cin >> a;
        dist[i]=a;
    }
    for (int i=1,a,b;i<candysellingstalls+1;++i){
        cin >> a >> b;
        candytype[a].push_back(b);
        closest[b].push({dist[a],a});
    }
    int queries; cin >> queries;
    char operation;
    for (int _=0,a,b;_<queries;++_){
        cin >> operation;
        if (operation=='Q'){
            cin >> a;
            while (!closest[a].empty()){
                if (find(candytype[closest[a].top().second].begin(),candytype[closest[a].top().second].end() ,a)!=candytype[closest[a].top().second].end()\
                &&closest[a].top().first==dist[closest[a].top().second]){
                    cout << closest[a].top().second << '\n';
                    break;
                }
                else{
                    closest[a].pop();
                }
            }
            if (closest[a].empty()){
                cout << -1 << '\n';
            }
        }
        else if (operation=='A'){
            cin >> a >> b;
            candytype[a].push_back(b);
            closest[b].push({dist[a],a});
        }
        else if (operation=='S'){
            cin >> a >> b;
            while (find(candytype[a].begin(),candytype[a].end(),b)!=end(candytype[a])){
                candytype[a].erase(find(candytype[a].begin(),candytype[a].end(),b));
            }
        }
        else if (operation=='E'){
            cin >> a >> b;
            dist[a]=b;
            candytype[a].clear();
        }
    }
}