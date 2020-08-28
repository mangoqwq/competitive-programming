#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
//ofstream fout("loan.out");
//ifstream fin("loan.in");

ll debt,days,eachday;
ll check(ll x){
    ll left=debt;
    ll time=0;
    ll temp=floor(left/x);
    //cout << temp << " " << left << " " << eachday << " ";
    while (left>0){
        if (temp<=eachday){
            break;
        }
        //cout << left << ":" << temp << ":" << floor((left-((x-1)*temp))/temp) << ":" << floor((left-((x-1)*temp))/temp)*temp << " ";
        time+=floor((left-((x-1)*temp))/temp);
        left-=floor((left-((x-1)*temp))/temp)*temp;
        temp=floor(left/x);
    }
    time+=ceil((double)left/eachday);
    //cout << time << '\n';
    return time;
}

int main(){
    cin >> debt >> days >> eachday;
    ll top=1000000000000, bot=1,temp=1,result,current; //binary search for the value
    for (int i=0;i<100;++i){
        current=floor((bot+top)/2);
        //cout << current << " - " << bot << " : " << top << '\n';
        //cout << current << "-> ";
        result=check(current);
        if (result<days || (result==days && check(current-1)<days)){
            bot=current+1;
        }
        else{
            if (result>=days){
                top=current-1;
            }
            else{
                bot=current+1;
            }
        }
    }
    cout << current << '\n';
}