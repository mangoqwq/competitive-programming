#include <iostream>
#include <vector>
using namespace std;

vector<int> t1[2003],t2[2003];
int one, two, edges;
int main(){
    cin >> one >> two >> edges;
    int a,b;
    for (int i=0;i<edges;++i){
        cin >> a >> b;
        t1[a].push_back(b);
        t2[b].push_back(a);
    }
    int bad=false;

    for (int i=1;i<one+1;++i){
        int visited[one+1]={0};

        for (int _:t1[i]){
            for (int __:t2[_]){
                if (visited[__]==0){
                    visited[__]=1;
                }
                else if (visited[__]==1 && __!=i){
                    bad=true;
                }
            }
        }
    }
    if (bad){
        cout << "NO" << '\n';
    }
    else{
        cout << "YES" << '\n';
    }

}