#include <bits/stdc++.h>
#include <queue>

using namespace std;

int main(){
    int x,temp,a;
    cin >> x;
    vector<int> book[x+1];
    for (int i=1;i<x+1;++i){
        cin >> temp;
        for (int k=0;k<temp;++k){
            cin >> a;
            book[i].push_back(a);
        }
    }
    int visited[x+1]={0},uwu,first=0,count=0;
    queue<int> q;
    q.push(1);
    while (!q.empty()){
        int e=q.size();
        count++;
        for (int i=0;i<e;++i){
            uwu=q.front();
            q.pop();
            if (!visited[uwu]){
                for (auto&&y:book[uwu]){
                    q.push(y);
                }
                if (first==0&&book[uwu].size()==0){
                    first=count;
                }
            }
            visited[uwu]=1;
        }
    }
    int connected=1;
    for (int i=1;i<x+1;++i){
        if (visited[i]==0){
            connected=0;
            cout << "N" << '\n';
            break;
        }
    }
    if (connected==1){
        cout << "Y" << '\n';
    }
    cout << first << '\n';
}