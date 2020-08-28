#include<bits/stdc++.h>
#include <queue>
#include <set>

using namespace std;
typedef vector<int> e;

int djs[100001];

int parent(int x){
    if (djs[x]==x){
        return x;
    }
    return djs[x] = parent(djs[x]);
}

void u(int x, int y){
    djs[parent(x)]=parent(y);
}

int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int nodes, edges, a, b, c;
    long long magic;
    cin >> nodes >> edges >> magic;
    for (int i=0;i<nodes+1;++i){
        djs[i]=i;
    }
    priority_queue<e,vector<e>,greater<e>> pq;
    for (int i=1;i<edges+1;++i){
        cin >> a >> b >> c;
        pq.push({c,i,a,b});
    }
    priority_queue<e,vector<e>,greater<e>> ok=pq;
    int days=0,total=0;
    e uwu;
    while (total<nodes-1){
        uwu=pq.top();
        pq.pop();
        if (parent(uwu[2])!=parent(uwu[3])){
            u(uwu[2],uwu[3]);
            if (uwu[1]>=nodes){
                days++;
            }
            total++;
        }
    }
    int maximum=uwu[0];
    for (int i=0;i<nodes+1;++i){
        djs[i]=i;
    }
    e owo;
    while (!ok.empty()){
        owo=ok.top();
        ok.pop();
        if (parent(owo[2])!=parent(owo[3])){
            if (owo[0]<maximum){
                u(owo[2],owo[3]);
            }
            else if (owo[1]<nodes && owo[0]==maximum){
                u(owo[2],owo[3]);
            }
            else if (owo[1]<nodes && owo[0]<=magic){
                days--;
                break;
            }
        }
    }



    
    cout << days << '\n';
}