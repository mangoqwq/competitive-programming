#include <iostream>
#include <queue>

using namespace std;

int parent[100001];
int find_parent(int a){
    if (a==parent[a]){
        return a;
    }
    return parent[a] = find_parent(parent[a]);
}
void union_sets(int a, int b){
    parent[find_parent(b)]=find_parent(a);
}
int main(){
    queue<int> q;
    int vertices, edges, count=0,x,y;
    cin >> vertices >> edges;
    for (int i=0;i<vertices+1;++i){
        parent[i]=i;
    }
    for (int i=1;i<edges+1;++i){
        cin >> x >> y;
        if (find_parent(x)!=find_parent(y)){
            q.push(i);
            union_sets(x,y);
        }
        if (q.size()==vertices-1){
            break;
        }
    }
    if (q.size()==vertices-1){
        int e=q.size();
        for (int i=0;i<e;++i){
            cout << q.front() << '\n';
            q.pop();
        }
    } else{
        cout << "Disconnected Graph" << '\n';
    }

}