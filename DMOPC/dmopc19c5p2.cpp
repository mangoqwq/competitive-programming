#include <bits/stdc++.h>

using namespace std;
queue<pair<char,int>> c,b;

int main(){
    int turns, charlie, bot; cin >> turns >> charlie;
    bot=charlie;
    char temp1; int temp2;
    for (int i=0;i<turns;++i){
        cin >> temp1 >> temp2;
        c.push({temp1,temp2});
    }
    for (int i=0;i<turns;++i){
        cin >> temp1 >> temp2;
        b.push({temp1,temp2});
    }
    for (int i=0;i<turns;++i){
        temp1=c.front().first; temp2=c.front().second; c.pop();
        if (temp1=='A'){
            bot-=temp2;
        }
        else if (temp1=='D'){
            if (b.front().first=='A'){
                charlie+=b.front().second;
            }
            else{
                charlie-=temp2;
            }
        }
        if (bot<=0){
            cout << "VICTORY" << '\n';
            return 0;
        }
        else if (charlie<=0){
            cout << "DEFEAT" << '\n';
            return 0;
        }
        temp1=b.front().first; temp2=b.front().second; b.pop();
        if (temp1=='A'){
            charlie-=temp2;
        }
        else if (temp1=='D'){
            if (c.front().first=='A'){
                bot+=c.front().second;
            }
            else{
                bot-=temp2;
            }
        }
        if (bot<=0){
            cout << "VICTORY" << '\n';
            return 0;
        }
        else if (charlie<=0){
            cout << "DEFEAT" << '\n';
            return 0;
        }
    }
    cout << "TIE" << '\n';
    return 0;

}