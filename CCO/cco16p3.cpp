#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main(){
    int subtask,cases;
    cin >> subtask >> cases;
    for (int k=0;k<cases;++k){
        int nodes,edges,a,b;
        cin >> nodes >> edges;
        vector<int> graph[nodes+1];
        for (int i=0;i<edges;++i){
            cin >> a >> b;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        if (subtask==1){
            cout << 1;
        }
        else if (subtask==2){
            if (nodes-1<edges){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }
        }
        else if (subtask==3){
            cout << 3;
        }
        else if (subtask==4){
            bool uwu=false;
            for (auto&&x:graph){
                if (x.size()>=3){
                    uwu=true;
                    break;
                }
            }
            if (uwu==true){
                cout << "YES" << '\n';
            }
            else{
                cout << "NO" << '\n';
            }
        }
        else if (subtask==5){
            cout << 5;
        }
    }
}