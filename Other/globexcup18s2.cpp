#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

typedef pair<int,int> uwu;

int main(){
    long tests,marks,temp1,temp2,mymark=0;
    long hours=0,goal;
    cin >> tests >> marks >> goal;
    goal*=tests;
    priority_queue<uwu,vector<uwu>,greater<uwu>> awoo;
    for (int i=0;i<tests;++i){
        cin >> temp1 >> temp2;
        mymark+=temp1;
        awoo.push(make_pair(temp2,marks-temp1));
        //pair: (hours cost, marks left)
    }
    marks = goal-mymark;
    while (marks>0){
        if (awoo.empty()){
            break;
        }
        if (marks>=awoo.top().second){
            marks-=awoo.top().second;
            hours+=(awoo.top().second*awoo.top().first);
            awoo.pop();
        } else{
            hours+=(awoo.top().first*marks);
            marks = 0;
        }
    
    }
    cout << hours;
}