#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int lim=100001;

ll uwu[2][lim]; //[sum of subarray][elements less than or equal to]

void update(int index, int val, int o){
    while (index<lim){
        uwu[o][index]+=val;
        index += (index)&(-index);
    }

}
ll sum(int index, int o){
    ll output=0;
    while (index>0){
        output+=uwu[o][index];
        index -= (index)&(-index);
    }
    return output;

}
int main(){
    cin.sync_with_stdio(0);
    cin.tie(0);
    int elements, operations;
    ll temp;
    cin >> elements >> operations;

    for (int i=1;i<elements+1;++i){
        cin >> temp;
        update(i,temp,0);
        update(temp,1,1);
    }
    int a,b;
    char x;
    for (int i=0;i<operations;++i){
        cin >> x;
        if (x=='C'){
            cin >> a >> b;
            //we need the original value of array[a]
            temp=sum(a,0)-sum(a-1,0);
            update(a,b-temp,0);
            update(b,1,1);
            update(temp,-1,1);
        }
        else if (x=='S'){
            cin >> a >> b;
            cout << sum(b,0) - sum(a-1,0) << '\n';
        }
        else if (x=='Q'){
            cin >> a;
            cout << sum(a,1) << '\n';
        }

    }


}