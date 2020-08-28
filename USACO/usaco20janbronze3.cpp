#include <bits/stdc++.h>

using namespace std;

int add(int top,int bot){
    if (top<bot){
        return -1;
    }
    return (top*(top+1))/2-((bot-1)*(bot))/2;
}

int main(){
    int m,cases;
    cin >> m >> cases;
    for (int _=0;_<cases;++_){
        int current=m;
        int speed=0;
        int fastest;
        cin >> fastest;
        int time=0;
        while (current>0){
            if (add(speed+1,fastest)<=current){
                time++; speed++; 
                current-=speed;
            }
            else if (add(speed,fastest)<=current){
                time++;
                current-=speed;
            }
            else{
                time++;speed--;
                current-=speed;
            }
        }
        cout << time << '\n';
    }
    
}
