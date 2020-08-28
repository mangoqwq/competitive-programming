#include <iostream>
#include <queue>

using namespace std;
vector<int> graph[10000];

int main(){
    int students,a,b;
    cin >> students;
    for (int i=0;i<students;++i){
        cin >> a >> b;
        graph[a].push_back(b);
    }
    int x,y;
    cin >> x >> y;
    while (!(x==0 & y==0)){
        int visited[10000];
        for (int i=0;i<10000;++i){
            visited[i]=0;
        }
        int current=x,count{-1},distance;
        while (true){
            visited[current]=1;
            count += 1;
            if (current==y){
                distance=count;
            }
            current=graph[current][0];
            if (visited[current]==1){
                break;
            }
        }
        if (visited[y]==1 && current == x){
            cout << "Yes " << distance-1 << '\n'; 
        } else{
            cout << "No" << '\n';
        }
        cin >> x >> y;
    }
    
}