#include <bits/stdc++.h>

using namespace std;
int events[50001];
int minutes,times,naps; 

bool sleep(int mins){
    int uwu=0;
    for (int i=0;i<times+1;++i){
        uwu+=events[i]/mins;
    }
    return uwu>=naps;
}

int main(){
    cin >> minutes >> times >> naps;
    int prev=0;
    for (int i=0,a;i<times;++i){
        cin >> a;
        events[i]=a-prev;
        prev=a;
    }
    events[times]=minutes-prev;
    for (int i=0;i<times+1;++i){
        cout << events[i] << " ";
    }
    int bot=0,top=minutes,mid;
    while (bot<=top&&0){
        cout << mid << " ";
        mid=(bot+top+1)/2;
        if (sleep(mid)){
            bot=mid;
        }
        else{
            top=mid-1;
        }
    }
    cout << sleep(4) << '\n';
}