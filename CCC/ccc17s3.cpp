#include <bits/stdc++.h>

using namespace std;
int boards[4001], lengths[500000];

int main(){
    int N,a; cin >> N;
    for (int i=0;i<N;++i){
        cin >> a; boards[a]++;
    }
    int count;
    for (int temp=0;temp<4001;++temp){
        count=0;
        for (int i=0;i<=(temp-1)/2;++i){
            count+=min(boards[i],boards[temp-i]);
        }
        if (temp%2==0){
            count+=floor((boards[temp/2])/2);
        }
        lengths[count]++;
    }
    for (int i=500000;i>0;--i){
        if (lengths[i]!=0){
            cout << i << " " << lengths[i] << '\n';
            break;
        }
    }

}