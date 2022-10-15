#include <iostream>
#include <string>

using namespace std;

int digitsum(string e){
    int output=0;
    for (int i=0;i<e.length();++i){
        output+=(e[i])-'0';
    }
    return output;
}
int main(){
    int sieve[100001];
    for (int i=0;i<100001;++i){
        sieve[i]=1;
    }
    sieve[1]=0;
    sieve[0]=0;
    for (int i=2;i<316;++i){
        if (sieve[i]!=0){
            sieve[i]=1;
            int temp=i*i;
            while (temp<100001){
                sieve[temp]=0;
                temp+=i;
            }

        }
    }
    int n,uwu,sum=0,digits;
    cin >> n;
    string x;
    for (int i=0; i<n; ++i){
        cin >> x;
        uwu=stoi(x);
        if (sieve[uwu] && sieve[digitsum(x)]){
            sum++;
        }
    }
    cout << sum;
    

}