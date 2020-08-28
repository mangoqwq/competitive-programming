#include <iostream>
#include <queue>

using namespace std;

int main(){
    int x,temp;
    cin >> x;
    int uwu[1001];
    for (int i=0;i<1001;++i){
        uwu[i]=0;
    }
    for (int i=0;i<x;++i){
        cin >> temp;
        uwu[temp]+=1;
    }
    int greatest=0;
    for (int i=0;i<1001;++i){
        if (uwu[i]>greatest){
            greatest=uwu[i];
        }
    }
    priority_queue<int> h1;
    priority_queue<int,vector<int>,greater<int>> l1;
    for (int i=0;i<1001;++i){
        if (uwu[i]==greatest){
            h1.push(i);
            l1.push(i);
        }
    }
    int greatest2=0;
    for (int i=0;i<1001;++i){
        if (uwu[i]>greatest2 && uwu[i]!=greatest){
            greatest2=uwu[i];
        }
    }
    priority_queue<int> h2;
    priority_queue<int,vector<int>,greater<int>> l2;
    for (int i=0;i<1001;++i){
        if (uwu[i]==greatest2){
            h2.push(i);
            l2.push(i);
        }
    }
    if (h1.size()>1){
        cout << abs(h1.top()-l1.top());
    }
    else if (greatest2==0){
        cout << abs(h1.top()-l1.top());
    }
    else{
        cout << max(abs(h2.top()-l1.top()),abs(h1.top()-l2.top()));
    }
}