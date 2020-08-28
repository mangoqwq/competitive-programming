#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
vector<int> owo;
queue<int> q;
deque<int> dq;
deque<int> dq2;

int main(){
    int crackers, water; cin >> crackers >> water;
    for (int i=0,a;i<crackers;++i){
        cin >> a;
        owo.push_back(a);
    }
    sort(owo.begin(),owo.end());
    if (abs(owo[0]-water)<abs(owo[crackers-1]-water)){
        reverse(owo.begin(),owo.end());
    }
    for (auto&&x:owo){
        q.push(x);
        dq.push_back(x);
        dq2.push_back(x);
    }
    ll smol=0; ll big=0; ll big2=0; int curr=water;
    for (int i=0;i<crackers;++i){
        smol+=min(abs(curr-q.front()),abs(water-q.front()));
        curr=q.front(); q.pop();
    }
    curr=dq.front();
    big+=abs(dq.front()-water);
    dq.pop_front();
    for (int i=1;i<crackers;++i){
        if (max(abs(curr-dq.front()),abs(water-dq.front()))>max(abs(curr-dq.back()),abs(water-dq.back()))){
            big+=max(abs(curr-dq.front()),abs(water-dq.front()));
            curr=dq.front(); dq.pop_front();
        }
        else{
            big+=max(abs(curr-dq.back()),abs(water-dq.back()));
            curr=dq.back(); dq.pop_back();
        }
    }
    curr=dq2.back();
    big2+=abs(dq2.back()-water);
    dq2.pop_back();
    for (int i=1;i<crackers;++i){
        if (max(abs(curr-dq2.front()),abs(water-dq2.front()))>max(abs(curr-dq2.back()),abs(water-dq2.back()))){
            big2+=max(abs(curr-dq2.front()),abs(water-dq2.front()));
            curr=dq2.front(); dq2.pop_front();
        }
        else{
            big2+=max(abs(curr-dq2.back()),abs(water-dq2.back()));
            curr=dq2.back(); dq2.pop_back();
        }
    }
    cout << smol << " " << max(big,big2) << '\n';

}