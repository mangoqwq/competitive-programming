#include <bits/stdc++.h>

using namespace std;
int dp[101];
string names[101];
int speed[101];
int bridge, q; 
pair<int,int> order[101];

int time(int index, int end){
    int output=-1;
    for (int i=index;i<end+1;++i){
        output=max(output,speed[i]);
    }
    return output;
}

int cross(int index){
    //cout << index << " ";
    if (dp[index]!=-1){
        return dp[index];
    }
    if (index>q-bridge){
        order[index]={index,q};
        return dp[index]=time(index,q);
    }
    int temp=0x3f3f3f3f;
    pair<int,int> uwu;
    for (int i=index;i<min(index+bridge,q);++i){
        if (time(index,i)+cross(i+1)<temp){
            temp=time(index,i)+cross(i+1);
            uwu={index,i};
        }
    }
    order[index]=uwu;
    return dp[index]=temp;
}

int main(){
    cin >> bridge >> q;
    string name; int temp;
    memset(dp,-1,sizeof dp);
    for (int i=1;i<q+1;++i){
        cin >> name >> temp;
        names[i]=name; speed[i]=temp;
    }
    int totaltime=cross(1);
    cout << "Total Time: " << totaltime << '\n';
    for (int _=1;_<q+1;++_){
        if (!(order[_].first==0 && order[_].second==0)){
            for (int i=order[_].first;i<order[_].second+1;++i){
                cout << names[i] << " ";
            }
            _=order[_].second;
            cout << '\n';
        }
        
    }
    
}