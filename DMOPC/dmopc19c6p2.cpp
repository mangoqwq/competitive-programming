#include <bits/stdc++.h>

using namespace std;
int a,b;

int uwu(int x){
    int total=0;
    int expo=x;
    while (expo<=b){
        total+=(int)b/expo;
        expo*=x;
    }
    return total;
    
}

int solve(){
    int mathishard=sqrt(b)+2;
    int count=0;
    int ans=0x3f3f3f3f;
    for (int i=2;i<=mathishard;++i){
        count=0;
        while (a%i==0){
            count++;
            a/=i;
        }
        if (count!=0){
            ans=min(ans,(int)(uwu(i)/count));
        }
        
    }
    
    return ans;
}


int main(){
    cin >> a >> b;
    cout << solve() << '\n';
}